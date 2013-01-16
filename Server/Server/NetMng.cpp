//
//  NetMng.cpp
//  server
//
//  Created by xiangyu on 12-12-21.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#include "NetMng.h"
#include "Tools.h"

CSNetMng* CSNetMng::Instance(void)
{
    static CSNetMng* inst= 0;
    if(!inst)
    {
        inst=new CSNetMng;
    }
    return inst;
}

void CSSessionManager::run(void)
{
    NetMessage * pRecvMsg;
    pRecvMsg = (NetMessage *)malloc(NetMessage::Max_Msg_Size);
    boost::posix_time::ptime m_thisSecond;
    
    for (;;)
    {
        ptime now = boost::posix_time::microsec_clock::universal_time();
        time_duration diff = now-m_thisSecond;
        unsigned int diffMillisecond = diff.total_milliseconds();
        bool isPrint = diffMillisecond > 1000;
        if (isPrint)
        {
            m_thisSecond=now;
        }
        boost::this_thread::sleep(boost::posix_time::millisec(1));
        boost::recursive_mutex::scoped_lock l(mutex);
        for (unsigned int i=0;i<m_sessions.size();)
        {
            TSSession* s = m_sessions[i];
            if (s->isclose())
            {
                //					closeCount++;
                if (s->canclose())
                {
                    if (on_session_cleanup(s))
                    {
                        m_sessions.erase(m_sessions.begin()+i);
                    }
                }
                else
                {
                    ++i;
                }
                continue;
            }
            s->update();
            
            while(s->m_conn->GetMsg(pRecvMsg))
            {
                m_netMsgHelper.HandleAccMsg(s->m_pAccount,pRecvMsg);
            }
            i++;
        }

    }
    free(pRecvMsg);
}

void CSNetMng::Start(int port,int threadCount,int sendLimit)
{
    m_netMsgHelper.InitAllCheck(CGameServer::Instance());
    printf("Start Server On %d. Thread:%d ,SpeedLimit:%g\r\n",port,threadCount,sendLimit/1024.0f);
    m_sendRateKeeped=sendLimit;
    
    acceptor_ = new tcp::acceptor(io_service_,tcp::endpoint(tcp::v4(), port));
    start_accept();
    
    
    for (unsigned int i=0;i<threadCount;i++)
    {
        boost::thread* t = new boost::thread(boost::bind(&boost::asio::io_service::run, &io_service_));
        ts.push_back(t);
    }
    ts.push_back(new boost::thread(boost::bind(&CSNetMng::run, this)));
}

void CSNetMng::start_accept()
{
    TSSession* new_session = new TSSession(io_service_);
    CGameAccount* pAccount = new CGameAccount(new_session->m_conn);
    pAccount->GetPlayer()->OnPush(CGameServer::Instance());
    new_session->m_pAccount = pAccount;
    acceptor_->async_accept(new_session->socket(),
                            boost::bind(&CSNetMng::handle_accept, this, new_session,
                                        boost::asio::placeholders::error));
}

void CSNetMng::handle_accept(TSSession* new_session,
                   const boost::system::error_code& error)
{
    if (!error)
    {
        new_session->start();
        boost::recursive_mutex::scoped_lock l(mutex);
        m_sessions.push_back(new_session);
    }
    else
    {
        delete new_session;
    }
    
    start_accept();
}
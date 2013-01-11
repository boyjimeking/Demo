//
//  NetMng.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Server__NetMng__
#define __Server__NetMng__

#define __CLIENT_MSG_DEFINITION__

#include "../../Demo/Comm/CommDef.h"
#include "../../Demo/Comm/NetMsgHelper.h"
#include "GameServer.h"
#include "GameAccount.h"
#include "../../Demo/Comm/CSession.h"

typedef Net::CSession<CGameAccount> TSSession;

class CSSessionManager
{
public:
    typedef Net::CNetMsgHelper<CGameServer, CGameAccount> CSNetMsgHelper;
    typedef std::vector<TSSession*> CSSessionMap;
	unsigned int	m_sendRateKeeped;
	boost::recursive_mutex mutex;
    CSSessionMap m_sessions;
	unsigned int m_msgID;
    
	CSSessionManager(void):
    m_netMsgHelper()
    {
		m_sendRateKeeped=20*1024;
		m_msgID=0;
	}
    
	virtual bool on_session_cleanup(TSSession* s){
        delete s->m_pAccount;
		delete s;
		return true;
	}
    
	void run(void)
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
//			float inkb = 0;
//			float outkb = 0;
//			float recvRatekb = 0;
//			float sendRatekb = 0;
//			int closeCount=0;
			//boost::this_thread::yield();
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
//				if (isPrint)
//				{
//					inkb += s->m_conn->m_inQueue->blockcount();
//					outkb += s->m_conn->m_outQueue->blockcount();
//					recvRatekb += s->m_conn->m_recvRate.RefreshRate()/1024.0f;
//					sendRatekb += s->m_conn->m_sendRate.RefreshRate()/1024.0f;
//				}
				s->update();
                
				while(s->m_conn->GetMsg(pRecvMsg))
				{
					m_netMsgHelper.HandleAccMsg(s->m_pAccount,pRecvMsg);
				}
				i++;
			}
//			if(isPrint)
//			{
//				int connCount = m_sessions.size();
//				int blockCount = TSSession::ms_pool.BlockCount;
//				printf("S:%d-%d:%g/%g,Recv:%g kb/s,Send:%g kb.Mem:%d*4mb/s\r\n"
//                       ,connCount,closeCount
//                       ,inkb,outkb
//                       ,recvRatekb
//                       ,sendRatekb,blockCount);
//			}
		}
		//boost::thread::sleep(boost::system_time(boost::posix_time::ptime()));
		free(pRecvMsg);
	}

    
protected:
    CSNetMsgHelper m_netMsgHelper;
};

class CSNetMng
:public CSSessionManager
{
public:
    static CSNetMng* Instance(void);
	CSNetMng()
	{
 		this->m_sendRateKeeped=220*1024;
	}
	void Start(int port,int threadCount,int sendLimit)
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


private:
	void start_accept()
	{
		TSSession* new_session = new TSSession(io_service_);
        new_session->m_pAccount = new CGameAccount(new_session->m_conn);
		acceptor_->async_accept(new_session->socket(),
                                boost::bind(&CSNetMng::handle_accept, this, new_session,
                                            boost::asio::placeholders::error));
	}
    
	void handle_accept(TSSession* new_session,
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
    
	boost::asio::io_service io_service_;
	tcp::acceptor* acceptor_;
    std::vector<boost::thread*> ts;
    
    
};
#endif
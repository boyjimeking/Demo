//
//  ClNetMng.h
//  client
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Demo__ClNetMng__
#define __Demo__ClNetMng__

#define __SERVER_MSG_DEFINITION__
#include "../Comm/CSession.h"
#include "../Comm/NetMsgHelper.h"
#include "CClient.h"
#include "CGameActor.h"

typedef Net::CSession<CGameActor> CClSession;
typedef Net::CNetMsgHelper<CClient, CGameActor> CClNetMsgHelper;

class CClSessionManager
{
public:
	unsigned int	m_sendRateKeeped;
	boost::recursive_mutex mutex;
	CClSession* m_pSession;
	unsigned int m_msgID;
public:
	CClSessionManager(void):
    m_pNetMsgHelper(0),
    m_pSession(0)
	{
		m_sendRateKeeped=20*1024;
		m_msgID=0;
        m_pRecvMsg = (NetMessage *)malloc(NetMessage::Max_Msg_Size);
	}
	virtual bool CleanSession(){
		delete m_pSession;
		m_pSession = NULL;
        free(m_pRecvMsg);
		return true;
	}
	void run(void)
	{
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
			if(!m_pSession)
				continue;
			boost::recursive_mutex::scoped_lock l(mutex);
			if (m_pSession->isclose())
			{
//				closeCount++;
				if (m_pSession->canclose())
				{
					if (CleanSession())
					{
						continue;
					}
				}
			}
//			if (isPrint)
//			{
//				inkb += m_pSession->m_conn->m_inQueue->blockcount();
//				outkb += m_pSession->m_conn->m_outQueue->blockcount();
//				recvRatekb += m_pSession->m_conn->m_recvRate.RefreshRate()/1024.0f;
//				sendRatekb += m_pSession->m_conn->m_sendRate.RefreshRate()/1024.0f;
//			}
			m_pSession->update();
            
//			if(isPrint)
//			{
//				int connCount = 1;
//				int blockCount = CClSession::ms_pool.BlockCount;
//				printf("C:%d-%d:%g/%g,Recv:%g kb/s,Send:%g kb.Mem:%d*4mb/s\r\n"
//                       ,connCount,closeCount
//                       ,inkb,outkb
//                       ,recvRatekb
//                       ,sendRatekb,blockCount);
//			}
		}
	}
    void HandleMsgs(void)
    {
        if(!m_pSession)
            return;
		while(m_pSession->m_conn->GetMsg(m_pRecvMsg)){
            m_pNetMsgHelper->HandleMsg(m_pRecvMsg);
        }
    }

protected:
    CClNetMsgHelper* m_pNetMsgHelper;
    NetMessage *m_pRecvMsg;
};


class CClNetMng
:public CClSessionManager{
public:
    CClNetMng():
    m_msgID(0),
    m_pClient(0),
    m_pMsgHelper(0)
    {
        resolver = new tcp::resolver(io_service);
    }
    ~CClNetMng()
    {
        delete _ins;
    }
    
    static CClNetMng * Instance(void);
    
    void Init()
    {
        if(m_pClient == NULL)
            m_pClient = new CClient();
        if(m_pMsgHelper == NULL)
            m_pMsgHelper = new CClNetMsgHelper();
        m_pMsgHelper->InitAllCheck(m_pClient);
        _ins->SetNetMsgHelper(m_pMsgHelper);
        _ins->Start("192.168.2.1","20051");
    }

    void SendMsgToServer(NetMessage& msg)
    {
        assert(m_pSession);
        msg.SerialNumber = m_msgID;
        m_msgID++;
        m_pSession->m_conn->SendMsg(&msg);
    }
    
    void Start(const char* host,const char* port)
    {
        printf("Start Client...[%s:%s]\r\n",host,port);
        query = new tcp::resolver::query(host,port);
        iterator = resolver->resolve(*query);
        
        Connect();
        boost::thread* t = new boost::thread(boost::bind(&boost::asio::io_service::run, &io_service));
        ts.push_back(t);
        ts.push_back(new boost::thread(boost::bind(&CClNetMng::run, this)));
    };
    virtual bool CleanSession(){
        delete m_pSession;
        m_pSession = NULL;
        return true;
    }
    void Connect()
    {
        CClSession* c=new CClSession(io_service);
        boost::asio::async_connect(c->socket(), iterator,
                                   boost::bind(&CClNetMng::on_connected, this,c,boost::asio::placeholders::error));
    }
    void on_connected(CClSession* c,const boost::system::error_code& error)
    {
        if (error)
        {
            printf("connect error .reconnect....\r\n");
            boost::asio::async_connect(c->socket(), iterator,
                                       boost::bind(&CClNetMng::on_connected, this,c,boost::asio::placeholders::error));
        }
        else
        {
            m_pSession = c;
            m_pSession->start();
        }
    }
    bool IsConnected()
    {
        return m_pSession && m_pSession->IsConnected();
    }
    void SetNetMsgHelper(CClNetMsgHelper* m_pMsgHelper){ m_pNetMsgHelper = m_pMsgHelper;}
    
    int m_msgID;
private:
    
	boost::asio::io_service io_service;
	tcp::resolver* resolver;
	tcp::resolver::query* query;
	tcp::resolver::iterator iterator;
	std::vector<boost::thread*> ts;
    static CClNetMng* _ins;
    CClient *m_pClient;
    CClNetMsgHelper* m_pMsgHelper;
};

#endif //__Demo__ClNetMng__
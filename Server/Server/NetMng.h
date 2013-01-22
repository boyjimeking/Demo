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
    
	void run(void);

    
protected:
    CSNetMsgHelper m_netMsgHelper;
};

class CSNetMng
:public CSSessionManager
{
public:

	CSNetMng():
    m_pGameServer(0)
	{
 		this->m_sendRateKeeped=220*1024;
	}
	void Start(int port,int threadCount,int sendLimit);
    void SetGameServer(CGameServer* pGameServer) { m_pGameServer = pGameServer;}
    
private:
	void start_accept();
	void handle_accept(TSSession* new_session,
                       const boost::system::error_code& error);
    
	boost::asio::io_service io_service_;
	tcp::acceptor* acceptor_;
    std::vector<boost::thread*> ts;
    CGameServer* m_pGameServer;
};
#endif
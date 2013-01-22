//
//  NetMsgHelper.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Demo__NetMsgHelper__H__
#define __Demo__NetMsgHelper__H__

//#include "stdafx.h"
#include "NetMessage.h"
#include "NetMsgHelper.h"
#include "NetMsgConfig.h"
#include "CSession.h"

//!Front转发消息规则
enum ENSETunnelingFlag
{
	enME_Tunneling_None=0,
	enME_Tunneling_ServerID=1,
	enME_Tunneling_Center=2,
	enME_Tunneling_Chat=3,
};

namespace Net
{
    //!网络消息帮助函数
    template<typename TMsgHandler, typename TAccount, typename TNetMessage=NetMessage>
    class CNetMsgHelper
    {
    public:
#ifdef __SERVER_MSG_DEFINITION__
        typedef bool (TMsgHandler::*_MSG_PROCESS_)(TNetMessage*);
#endif
#ifdef __CLIENT_MSG_DEFINITION__
        typedef bool (TMsgHandler::*_MSG_PROCESS_)(TAccount*, TNetMessage*);
#endif
        CNetMsgHelper(void);
        ~CNetMsgHelper(void);
        void InitAllCheck(TMsgHandler* pHandler);
        //!产生消息安全性检查.
        void GenerateSafeCheck(void);
        //!产生客户端可否发送标志.
        void GenerateClientSendFlag(void);
        //!产生消息转发规则
        void GenerateTunneling(void);
        //!检查消息id是否被重复使用
        bool CheckMsgIsRedefine(void);
        //!对于客户端可以发送的消息进行特别检查
        void CheckClientSendMsgDefine(void);
        //!检查消息是否安全.
        bool CheckMsgIsSafe(void* event);
        //!检查客户端是否可以发送
        bool CanClientSend(void* event);
        //!检查消息转发标志
        ENSETunnelingFlag GetSETunneling(void* event);
        //!获得消息包名字字符串
        //static const char* GetMsgName(int msgid);
        void GenerateMsgProcessList(void);
#ifdef __SERVER_MSG_DEFINITION__
        bool HandleMsg(TNetMessage* pMsg);
#endif
#ifdef __CLIENT_MSG_DEFINITION__
        bool HandleAccMsg(TAccount* pAccount, TNetMessage* pMsg);
#endif
        
        ENSETunnelingFlag m_seTunnelingFlag[_Max_CS_Msg_ID_];
        typedef bool (*CheckFunc) (void* event);
        CheckFunc m_safeCheckFuncList[_Max_CS_Msg_ID_];
        bool m_canClientSend[_Max_CS_Msg_ID_];
    private:
        TMsgHandler* m_pHandler;
        _MSG_PROCESS_ m_msgProcessFuncList[_Max_CS_Msg_ID_];
        
    };
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::CNetMsgHelper(void):
    m_pHandler(0)
    {
        
    }
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::~CNetMsgHelper(void)
    {
        
    }
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    void CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::InitAllCheck(TMsgHandler* pHandler)
    {
        //
        GenerateMsgProcessList();
        //!产生消息安全性检查.
        GenerateSafeCheck();
        //!产生客户端可否发送标志.
        GenerateClientSendFlag();
        //!产生消息转发规则
        GenerateTunneling();
        //!检查消息id是否被重复使用
        CheckMsgIsRedefine();
        //!对于客户端可以发送的消息进行特别检查
        CheckClientSendMsgDefine();
        m_pHandler = pHandler;
    }
    
    
#ifdef __SERVER_MSG_DEFINITION__
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    bool CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::HandleMsg(TNetMessage* pMsg)
    {
        assert(m_pHandler);
        _MSG_PROCESS_ f = m_msgProcessFuncList[pMsg->GetType()];
        if(!f)
            return false;
        return (m_pHandler->*f)(pMsg);
    }
#endif
    
#ifdef __CLIENT_MSG_DEFINITION__
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    bool CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::HandleAccMsg(TAccount* pAccount, TNetMessage* pMsg)
    {
        assert(m_pHandler);
        _MSG_PROCESS_ f = m_msgProcessFuncList[pMsg->GetType()];
        if(!f)
            return false;
        return (m_pHandler->*f)(pAccount, pMsg);
    }
#endif
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    void CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::GenerateMsgProcessList(void)
    {
        memset(m_msgProcessFuncList,0,sizeof(m_msgProcessFuncList));
#define _SE_En_Decl_V_(EName,EID,CheckType,ME_Nop1,ME_Nop2) m_msgProcessFuncList[EID]=&TMsgHandler::EName;
#include "NetCommand.h"
#define __SERVER_MSG_DEFINITION__
#define __CLIENT_MSG_DEFINITION__
    }
    
    //////////////////////////////////////////////////////////////////////////
    //安全性检查
    
    
    template<class T>
    struct SE_Auto_Struct_Check
    {
        static bool _SafeCheck(void* event)
        {
            T* self = (T*)event;
            return self->GetLength() == sizeof(T);
        }
    };
    
    inline bool SE_NoneSafeCheck(void* event)
    {
        return true;
    }
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    void CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::GenerateSafeCheck(void)
    {
        memset(m_safeCheckFuncList,0,sizeof(m_safeCheckFuncList));
#define ME_Check_None(EID,EName) m_safeCheckFuncList[EID]=&SE_NoneSafeCheck;
        //!调用自身的函数(static bool _SafeCheck(XXX* event) )进行安全性检查
#define ME_Check_Self(EID,EName) m_safeCheckFuncList[EID]=&EName::_SafeCheck;
        //!只进行长度检查,并且长度必须=结构体长度
#define ME_Check_Stru(EID,EName) m_safeCheckFuncList[EID]=&SE_Auto_Struct_Check<TMsg##EName>::_SafeCheck;
#define _SE_En_Decl_V_(EName,EID,CheckType,ME_Nop1,ME_Nop2) CheckType(EID,EName)
#include "NetCommand.h"
    }
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    bool CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::CheckMsgIsSafe(void* event)
    {
        NetMessage* e=(NetMessage*)event;
        return (e->GetType() >= 0 && e->GetType() < _Max_CS_Msg_ID_)&&(*m_safeCheckFuncList[e->GetType()])(event);
    }
    //////////////////////////////////////////////////////////////////////////
    //客户端可否发送
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    void CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::GenerateClientSendFlag(void)
    {
        memset(m_canClientSend,0,sizeof(m_canClientSend));
#define ME_NS_Client true
#define ME_NS_Server false
        
#define _SE_En_Decl_V_(EName,EID,ME_Nop1,CanSendFlag,ME_Nop2) m_canClientSend[EID] = CanSendFlag;
#include "NetCommand.h"
    }
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    bool CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::CanClientSend(void* event)
    {
        NetMessage* e=(NetMessage*)event;
        return (e->GetType() >= 0 && e->GetType() < _Max_CS_Msg_ID_)&&m_canClientSend[e->GetType()];
    }
    //////////////////////////////////////////////////////////////////////////
    //FE转发规则
    
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    void CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::GenerateTunneling(void)
    {
        memset(m_seTunnelingFlag,enME_Tunneling_None,sizeof(m_seTunnelingFlag));
#define ME_Tunneling_Chat enME_Tunneling_Chat
#define ME_Tunneling_Cent enME_Tunneling_Center
#define ME_Tunneling_Serv enME_Tunneling_ServerID
#define _SE_En_Decl_V_(EName,EID,ME_Nop1,ME_Nop2,Tunneling) m_seTunnelingFlag[EID] = Tunneling;
        
#include "NetCommand.h"
    }
    
    template<typename TMsgHandler, typename TAccount, typename TNetMessage>
    ENSETunnelingFlag CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::GetSETunneling(void* event)
    {
        NetMessage* e=(NetMessage*)event;
        return (e->GetType() >= 0 && e->GetType() < _Max_CS_Msg_ID_)?m_seTunnelingFlag[e->GetType()] : enME_Tunneling_None;
    }
    
    struct _client_msg_must_check
    {
        
    };
    
    struct _server_msg_may_check
    {
        _server_msg_may_check& operator=(const _server_msg_may_check& rhs)
        {
            return *this;
        }
        _server_msg_may_check&operator=(const _client_msg_must_check& rhs)
        {
            return *this;
        }
        _server_msg_may_check& operator=(const int& rhs)
        {
            return *this;
        }
        };
        
        template<typename TMsgHandler, typename TAccount, typename TNetMessage>
        bool CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::CheckMsgIsRedefine(void)
        {
            int i=rand();
#define _SE_En_Decl_V_(EName,EID,ME_Nop1,ME_Nop2,ME_Nop3) case EID:break;
            switch(i)
            {
#include "NetCommand.h"
                default:
                    break;
            }
            
            return true;
        }
        
        template<typename TMsgHandler, typename TAccount, typename TNetMessage>
        void CNetMsgHelper<TMsgHandler, TAccount, TNetMessage>::CheckClientSendMsgDefine(void)
        {
            //允许客户端发送的(ME_NS_Client),不能使用ME_Check_None作为安全检查
            int iv1 = 0;
            int iv2 = 0;
            _client_msg_must_check mustcheck1;
            _client_msg_must_check mustcheck2;
            _server_msg_may_check maycheck;
#define ME_NS_Client mustcheck1
#define ME_NS_Server maycheck
            
#define ME_Check_None iv2
#define ME_Check_Self mustcheck2
#define ME_Check_Stru mustcheck2
#define _SE_En_Decl_V_(EName,EID,Check,IsClient,Tunneling) (IsClient=Check);
            
#include "NetCommand.h"
            
        }
        
        //const char* CNetMsgHelper::GetMsgName(int msgid)
        //{
        //	extern char g_msg_named[_Max_CS_Msg_ID_][64];
        //	if (msgid >= 0 && msgid < _Max_CS_Msg_ID_)
        //	{
        //		return g_msg_named[msgid];
        //	}
        //	static const char* notExist = "NotExist";
        //	return notExist;
        //}
}

#endif //__Demo__NetMsgHelper__H__
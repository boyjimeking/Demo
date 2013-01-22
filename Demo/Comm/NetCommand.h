//
//  NetCommand.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

////////////////////////////////////////////////////////////////////////////////////
//安全性检查规则
////////////////////////////////////////////////////////////////////////////////////
//!不进行安全性检查,可能在处理时,独立进行安全性检查
#ifndef ME_Check_None
#	define ME_Check_None
#endif
//!调用自身的函数(static bool _SafeCheck(XXX* event) )进行安全性检查
#ifndef ME_Check_Self
#	define ME_Check_Self
#endif
//!只进行长度检查,并且长度必须=结构体长度
#ifndef ME_Check_Stru
#	define ME_Check_Stru
#endif
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//客户端是否可以发送规则
////////////////////////////////////////////////////////////////////////////////////
//!允许客户端发送移动到下面定义,以免客户端发送过来的消息位置放错.
//#ifndef ME_NS_Client
//#	define ME_NS_Client
//#endif
//!不允许客户端发送,只允许服务器端发送,FE一旦收到此类消息,即丢弃
#ifndef ME_NS_Server
#	define ME_NS_Server
#endif
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
//FE转发规则
////////////////////////////////////////////////////////////////////////////////////
//!FE自动将此消息转发给chat
#ifndef ME_Tunneling_Chat
#	define ME_Tunneling_Chat
#endif
//!FE自动将此消息转发给center
#ifndef ME_Tunneling_Cent
#	define ME_Tunneling_Cent
#endif
//!FE依据当前这个客户端的上行服务器id进行此消息的转发，即发送给Zone
#ifndef ME_Tunneling_Serv
#	define ME_Tunneling_Serv
#endif
//!FE自己处理，不转发，gtw
#ifndef ME_Tunneling_Self
#	define ME_Tunneling_Self ME_Tunneling_Serv
#endif
//!FE将消息转发给客户端
#ifndef ME_Tunneling_Client
#	define ME_Tunneling_Client ME_Tunneling_Serv
#endif
////////////////////////////////////////////////////////////////////////////////////
#ifndef _SE_En_Decl_V_
#	define _SE_En_Decl_V_
#endif

//#pragma endregion
#ifdef __SERVER_MSG_DEFINITION__
#include "ServerMsgDef.h"
#endif

#ifdef __CLIENT_MSG_DEFINITION__
#include "ClientMsgDef.h"
#endif

#undef _SE_En_Decl_V_
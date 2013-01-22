//
//  ServerMsgDef.h
//  client
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#define _SERVER_MSG_BASE_  5000
#define _S_SE_En_Decl_V_(className,value,check1,check2,check3) _SE_En_Decl_V_(className,value+_SERVER_MSG_BASE_,check1,check2,check3)

//////////////////////////////////////////////////////////////////////////
//服务器端发出的消息 
_S_SE_En_Decl_V_(InitScene_S2C, 1, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(InitPlayer_S2C, 2, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(InitNPC_S2C, 3, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(ChangeActorEquip_S2C, 4, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(SycActor_S2C, 5, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(MoveTo_S2C, 6, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(AttackTarget_S2C, 7, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(Dead_S2C, 8, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
_S_SE_En_Decl_V_(BeAttack_S2C, 9, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
//
//_S_SE_En_Decl_V_(, 10, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
//_S_SE_En_Decl_V_(, 11, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
//_S_SE_En_Decl_V_(, 12, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
//_S_SE_En_Decl_V_(, 13, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
//_S_SE_En_Decl_V_(, 14, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)
//_S_SE_En_Decl_V_(, 15, ME_Check_None, ME_NS_Server, ME_Tunneling_Serv)

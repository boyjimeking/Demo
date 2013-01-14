//
//  Client.cpp
//  client
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

//#include "stdafx.h"

#include "CClient.h"
#include "WorldManager.h"
#include "ClNetMng.h"
#include "../../Comm/CommDef.h"
#include "../Actors/ActorProp.h"
#include "../Actors/ActorsControl.h"
#include "../CSProtocol/ActorBattleInfo.h"
#include "support/CCPointExtension.h"


CClient::CClient():
m_bIsLogined(false)
{
    
}

bool CClient::Login(const char*username, const char*password)
{
    TMsgLogin msg;
    assert(strlen(username) <128 && strlen(password) < 128);
    strcpy(msg.m_userName, username);
    strcpy(msg.m_password, password);
    while(!CClNetMng::Instance()->IsConnected())
    {
        usleep(100);
    }
    SendMsg(msg);

	return true;
}

bool CClient::InitScene_S2C(NetMessage* pMsg)
{
    MSG_PTR_CVT(p, TMsgInitScene_S2C, pMsg);
	printf("InitScene_S2C::%d, %s\n",pMsg->GetType(),p->m_sceneName);

    Game::WorldManager::Instance()->InitSceneByFile(p->m_sceneName);
    m_bIsLogined = true;
    
	return true;
}

bool CClient::InitPlayer_S2C(NetMessage* pMsg)
{
    MSG_PTR_CVT(p, TMsgInitPlayer_S2C, pMsg);
	printf("InitPlayer_S2C::%d,id:%d\n",pMsg->GetType(), p->m_actorID);

    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->GetMainActor();
    if (NULL == actor)
    {
        actor = Game::WorldManager::Instance()->GetActorsControl()->CreateActor(ENActorType::enMain, p->m_actorID, p->m_x, p->m_y);
        actor->GetBattleInfo()->Read(p->m_battleInfo);
        Game::WorldManager::Instance()->GetActorsControl()->SetMainActorId(p->m_actorID);
    }
    else
    {
        //error
    }
    
	return true;
}

bool CClient::InitNPC_S2C(NetMessage* pMsg)
{
    MSG_PTR_CVT(p, TMsgInitNPC_S2C, pMsg);
    printf("InitNPC_S2C::%d,id:%d\n",pMsg->GetType(), p->m_actorID);
    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    if (NULL == actor)
    {
        actor = Game::WorldManager::Instance()->GetActorsControl()->CreateActor(ENActorType::enMonster, p->m_actorID, p->m_x, p->m_y);
        actor->GetBattleInfo()->Read(p->m_battleInfo);
    }
    else
    {
        //error
    }
    
    return true;
}

bool CClient::ChangeActorEquip_S2C(NetMessage* pMsg)
{
    MSG_PTR_CVT(p, TMsgChangeActorEquip_S2C, pMsg);
 	printf("ChangeActorEquip_S2C::%d\n",pMsg->GetType());
    
    //CSChangeActorEquip_S2C *innerMessage = reinterpret_cast<CSChangeActorEquip_S2C*>(message);
    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    if (NULL != actor)
    {
        actor->ChangeEquip((ENEquipType::Decl)p->m_equipType, p->m_equipName);
    }
    
	return true;
}

bool CClient::SycActor_S2C(NetMessage* pMsg)
{
 	printf("SycActor_S2C::%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgSycActor_S2C, pMsg);

    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    if (NULL == actor)
    {
        Game::WorldManager::Instance()->GetActorsControl()->CreateActor(ENActorType::enMonster, p->m_actorID, p->m_x, p->m_y);
    }
    else
    {
        actor->SetPosition(ccp(p->m_x, p->m_y));
    }
    return true;
}

bool CClient::MoveTo_S2C(NetMessage* pMsg)
{
    printf("MoveTo_S2C::%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgMoveTo_S2C, pMsg);

    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    if (NULL == actor)
    {
        return false;
    }
    actor->MoveTo(ccp(p->m_x, p->m_y));

    return true;
}

bool CClient::AttackTarget_S2C(NetMessage* pMsg)
{
    printf("AttackTarget_S2C::%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgAttackTarget_S2C, pMsg);
    
    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    Game::ActorProp *target = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_targetID);
    if (NULL == actor || NULL == target)
    {
        return false;
    }
    actor->StartAttack(target);
    
    return true;
}

bool CClient::Dead_S2C(NetMessage* pMsg)
{
    printf("Dead_S2C::%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgDead_S2C, pMsg);
    
    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    if (NULL == actor)
    {
        return false;
    }
    actor->Dead();
    
    return true;
}

bool CClient::BeAttack_S2C(NetMessage* pMsg)
{
    printf("BeAttack_S2C::%d\n",pMsg->GetType());
    MSG_PTR_CVT(p, TMsgBeAttack_S2C, pMsg);
    
    Game::ActorProp *actor = Game::WorldManager::Instance()->GetActorsControl()->LookupActor(p->m_actorID);
    if (NULL == actor)
    {
        return false;
    }
    actor->BeAttacked(p->m_hpChanged);

    return true;
}

void CClient::Attack( int targetID )
{
    TMsgAttackTarget_C2S msg;
    msg.m_actorID = Game::WorldManager::Instance()->GetActorsControl()->GetMainActor()->GetID();
    msg.m_targetID = targetID;
    SendMsg(msg);
}

void CClient::SendMsg(NetMessage& msg) { CClNetMng::Instance()->SendMsgToServer(msg);}



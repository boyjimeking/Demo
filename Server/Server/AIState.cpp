//
//  AIState.cpp
//  Server
//
//  Created by xiangyu on 13-1-9.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "AIState.h"
#include "../../Demo/Comm/NetMessage.h"
#include "GameServer.h"
#include "Tools.h"

AIState::AIState(void)
{
    
}

AIState::~AIState(void)
{
    
}

void AIPatrol::Tick( CNpc& npc, u32 dt )
{
    float changedTime = 5.0f;
    if (m_totalTime < 0.000001f)
    {
        ChangeTarget(npc);
        m_totalTime = 1;
    }
    m_totalTime += dt;
    if (m_totalTime > changedTime)
    {
        m_totalTime = rand() / RAND_MAX * changedTime;
    }
}

void AIPatrol::OnEnter( CNpc& npc )
{
    m_totalTime = 0.0f;
}

void AIPatrol::OnExit( CNpc& npc )
{
    
}
void AIPatrol::ChangeTarget(CNpc& npc)
{
    TMsgMoveTo_S2C message;
    message.m_actorID = npc.GetID();
    message.m_x = CGameServer::RandX();
    message.m_y = CGameServer::RandY();
    npc.BoardcastMsg(message);
}

void AIAttack::Tick( CNpc& npc, u32 dt )
{
    m_nextAttack -= dt;
    if (m_nextAttack <= 0.0f)
    {
        SendAttack(npc);
        m_nextAttack = 5.0f;
    }
}

void AIAttack::OnEnter( CNpc& npc )
{
    m_nextAttack = 0.0f;
}

void AIAttack::OnExit( CNpc& npc )
{
    
}

void AIAttack::SendAttack( CNpc& npc )
{
    TMsgAttackTarget_S2C message;
    message.m_actorID = npc.GetID();
    message.m_targetID = npc.GetTarget();
    npc.BoardcastMsg(message);
}


void AIDead::OnEnter( CNpc& npc )
{
    TMsgDead_S2C message;
    message.m_actorID = npc.GetID();
    npc.BoardcastMsg(message);
}

void AIDead::OnExit( CNpc& npc )
{
    
}

void AIDead::Tick( CNpc& npc, u32 dt )
{
    
}
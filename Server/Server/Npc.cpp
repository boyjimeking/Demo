//
//  Npc.cpp
//  Server
//
//  Created by xiangyu on 13-1-7.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include <assert.h>
#include "Npc.h"
#include "../../Demo/Comm/NetMessage.h"
#include "AIControl.h"
#include "Tools.h"

u32 CNpc::m_nIdGenerator = 1;
CNpc::TNpcMap CNpc::m_npcMap;

CNpc::CNpc(u32 id):IUnit(id)
{
    ++m_nIdGenerator;
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
}

CNpc::~CNpc()
{
    TNpcMap::iterator it = m_npcMap.find(m_nId);
    assert(it != m_npcMap.end());
    delete it->second;
    m_npcMap.erase(it);
}

CNpc* CNpc::CreateObj(u32 id)
{
    if(m_npcMap.find(id) != m_npcMap.end())
    {
        return 0;
    }
    
    CNpc* p = new CNpc(id);
    if(!p->Init())
        return 0;
    m_npcMap[id] = p;
    
    return p;
}

bool CNpc::Init(void)
{
    //
    m_battleInfo.m_HP = 5;
    m_battleInfo.m_maxHP = 5;
    m_battleInfo.m_isAlive = true;
    m_observers.insert(m_nId);
    
    return true;
}

void CNpc::SycInfo( void )
{
    TMsgInitNPC_S2C msg;
    msg.m_actorID = GetID();
    msg.m_npcStaticID = 0;
    msg.m_x = GetX();
    msg.m_y = GetY();
    msg.m_battleInfo.Set(m_battleInfo);
    BoardcastMsg(msg);
}


void CNpc::UpdateAll(u32 elps)
{
    for(TNpcMap::iterator it = m_npcMap.begin(); it != m_npcMap.end(); ++it)
    {
        it->second->Update(elps);
    }
}

void CNpc::Update(u32 elps)
{
    m_control->Tick(*this, elps);
}

CNpc* CNpc::FindNpc(u32 id)
{
    TNpcMap::iterator it = m_npcMap.find(id);
    if(it == m_npcMap.end())
    {
        return NULL;
    }
    
    return it->second;
}

void CNpc::BeAttacked( int targetID )
{
    IUnit::BeAttacked(targetID);
    if (m_battleInfo.m_isAlive)
    {
        SetTarget(targetID);
        GetControl()->ChangeState(*this, ENNPCAIState::enAttack);
    }
}

void CNpc::Dead( void )
{
    m_battleInfo.m_isAlive = false;
    GetControl()->ChangeState(*this, ENNPCAIState::enDead);
}

void CNpc::InitAll()
{
    for (int index = 0; index < 50; ++index)
    {
        CNpc* p = CNpc::CreateObj(CNpc::m_nIdGenerator);
        p->SetX(21.8f);
        p->SetY(10.9f);
    }
}
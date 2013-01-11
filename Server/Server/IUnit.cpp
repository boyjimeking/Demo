//
//  IUnit.cpp
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "IUnit.h"
#include "Player.h"
#include "Tools.h"

IUnit::TUnitMap IUnit::m_unitMap;

IUnit::IUnit(u32 id)
{
    m_nId = id;
    m_unitMap[id] = this;
    dprint(Lg_Debug,"initialize a unit:%d\n",m_nId);
}

IUnit::~IUnit()
{
    m_observers.erase(m_nId);
    m_unitMap.erase(m_nId);
}

void IUnit::SycPosition(void)
{
    TMsgSycActor_S2C message;
    message.m_actorID = GetID();
    message.m_x = GetX();
    message.m_y = GetY();
    BoardcastMsg(message);
}

void IUnit::BoardcastMsg(NetMessage &msg, u32 ownerid)
{
    for(TObserversSet::iterator it = m_observers.begin(); it != m_observers.end(); ++it)
    {
        CPlayer* player = CPlayer::FindPlayer(*it);
        if(player && ownerid != player->m_nId)
        {
            player->SendToClient(msg);
        }
    }
}

void IUnit::Attack( int targetID )
{
    
}

void IUnit::SycBattleInfo( void )
{
    
}

void IUnit::SycInfo( void )
{
    
}

void IUnit::Dead( void )
{

}

void IUnit::BeAttacked( int targetID )
{
    m_battleInfo.m_HP--;
    TMsgBeAttack_S2C message;
    message.m_actorID = GetID();
    message.m_hpChanged = -1;
    BoardcastMsg(message);
    
    if (m_battleInfo.m_HP <= 0)
    {
        Dead();
    }
}

IUnit* IUnit::FindUnit(u32 id)
{
    if(id == INVALID_ID)
        return 0;
    
    TUnitMap::iterator it = m_unitMap.find(id);
    if(it == m_unitMap.end())
    {
        return 0;
    }

    return it->second;
}



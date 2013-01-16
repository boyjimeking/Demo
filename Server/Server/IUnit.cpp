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
#include "ILayer.h"


IUnit::IUnit()
{

}

IUnit::~IUnit()
{
    m_observers.erase(GetID());
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
        IObject* obj = GetLayer()->LookupObject(*it);
        OBJ_PTR_CVT(unit, IUnit, obj);
        if(unit->IsPlayer())
        {
            OBJ_PTR_CVT(player, CPlayer, unit);
            if(ownerid != player->GetID())
            {
                player->SendToClient(msg);
            }
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



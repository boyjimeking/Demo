//
//  AIState.h
//  Server
//
//  Created by xiangyu on 13-1-9.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__AIState__
#define __Server__AIState__

#include "Npc.h"

class AIState
{
public:
    AIState(void);
    virtual ~AIState(void);
    
    virtual void Tick(CNpc& npc, u32 dt){}
    virtual void OnEnter(CNpc& npc){}
    virtual void OnExit(CNpc& npc){}
protected:
    
private:
    
};

//巡逻
class AIPatrol
:public AIState
{
public:
    virtual void Tick( CNpc& npc, u32 dt );
    virtual void OnEnter( CNpc& npc );
    virtual void OnExit( CNpc& npc );
private:
    void ChangeTarget(CNpc& npc);
    float m_totalTime;
};
//攻击
class AIAttack
:public AIState
{
public:
    virtual void Tick( CNpc& npc, u32 dt );
    virtual void OnEnter( CNpc& npc );
    virtual void OnExit( CNpc& npc );
private:
    void SendAttack(CNpc& npc);
    float m_nextAttack;
};
//死亡
class AIDead
:public AIState
{
public:
    virtual void Tick( CNpc& npc, u32 dt );
    virtual void OnEnter( CNpc& npc );
    virtual void OnExit( CNpc& npc );
private:
};

#endif /* defined(__Server__AIState__) */

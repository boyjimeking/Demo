//
//  AIControl.h
//  Server
//
//  Created by xiangyu on 13-1-9.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__AIControl__
#define __Server__AIControl__

#include "SOBNpc.h"

struct ENNPCAIState
{
    enum Decl
    {
        enError = -1,
        enPatrol,
        enAttack,
        enDead,
        
        Count,
    };
};
class AIState;
class NPC;
class AIControl
{
public:
    AIControl(void);
    virtual ~AIControl(void);
    
    void Tick(CNpc& npc, u32 dt);
    
    void ChangeState(CNpc& npc, ENNPCAIState::Decl type);
protected:
    
private:
    ENNPCAIState::Decl m_currentState;
    AIState *m_state[ENNPCAIState::Count];
};

#endif /* defined(__Server__AIControl__) */

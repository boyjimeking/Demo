//
//  AIControl.cpp
//  Server
//
//  Created by xiangyu on 13-1-9.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "AIControl.h"
#include "AIState.h"
#include "Tools.h"

AIControl::AIControl(void)
:m_currentState(ENNPCAIState::enError)
{
    m_state[ENNPCAIState::enPatrol] = new AIPatrol;
    m_state[ENNPCAIState::enAttack] = new AIAttack;
    m_state[ENNPCAIState::enDead] = new AIDead;
}

AIControl::~AIControl(void)
{
    for (int index = 0; index < ENNPCAIState::Count; ++index)
    {
        delete m_state[index];
        m_state[index] = NULL;
    }
}

void AIControl::ChangeState(CNpc& npc, ENNPCAIState::Decl type)
{
    if (type == m_currentState)
    {
        return;
    }
    if (ENNPCAIState::enError != m_currentState)
    {
        m_state[m_currentState]->OnExit(npc);
    }
    m_currentState = type;
    m_state[m_currentState]->OnEnter(npc);
}

void AIControl::Tick(CNpc& npc, u32 dt)
{
    if (ENNPCAIState::enError == m_currentState)
    {
        ChangeState(npc, ENNPCAIState::enPatrol);
    }
    m_state[m_currentState]->Tick(npc, dt);
}


//
//  MainActor.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "MainActor.h"
#include "../CSProtocol/CSMessageDef.h"
#include "Server.h"

namespace Net
{
    void MainActor::SycPosition(void)
    {
    	CSInitMainActor_S2C message;
        message.m_mainActorID = GetID();
        message.m_x = GetX();
        message.m_y = GetY();
        message.Build(GetMessageType(CSInitMainActor_S2C), GetID(), sizeof(CSInitMainActor_S2C));
        Send(&message);
    }
}
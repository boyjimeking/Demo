//
//  Server.cpp
//  server
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#include <stdlib.h>
#include "GameServer.h"
#include "GameAccount.h"
#include "NetMng.h"
#include "../../Demo/Comm/CommDef.h"
#include "Tools.h"
#include "../../Demo/Tools/Scene.h"
#include "SOBPlayer.h"
#include "SOBNpc.h"
#include "Tools.h"

float CGameServer::Width = 384.0f;
float CGameServer::Height = 192.0f;
float CGameServer::GridSize = 0.5f;
float CGameServer::TranScale = 10.0f;//一米多少点

int CGameServer::RandX(void)
{
    return (float)rand() / (float)RAND_MAX * Width;
}
int CGameServer::RandY(void)
{
    return (float)rand() / (float)RAND_MAX * Height;
}

void CGameServer::Update(u32 elps)
{
    CPlayer::UpdateAll(elps);
    CNpc::UpdateAll(elps);
}

bool CGameServer::Init(void)
{
    srand(time(0));
    
    //scene initialize
    unsigned int size = 0;
    unsigned char *buff = GetFileData("/Users/xiangyu/projects/DemoNew/Demo/Demo/Resources/Demo.pkm", "rb", &size);
    
    Tools::Scene scene;
    scene.Read(buff, size);
    delete[] buff;
    Width = scene.GetWidth();
    Height = scene.GetHeight();
    GridSize = scene.GetGridSize();
    TranScale = scene.GetTransScale();
    
    //NPC initialize
    if(InitNpc() == false)
    {
        dprint(Lg_Info, "Fail to initialize NPCs!\n");
        return false;
    }
    return true;
}

bool CGameServer::InitNpc(void )
{
    for (int index = 0; index < 50; ++index)
    {
        CNpc* p = new CNpc;
        p->OnPush(this);
        if(p->Init() == true)
        {
            PushObject(p);
            p->AddObservers();
            p->AddNpcMap();
        }
    }
}
//
//  Schedule.h
//  Server
//
//  Created by xiangyu on 13-1-16.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__Schedule__
#define __Server__Schedule__

#include <string>
#include "GameServer.h"
#include "Tools.h"
#include "NetMng.h"

struct GSConfig{
    u16 port;
    int threadCount;
    int speedLimit;
};

class CSchedule{
public:
    void Run(void);
    bool LoadConfig(std::string filename);
private:
    CGameServer m_gameServer;
    CSNetMng m_netMng;
    GSConfig m_config;
};

#endif /* defined(__Server__Schedule__) */

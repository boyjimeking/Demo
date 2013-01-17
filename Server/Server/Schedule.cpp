//
//  Schedule.cpp
//  Server
//
//  Created by xiangyu on 13-1-16.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "Schedule.h"
#include "Tools.h"

void CSchedule::Run(void)
{
    if(!LoadConfig("GameSetting.ini"))
    {
        dprint(Lg_Info,"Fail to load configure file!\n");
        return ;
    }
    m_gameServer.Init();
    m_netMng.SetGameServer(&m_gameServer);
    m_netMng.Start(m_config.port, m_config.threadCount, m_config.speedLimit);
    
    time_t oldSvrTime, elpsTime;
    time(&oldSvrTime);
    while(1)
    {
        elpsTime = time(0) - oldSvrTime;
        time(&oldSvrTime);
        m_gameServer.Update(elpsTime);
    }
}

bool CSchedule::LoadConfig(std::string filename)
{
    m_config.port = 20051;
    m_config.speedLimit = 200*1024;
    m_config.threadCount = 3;
    
    return true;
}
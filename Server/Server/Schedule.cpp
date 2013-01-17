//
//  Schedule.cpp
//  Server
//
//  Created by xiangyu on 13-1-16.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "Schedule.h"
#include "Tools.h"
#include "tinyxml/tinyxml.h"

void CSchedule::Run(void)
{
    if(!LoadConfig("GameSetting.xml"))
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
    TiXmlDocument setting_file;
    if(!setting_file.LoadFile(filename.c_str()))
    {
        dprint(Lg_Info, "Can't find the file %s!\n", filename.c_str());
        return false;
    }
    TiXmlElement* root = setting_file.FirstChildElement("GameServer");
    assert(root);
    
    m_config.port = atoi(root->Attribute("port"));
    m_config.speedLimit = atoi(root->Attribute("speedLimit"))*1024;
    m_config.threadCount = atoi(root->Attribute("threadCount"));;
    
    return true;
}
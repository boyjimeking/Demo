//
//  main.cpp
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//


//#include "stdafx.h"
#define __CLIENT_MSG_DEFINITION__

#include "../../Demo/Comm/CommDef.h"
#include "NetMng.h"

//CSNetMng net;
int main(int argc, char* argv[])
{
	if (argc==1)
	{
		return -1;
	}
	bool isServer = false;
	int speedLimit=20*1024;
	std::string host;
	int port = 0;
	std::string port_str;
	int threadCount=1;
	int connCount=1;
	std::string cur;
	char curParam = 0;
	char* ptr = argv[1];
	while(*ptr)
	{
		if (*ptr == '-')
		{
			if (curParam=='s')
			{
				isServer=true;
			}
			if (curParam=='l')
			{
				speedLimit=atoi(cur.c_str());
				speedLimit*=1024;
			}
			if (curParam=='h')
			{
				host=cur;
			}
			if (curParam=='p')
			{
				port=atoi(cur.c_str());
				port_str=cur;
			}
			if (curParam=='t')
			{
				threadCount=atoi(cur.c_str());
			}
			if (curParam=='c')
			{
				connCount=atoi(cur.c_str());
			}
			cur.clear();
			curParam = *(ptr+1);
			ptr+=2;
			continue;
		}
		cur.push_back(*ptr);
		++ptr;
	}
	if (!cur.empty())
	{
		if (curParam=='s')
		{
			isServer=true;
		}
		if (curParam=='l')
		{
			speedLimit=atoi(cur.c_str());
			speedLimit*=1024;
		}
		if (curParam=='h')
		{
			host=cur;
		}
		if (curParam=='p')
		{
			port=atoi(cur.c_str());
			port_str=cur;
		}
		if (curParam=='t')
		{
			threadCount=atoi(cur.c_str());
		}
		if (curParam=='c')
		{
			connCount=atoi(cur.c_str());
		}
	}
    int a(0),b(9),c;
    c =a + b;

	if (isServer)
	{
        CGameServer::Instance()->Init();
        CSNetMng::Instance()->Start(port,threadCount,speedLimit);

        time_t oldSvrTime, elpsTime;
        time(&oldSvrTime);
        while(1)
		{
			char cmd[256];
			gets(cmd);
			if(strcmp(cmd, "quit")==0)
				return 0;
            elpsTime = time(0) - oldSvrTime;
            time(&oldSvrTime);
            CGameServer::Instance()->Update(elpsTime);
		}
	}

	return 0;
}


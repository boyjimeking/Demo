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
#include "Schedule.h"

int main(int argc, char* argv[])
{
    CSchedule schedule;
    schedule.Run();

	return 0;
}


//
//  NetMng.cpp
//  server
//
//  Created by xiangyu on 12-12-21.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#include "NetMng.h"
#include "Tools.h"

CSNetMng* CSNetMng::Instance(void)
{
    static CSNetMng* inst= 0;
    if(!inst)
    {
        inst=new CSNetMng;
    }
    return inst;
}

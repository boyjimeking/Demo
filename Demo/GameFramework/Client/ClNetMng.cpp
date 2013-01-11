//
//  ClNetMng.cpp
//  client
//
//  Created by xiangyu on 13-1-5.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "ClNetMng.h"

CClNetMng* CClNetMng::_ins;

CClNetMng * CClNetMng::Instance(void)
{
    if(_ins == NULL)
    {
        _ins = new CClNetMng();
    }
    return _ins;
}

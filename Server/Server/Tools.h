//
//  Tools.h
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__Tools__
#define __Server__Tools__

#include "../../Demo/Comm/CommDef.h"

enum EN_Debug_Level{
    Lg_Trace,
    Lg_Debug,
    Lg_Info,
    Lg_Notice,
    Lg_Warning,
    Lg_Error,
    Lg_Critical
};

void dprint(EN_Debug_Level level, const char *fmt, ...);
unsigned char* GetFileData(const char* pszFileName, const char* pszMode, unsigned int * pSize);


#endif /* defined(__Server__Tools__) */

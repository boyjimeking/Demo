//
//  Tools.cpp
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "Tools.h"
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>

unsigned char* GetFileData(const char* pszFileName, const char* pszMode, unsigned int * pSize)
{
    unsigned char * pBuffer = NULL;
    assert(pszFileName != NULL && pSize != NULL && pszMode != NULL);
    *pSize = 0;
    do
    {
        // read the file from hardware
        FILE *fp = fopen(pszFileName, pszMode);
        if(!fp)
            break;
        
        fseek(fp,0,SEEK_END);
        *pSize = ftell(fp);
        fseek(fp,0,SEEK_SET);
        pBuffer = new unsigned char[*pSize];
        *pSize = fread(pBuffer,sizeof(unsigned char), *pSize,fp);
        fclose(fp);
    } while (0);
    
    if (!pBuffer)
    {
        printf("Get data from file(%s) failed!\n", pszFileName);
    }
    return pBuffer;
}

void dprint(EN_Debug_Level level, const char *fmt, ...)
{
    switch(level)
    {
        case Lg_Debug:
        {
            va_list arg;
            va_start(arg, fmt);
            vprintf(fmt, arg);
            va_end(arg);
        }
            break;
        default:
        {
            va_list arg;
            va_start(arg, fmt);
            vprintf(fmt, arg);
            va_end(arg);
        }
            break;
    }

}
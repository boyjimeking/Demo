//
//  NetCounter.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Comm__NetCounter__H__
#define __Comm__NetCounter__H__



namespace Net
{
    struct NetRateCount
    {
        //enum
        //{
        //!统计区间
        int m_countSecond;
        //};
        NetRateCount(void):m_bytesPerSecond(0),m_totalBytes(0),m_bytesCounted(0),m_countSecond(1),m_bytesThisSecond(0){}
        unsigned int m_bytesCounted;
        unsigned int m_totalBytes;
        unsigned int m_bytesPerSecond;
        unsigned int m_bytesThisSecond;
        boost::posix_time::ptime m_thisSecond;
        void Count(unsigned int incBytes)
        {
            m_totalBytes += incBytes;
            m_bytesThisSecond+=incBytes;
        }
        unsigned int RefreshRate(void)
        {
            boost::posix_time::ptime now = boost::posix_time::microsec_clock::universal_time();
            boost::posix_time::time_duration diff = now-m_thisSecond;
            unsigned int diffMillisecond = diff.total_milliseconds();
            
            unsigned int curTick = 0;//GetTickCount();
            unsigned int bytesTotal = m_totalBytes;
            if (diffMillisecond > m_countSecond*1000)
            {
                m_bytesPerSecond = (bytesTotal-m_bytesCounted)*1000/(diffMillisecond);
                m_bytesCounted = bytesTotal;
                m_thisSecond=now;
                m_bytesThisSecond=0;
            }
            return m_bytesPerSecond;
        }
    };
}
#endif

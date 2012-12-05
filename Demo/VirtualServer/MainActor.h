//
//  MainActor.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__MainActor__
#define __Demo__MainActor__

#include "ServerActor.h"

namespace Net
{
    class MainActor
        :public ServerActor
    {
        virtual void SycPosition(void);
    };
}

#endif /* defined(__Demo__MainActor__) */

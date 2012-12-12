//
//  CameraObserver.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_CameraObserver_h
#define Demo_CameraObserver_h

#include "Base/IObserver.h"
#include "base_nodes/CCNode.h"

namespace cocos2d
{
    class CCScene;
}

namespace Game
{
    class CameraObserver
        :public IObserver
        ,public cocos2d::CCNode
    {
    public:
        static CameraObserver* Create(void);
        CameraObserver(void);
        void Init(void);
        virtual ~CameraObserver(void);
        virtual void OnNotifyChange(INotifier *notify, const INotifyEvent *event);
    private:
    };
}

#endif

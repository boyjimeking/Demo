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

namespace cocos2d
{
    class CCScene;
}

namespace Game
{
    class CameraObserver
        :public IObserver
    {
    public:
        CameraObserver(cocos2d::CCScene *scene);
        virtual ~CameraObserver(void);
        virtual void OnNotifyChange(INotifier *notify, const INotifyEvent *event);
    private:
        cocos2d::CCScene *m_scene;
    };
}

#endif

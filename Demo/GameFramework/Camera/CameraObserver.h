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
    class CCCamera;
}

namespace Game
{
    class CameraObserver
        :public IObserver
    {
    public:
        CameraObserver(void);
        virtual ~CameraObserver(void);
        virtual void OnNotifyChange(const INotifier *notify, const INotifyEvent *event);
    private:
        cocos2d::CCCamera *m_camera;
    };
}

#endif

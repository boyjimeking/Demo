//
//  Camera.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_Camera_h
#define Demo_Camera_h

#include "Base/INotifier.h"
#include "cocoa/CCGeometry.h"

namespace cocos2d
{
    class CCScene;
}

namespace Game
{
	class CameraObserver;
    class Camera
        :public INotifier
    {
    public:
        Camera(void);
        virtual ~Camera(void);

        void init(cocos2d::CCScene *scene);
        
        cocos2d::CCPoint ConvertWorldPosToScreen(const cocos2d::CCPoint &worldPos);
        cocos2d::CCPoint ConvertScreenPosToWorld(const cocos2d::CCPoint &screenPos);
    protected:
    private:
        cocos2d::CCPoint m_position;

    };
}

#endif

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

        void init(IObserver *observer);
        
        cocos2d::CCPoint ConvertWorldPosToDesign(const cocos2d::CCPoint &worldPos);
        cocos2d::CCPoint ConvertDesignPosToWorld(const cocos2d::CCPoint &screenPos);

        void SetPosition(const cocos2d::CCPoint &newPosition);
        const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
    protected:
    private:
        cocos2d::CCSize m_size;
        cocos2d::CCPoint m_position;
    };
}

#endif

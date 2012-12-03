//
//  Camera.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "Camera.h"
#include "CameraObserver.h"
#include "CameraNotifyEvents.h"
#include "support/CCPointExtension.h"
#include "CCDirector.h"

namespace Game
{
    Camera::Camera(void)
        :m_position(-480, -240)
        ,m_size(960, 640)
    {

    }
    Camera::~Camera(void)
    {
    	//只有Camera类知道CameraObserver，所以在释放的时候要把observer释放掉
    	delete reinterpret_cast<CameraObserver*>(m_observer);
    }

    void Camera::init(cocos2d::CCScene *scene)
    {
        m_size = cocos2d::CCDirector::sharedDirector()->getVisibleSize();
        m_position = ccp(-m_size.width / 2, -m_size.height / 2);
    	CameraObserver *observer = new CameraObserver(scene);
    	this->AttachObserver(observer);

        CameraPosChanged event(m_position);
        NotifyChange(&event);
    }

    cocos2d::CCPoint Camera::ConvertWorldPosToScreen(const cocos2d::CCPoint &worldPos)
    {
        return cocos2d::ccpSub(worldPos, m_position);
    }
    cocos2d::CCPoint Camera::ConvertScreenPosToWorld(const cocos2d::CCPoint &screenPos)
    {
        return cocos2d::ccpAdd(screenPos, m_position);
    }

    void Camera::SetPosition(const cocos2d::CCPoint &newPosition)
    {
        m_position = newPosition;
        m_position.x -= m_size.width / 2;
        m_position.y -= m_size.height / 2;
        CameraPosChanged event(m_position);
        NotifyChange(&event);
    }
}
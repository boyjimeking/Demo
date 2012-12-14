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
#include "Camera.h"
#include "layers_scenes_transitions_nodes/CCScene.h"

namespace Game
{
    Camera::Camera(void)
        :m_size(960, 640)
		,m_scale(1.0f)
    {

    }
    Camera::~Camera(void)
    {
    	
    }

    void Camera::init(IObserver *observer)
    {
        this->AttachObserver(observer);

        m_size = cocos2d::CCDirector::sharedDirector()->getWinSize();
        SetPosition(cocos2d::CCPointZero);
    }

    cocos2d::CCPoint Camera::ConvertWorldPosToDesign(const cocos2d::CCPoint &worldPos)
    {
		cocos2d::CCPoint newPos = cocos2d::ccpSub(worldPos, GetPosition());
		newPos.x *= m_scale;
		newPos.y *= m_scale;
		newPos.x += m_size.width / 2;
		newPos.y += m_size.height / 2;
        return newPos;
    }
    cocos2d::CCPoint Camera::ConvertDesignPosToWorld(const cocos2d::CCPoint &screenPos)
    {
		cocos2d::CCPoint newPos = screenPos;
		newPos.x -= m_size.width / 2;
		newPos.y -= m_size.height / 2;
		newPos.x /= m_scale;
		newPos.y /= m_scale;
        return cocos2d::ccpAdd(newPos, GetPosition());
    }

    void Camera::SetPosition(const cocos2d::CCPoint &newPosition)
    {
        m_position = newPosition;
		cocos2d::CCPoint entityPos = m_position;
        entityPos.x -= m_size.width / 2;
        entityPos.y -= m_size.height / 2;
        CameraPosChanged event(entityPos);
        NotifyChange(&event);
    }

	void Camera::SetScale( float scale )
	{
		m_scale = scale;
		CameraScaleChanged event(m_scale);
		NotifyChange(&event);
	}

}
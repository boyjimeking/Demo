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
#include "SceneInfo.h"
#include "WorldManager.h"

namespace Game
{
    Camera::Camera(void)
        :m_size(0.0f, 0.0f)
		,m_transScale(1.0f)
    {

    }
    Camera::~Camera(void)
    {
    	
    }

    void Camera::init(IObserver *observer)
    {
        this->AttachObserver(observer);

		SetTransScale(1.0f);
		SetPosition(cocos2d::CCPointZero);
    }

    cocos2d::CCPoint Camera::ConvertWorldPosToDesign(const cocos2d::CCPoint &worldPos)
    {
		cocos2d::CCPoint newPos = cocos2d::ccpSub(worldPos, GetPosition());
		newPos.x += PointToLogic(m_size.width) / 2;
		newPos.y += PointToLogic(m_size.height) / 2;
        return LogicToPoint(newPos);
    }
    cocos2d::CCPoint Camera::ConvertDesignPosToWorld(const cocos2d::CCPoint &screenPos)
    {
		cocos2d::CCPoint newPos = PointToLogic(screenPos);
		newPos.x -= PointToLogic(m_size.width) / 2;
		newPos.y -= PointToLogic(m_size.height) / 2;
        return cocos2d::ccpAdd(newPos, GetPosition());
    }
	float Camera::LogicToPoint( float size )
	{
		return size * m_transScale;
	}

	cocos2d::CCPoint Camera::LogicToPoint( const cocos2d::CCPoint &pos )
	{
		return ccpMult(pos, m_transScale);
	}

	cocos2d::CCSize Camera::LogicToPoint( const cocos2d::CCSize &pos )
	{
		return cocos2d::CCSizeMake(pos.width * m_transScale, pos.height * m_transScale);
	}

	float Camera::PointToLogic( float size )
	{
		return size / m_transScale;
	}

	cocos2d::CCPoint Camera::PointToLogic( const cocos2d::CCPoint &pos )
	{
		return ccpMult(pos, 1.0f / m_transScale);
	}

	cocos2d::CCSize Camera::PointToLogic( const cocos2d::CCSize &pos )
	{
		return cocos2d::CCSizeMake(pos.width / m_transScale, pos.height / m_transScale);
	}

    void Camera::SetPosition(const cocos2d::CCPoint &newPosition)
    {
		if (m_position.equals(newPosition))
		{
			return;
		}
		cocos2d::CCPoint innerPos = newPosition;
		if (newPosition.x < 4.8f || newPosition.x > WorldManager::Instance()->GetSceneInfo()->GetWidth() - 9.6f)
		{
			innerPos.x = m_position.x;
		}
		if (newPosition.y < 3.2f || newPosition.y > WorldManager::Instance()->GetSceneInfo()->GetHeight() - 4.8f)
		{
			innerPos.y = m_position.y;
		}
		if (m_position.equals(innerPos))
		{
			return;
		}
        m_position = innerPos;
		cocos2d::CCPoint entityPos = m_position;
        entityPos.x -= m_size.width / 2;
        entityPos.y -= m_size.height / 2;
        CameraPosChanged event(entityPos);
        NotifyChange(&event);
    }

	void Camera::SetRootScale( float scale )
	{
		CameraScaleChanged event(scale);
		NotifyChange(&event);
	}

	void Camera::SetTransScale( float transScale )
	{
		m_transScale = transScale;
		m_size = cocos2d::CCDirector::sharedDirector()->getWinSize();
		SetRootScale(transScale);
	}

	void Camera::Shake( void )
	{
		CameraShake event;
		NotifyChange(&event);
	}

}
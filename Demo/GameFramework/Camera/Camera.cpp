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
		SetPosition(CCPointZero);
    }

    CCPoint Camera::ConvertWorldPosToDesign(const CCPoint &worldPos)
    {
		CCPoint newPos = ccpSub(worldPos, GetPosition());
		newPos.x += PointToLogic(m_size.width) / 2;
		newPos.y += PointToLogic(m_size.height) / 2;
        return LogicToPoint(newPos);
    }
    CCPoint Camera::ConvertDesignPosToWorld(const CCPoint &screenPos)
    {
		CCPoint newPos = PointToLogic(screenPos);
		newPos.x -= PointToLogic(m_size.width) / 2;
		newPos.y -= PointToLogic(m_size.height) / 2;
        return ccpAdd(newPos, GetPosition());
    }
	float Camera::LogicToPoint( float size )
	{
		return size * m_transScale;
	}

	CCPoint Camera::LogicToPoint( const CCPoint &pos )
	{
		return ccpMult(pos, m_transScale);
	}

	CCSize Camera::LogicToPoint( const CCSize &pos )
	{
		return CCSizeMake(pos.width * m_transScale, pos.height * m_transScale);
	}

	float Camera::PointToLogic( float size )
	{
		return size / m_transScale;
	}

	CCPoint Camera::PointToLogic( const CCPoint &pos )
	{
		return ccpMult(pos, 1.0f / m_transScale);
	}

	CCSize Camera::PointToLogic( const CCSize &pos )
	{
		return CCSizeMake(pos.width / m_transScale, pos.height / m_transScale);
	}

    void Camera::SetPosition(const CCPoint &newPosition)
    {
		CCPoint innerPos = newPosition;
		if (newPosition.x < 4.8f)
		{
			innerPos.x = 4.8f;
		}
		else if (newPosition.x > WorldManager::Instance()->GetSceneInfo()->GetWidth() - 9.6f)
		{
			innerPos.x = WorldManager::Instance()->GetSceneInfo()->GetWidth() - 9.6f;
		}
		if (newPosition.y < 3.2f)
		{
			innerPos.y = 3.2f;
		}
		else if (newPosition.y > WorldManager::Instance()->GetSceneInfo()->GetHeight() - 4.8f)
		{
			innerPos.y = WorldManager::Instance()->GetSceneInfo()->GetHeight() - 4.8f;
		}
        m_position = innerPos;
		CCPoint entityPos = m_position;
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
		m_size = CCDirector::sharedDirector()->getWinSize();
		SetRootScale(transScale);
	}

	void Camera::Shake( void )
	{
		CameraShake event;
		NotifyChange(&event);
	}

	void Camera::Reset( void )
	{
		CCPoint entityPos = m_position;
		entityPos.x -= m_size.width / 2;
		entityPos.y -= m_size.height / 2;
		CameraReset event(entityPos);
		NotifyChange(&event);
	}

}
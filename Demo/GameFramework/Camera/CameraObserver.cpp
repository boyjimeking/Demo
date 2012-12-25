//
//  CameraObserver.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "CameraObserver.h"
#include "CCCamera.h"
#include "CameraNotifyEvents.h"
#include "support/CCPointExtension.h"
#include "WorldManager.h"
#include "actions/CCActionInterval.h"
#include "Actors/ActorProp.h"
#include "Actors/ActorsControl.h"

namespace Game
{
    CameraObserver* CameraObserver::Create(void)
    {
        CameraObserver *camera = new CameraObserver();
        camera->Init();
        camera->autorelease();
        return camera;
    }
    CameraObserver::CameraObserver(void)
    {
        
    }
    CameraObserver::~CameraObserver(void)
    {
        
    }
    void CameraObserver::Init(void)
    {

    }

	class ShakeAction
		:public cocos2d::CCActionInterval
	{
	public:
		ShakeAction(float scale) : m_srcScale(scale) {}

		virtual void update( float time ) 
		{
			//float scale = (float)rand() / (float)RAND_MAX * 0.1f * m_srcScale - 0.05f * m_srcScale + m_srcScale;
			//this->m_pTarget->setScale(scale);
			cocos2d::CCPoint pos = WorldManager::Instance()->GetActorsControl()->GetMainActor()->GetPosition();
			this->m_pTarget->setPosition(pos.x + (float)rand() / (float)RAND_MAX * 10.0f - 5.0f, pos.y + (float)rand() / (float)RAND_MAX * 10.0f - 5.0f);
		}

		virtual void stop( void ) 
		{
			this->m_pTarget->setPosition(WorldManager::Instance()->GetActorsControl()->GetMainActor()->GetPosition());
		}

	private:
		float m_srcScale;
	};
    void CameraObserver::OnNotifyChange(INotifier *notify, const INotifyEvent *event)
    {
        if (NULL == event)
        {
            return;
        }
        switch (event->GetNotifyEventType())
        {
            case ENCameraEvent::enPosChanged:
                {
                    const CameraPosChanged *posChangedEvent = reinterpret_cast<const CameraPosChanged*>(event);
                    setPosition(cocos2d::ccpNeg(posChangedEvent->GetCameraPosition()));
                }
                break;
			case ENCameraEvent::enScaleChanged:
				{
					const CameraScaleChanged *changedEvent = reinterpret_cast<const CameraScaleChanged*>(event);
					getParent()->setScale(changedEvent->GetScale());
				}
				break;
			case ENCameraEvent::enShake:
				{
					ShakeAction *action = new ShakeAction(getParent()->getScale());
					action->initWithDuration(0.3f);
					action->autorelease();
					getParent()->runAction(action);
				}
            default:
                break;
        }
    }
}
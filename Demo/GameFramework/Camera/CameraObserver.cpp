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
                    //setPosition(cocos2d::ccpNeg(posChangedEvent->GetCameraPosition()));
					cocos2d::CCPoint newPos = cocos2d::ccpNeg(posChangedEvent->GetCameraPosition());
					cocos2d::CCPoint dis = cocos2d::ccpSub(newPos, m_lastPos);
					if ( m_pChildren && m_pChildren->count() > 0 )
					{
						CCObject* child;
						CCARRAY_FOREACH(m_pChildren, child)
						{
							CCNode* pNode = (CCNode*)child;
							if (pNode)
							{
								MoveScale::iterator it = m_moveScale.find(pNode);
								if (m_moveScale.end() == it)
								{
									pNode->setPosition(newPos);
								}
								else
								{
									pNode->setPosition(ccpAdd(pNode->getPosition(), ccpMult(dis, it->second)));
								}
							}
						}
					}
					m_lastPos = cocos2d::ccpNeg(posChangedEvent->GetCameraPosition());
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
				break;
			case ENCameraEvent::enReset:
				{
					const CameraReset *posChangedEvent = reinterpret_cast<const CameraReset*>(event);
					cocos2d::CCPoint newPos = cocos2d::ccpNeg(posChangedEvent->GetCameraPosition());
					if ( m_pChildren && m_pChildren->count() > 0 )
					{
						CCObject* child;
						CCARRAY_FOREACH(m_pChildren, child)
						{
							CCNode* pNode = (CCNode*)child;
							if (pNode)
							{
								pNode->setPosition(newPos);
							}
						}
					}
					m_lastPos = newPos;
				}
				break;
            default:
                break;
        }
    }

	void CameraObserver::addChild( CCNode *child, float moveScale )
	{
		CCAssert( child != NULL, "Argument must be non-nil");
		m_moveScale.insert(std::make_pair(child, moveScale));
		CCNode::addChild(child);
	}

	//void CameraObserver::addChild( CCNode * child, int zOrder, int tag )
	//{
	//	CC_UNUSED_PARAM(zOrder);
	//	CC_UNUSED_PARAM(child);
	//	CC_UNUSED_PARAM(tag);
	//	CCAssert(0,"CameraObserver: use addChild:moveScale instead");
	//}

	void CameraObserver::removeChild( CCNode* child, bool cleanup )
	{
		MoveScale::iterator it = m_moveScale.find(child);
		if (m_moveScale.end() != it)
		{
			m_moveScale.erase(it);
		}
		CCNode::removeChild(child, cleanup);
	}

	void CameraObserver::removeAllChildrenWithCleanup( bool cleanup )
	{
		m_moveScale.clear();
		CCNode::removeAllChildrenWithCleanup(cleanup);
	}

}
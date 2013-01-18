#include "SceneObjectEntity.h"
#include "SceneObjectEvents.h"
#include "Base/INotifier.h"
#include "WorldManager.h"
#include "Camera/Camera.h"
#include "Tools/FrameTools.h"
#include "../Tools/Scene.h"

namespace Game
{
	SceneObjectEntity* SceneObjectEntity::Create(void)
	{
		if (!INotifier::NotifyMode)
		{
			return NULL;
		}
		SceneObjectEntity *entity = new SceneObjectEntity();
	    if (entity/* && entity->init()*/)
	    {
	        entity->autorelease();
	        return entity;
	    }
	    CC_SAFE_DELETE(entity);
	    return NULL;
	}
	SceneObjectEntity::SceneObjectEntity(void)
		:m_batchNode(NULL)
	{

	}
	SceneObjectEntity::~SceneObjectEntity(void)
	{

	}
	void SceneObjectEntity::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
		case ENSceneObjectEvent::enInitObject:
			{
				const SceneObjectEventInit *objectEvent = reinterpret_cast<const SceneObjectEventInit*>(event);
				Tools::ObjectInfo *objInfo = objectEvent->m_objInfo;
				if (NULL != m_batchNode)
				{
					Tools::FrameTools::RefreshBatchNode(m_batchNode, *objInfo);
				}
				else
				{
					m_batchNode = Tools::FrameTools::CreateBatchNode(*objInfo);
					addChild(m_batchNode);
				}

				setPosition(cocos2d::CCPointMake(objInfo->m_x, objInfo->m_y));
				setContentSize(cocos2d::CCSizeMake(objInfo->width, objInfo->height));
				setAnchorPoint(cocos2d::CCPointZero);
				if (NULL != getParent())
				{
					getParent()->reorderChild(this, -getPosition().y * 1000);
				}
				else
				{
					_setZOrder(-getPosition().y * 1000);
				}
				setScale(WorldManager::Instance()->GetCamera()->GetObjectScale());
			}
			break;
		case ENSceneObjectEvent::enRemoveObject:
			{
				getParent()->removeChild(this, true);
			}
			break;
		default:
			break;
		}
	}
}
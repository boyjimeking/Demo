#include "SceneObjectsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "SceneObjectEvents.h"
#include "SceneObjectEntity.h"
#include "SceneObjectProp.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "SceneObjectControlEvent.h"
#include "WorldManager.h"

namespace Game
{
	SceneObjectsLayer::SceneObjectsLayer(void)
	{

	}
	SceneObjectsLayer::~SceneObjectsLayer(void)
	{

	}

	void SceneObjectsLayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
		case ENSceneObjectControl::enAddObject:
			{
				const SceneObjectControlEventAddObject *controlEvent = reinterpret_cast<const SceneObjectControlEventAddObject*>(event);
				cocos2d::CCLayer *layer = WorldManager::Instance()->LookupLayer(controlEvent->m_layerName);
				if (NULL != layer)
				{
					layer->addChild(controlEvent->m_entity);
				}
			}
			break;
		case ENSceneObjectControl::enAddObjectImage:
			{
				const SceneObjectEventAddObjectImage *controlEvent = reinterpret_cast<const SceneObjectEventAddObjectImage*>(event);
				cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(controlEvent->m_imageName.c_str());
			}
			break;
		case ENSceneObjectControl::enRemoveObjectImage:
			{
				const SceneObjectEventRemoveObjectImage *controlEvent = reinterpret_cast<const SceneObjectEventRemoveObjectImage*>(event);
				cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(controlEvent->m_imageName.c_str());
			}
			break;
		default:
			break;
		}
	}

}
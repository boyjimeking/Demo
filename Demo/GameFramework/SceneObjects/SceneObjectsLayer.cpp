#include "SceneObjectsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "SceneObjectEvents.h"
#include "SceneObjectEntity.h"
#include "SceneObjectProp.h"
#include "sprite_nodes/CCSpriteFrameCache.h"

namespace Game
{
	SceneObjectsLayer::SceneObjectsLayer(cocos2d::CCLayer *entityLayer)
		:m_entityLayer(entityLayer)
	{

	}
	SceneObjectsLayer::~SceneObjectsLayer(void)
	{

	}

	void SceneObjectsLayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
			case ENSceneObjectEvent::enInitLayer:
				{
					int size = reinterpret_cast<const SceneObjectEventInitLayer*>(event)->m_size;
					cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(reinterpret_cast<const SceneObjectEventInitLayer*>(event)->m_imageNameList.back().c_str());
					SceneObjectProp **entityList = reinterpret_cast<const SceneObjectEventInitLayer*>(event)->m_entity;
					for (int index = 0; index < size; ++index)
					{
						SceneObjectEntity *entity = entityList[index]->CreateEntity();
						m_entityLayer->addChild(entity);
						if (NULL != entity->getParent())
						{
							entity->getParent()->reorderChild(entity, -entity->getPosition().y);
						}
						else
						{
							entity->_setZOrder(-entity->getPosition().y);
						}
					}
				}
				break;
			default:
				break;
		}
	}

}
#include "BuildingsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "BuildingEvents.h"
#include "BuildingEntity.h"
#include "BuildingProp.h"
#include "sprite_nodes/CCSpriteFrameCache.h"

namespace Game
{
	BuildingsLayer::BuildingsLayer(cocos2d::CCLayer *entityLayer)
		:m_entityLayer(entityLayer)
	{

	}
	BuildingsLayer::~BuildingsLayer(void)
	{

	}

	void BuildingsLayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
			case ENBuildingEvent::enInitLayer:
				{
					int size = reinterpret_cast<const BuildingEventInitLayer*>(event)->m_size;
					cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(reinterpret_cast<const BuildingEventInitLayer*>(event)->m_imageNameList.back().c_str());
					BuildingProp **entityList = reinterpret_cast<const BuildingEventInitLayer*>(event)->m_entity;
					for (int index = 0; index < size; ++index)
					{
						BuildingEntity *entity = entityList[index]->CreateEntity();
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
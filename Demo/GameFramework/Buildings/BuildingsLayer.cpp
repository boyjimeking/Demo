#include "BuildingsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "BuildingEvents.h"
#include "BuildingEntity.h"

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
			case ENBuildingEvent::enBuildingEvent_InitLayer:
				{
					int size = reinterpret_cast<const BuildingEventInitLayer*>(event)->m_size;
					BuildingEntity **entityList = reinterpret_cast<const BuildingEventInitLayer*>(event)->m_entity;
					for (int index = 0; index < size; ++index)
					{
						m_entityLayer->addChild(entityList[index]);
						if (NULL != entityList[index]->getParent())
						{
							entityList[index]->getParent()->reorderChild(entityList[index], -entityList[index]->getPosition().y);
						}
						else
						{
							entityList[index]->_setZOrder(-entityList[index]->getPosition().y);
						}
					}
				}
				break;
			default:
				break;
		}
	}

}
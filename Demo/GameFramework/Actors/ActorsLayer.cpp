#include "ActorsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "ActorsControlEvents.h"
#include "ActorEntity.h"
#include "WorldManager.h"

namespace Game
{
	ActorsLayer::ActorsLayer(void)
	{

	}
	ActorsLayer::~ActorsLayer(void)
	{

	}

	void ActorsLayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
			case ENActorsControlEvents::enCreateActor:
				{
					const ActorsControlEventCreateActor *createEvent = reinterpret_cast<const ActorsControlEventCreateActor*>(event);
					ActorEntity *entity = createEvent->GetActorEntity();
					cocos2d::CCLayer *layer = WorldManager::Instance()->LookupLayer(createEvent->GetLayerName());
					if (NULL != layer)
					{
						layer->addChild(entity);
					}
				}
				break;
			default:
				break;
		}
	}

}
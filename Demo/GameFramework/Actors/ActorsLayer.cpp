#include "ActorsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "ActorsControlEvents.h"
#include "ActorEntity.h"

namespace Game
{
	ActorsLayer::ActorsLayer(cocos2d::CCLayer *entityLayer)
		:m_entityLayer(entityLayer)
	{

	}
	ActorsLayer::~ActorsLayer(void)
	{

	}

	void ActorsLayer::OnNotifyChange( const INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
			case ENActorsControlEvents::enActorsControlEvent_CreateActor:
				{
					const ActorsControlEventCreateActor *createEvent = reinterpret_cast<const ActorsControlEventCreateActor*>(event);
					ActorEntity *entity = createEvent->GetActorEntity();
					m_entityLayer->addChild(entity);
				}
				break;
			default:
				break;
		}
	}

}
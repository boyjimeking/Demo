#include "UITargetProp.h"
#include "Base/INotifyEvent.h"
#include "Actors/ActorEvents.h"
#include "UIEvents.h"
#include "Actors/ActorProp.h"
#include "../CSProtocol/ActorBattleInfo.h"

namespace GUI
{
	UITargetProp::UITargetProp(void)
	{

	}

	UITargetProp::~UITargetProp(void)
	{

	}

	void UITargetProp::Init( const std::string &windowName )
	{
		UIProperty::Init(windowName);
	}

	void UITargetProp::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (notify->GetType())
		{
		case GetNotifierType(ActorProp):
			{
				switch (event->GetNotifyEventType())
				{
				case Game::ENActorEvent::enAttachUI:
					{
						Game::ActorProp *prop = reinterpret_cast<const Game::ActorEventAttachUI*>(event)->m_prop;
						int maxHp = prop->GetBattleInfo()->GetMaxHP();
						int currentHp = prop->GetBattleInfo()->GetHP();
						UIEventAttachActor innerEvent(maxHp, currentHp);
						NotifyChange(&innerEvent);
					}
					break;
				case Game::ENActorEvent::enBeAttacked:
					{
						Game::ActorProp *prop = reinterpret_cast<Game::ActorProp*>(notify);
						UIEventChangeTargetHp innerEvent(prop->GetBattleInfo()->GetHP());
						NotifyChange(&innerEvent);
					}
					break;
				default:
					break;
				}
			}
			break;
		default:
			break;
		}

	}

}
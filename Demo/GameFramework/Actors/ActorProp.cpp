#include "ActorProp.h"
#include "ActorEvents.h"
#include "ActorEntity.h"
#include "WorldManager.h"
#include "SceneInfo.h"
#include "Client/Client.h"
#include "../CSProtocol/ActorBattleInfo.h"
#include "UI/UIProperty.h"

namespace Game
{
	ActorProp::ActorProp(ENActorType::Decl type, int id)
	:m_id(id)
	,m_type(type)
	,m_speed(3.0f)
	,m_battleInfo(new ActorBattleInfo)
	,m_actionControl(new ActionControl)
	{

	}
	ActorProp::~ActorProp(void)
	{
		delete m_battleInfo;
		delete m_actionControl;
	}

	void ActorProp::Init(void)
	{
		switch (GetActorType())
		{
			case ENActorType::enMain:
				{
					
				}
				break;
			default:
				break;
		}
	}
	ActorEntity* ActorProp::Create(void)
	{
		ActorEntity *entity = new ActorEntity(this);
		entity->autorelease();
		AttachObserver(entity);

		ActorEventCreate event(GetActorType());
		NotifyChange(&event);
		return entity;
	}

	void ActorProp::Release(void)
	{
		ActorEventRelease event;
		NotifyChange(&event);
	}
	void ActorProp::MoveTo(const cocos2d::CCPoint &pos)
	{
		if (!GetBattleInfo()->IsAlive())
		{
			return;
		}
		m_actionControl->AddAction(this, new MoveAction(pos));
	}
	void ActorProp::SetPosition(const cocos2d::CCPoint &pos)
	{
		if (!WorldManager::Instance()->GetSceneInfo()->IsPointCanStanc(pos))
		{
			return;
		}
		if (m_position.equals(pos))
		{
			return;
		}
		m_position = pos;
		ActorEventChangePos event(pos);
		NotifyChange(&event);
	}
	void ActorProp::Stop(void)
	{
		if (!GetBattleInfo()->IsAlive())
		{
			return;
		}
		m_actionControl->AddAction(this, new StopAction);
	}
	void ActorProp::StartAttack(ActorProp *target)
	{
		if (!GetBattleInfo()->IsAlive())
		{
			return;
		}
		m_actionControl->AddAction(this, new AttackAction(target));
	}

	void ActorProp::ChangeAvatar( Tools::AvatarData *avatar )
	{
		ActorEventChangeAvatar event(avatar);
		NotifyChange(&event);
	}

	void ActorProp::ChangeEquip( ENEquipType::Decl type, const char *avatarFile )
	{
		ActorEventChangeEquip event(type, avatarFile);
		NotifyChange(&event);
	}

	void ActorProp::Tick( float dt )
	{
		m_actionControl->Tick(this, dt);
	}

	void ActorProp::SendAttack( int targetID )
	{
		WorldManager::Instance()->GetClient()->Attack(targetID);
	}

	void ActorProp::Dead( void )
	{
		GetBattleInfo()->SetAlive(false);
		m_actionControl->AddAction(this, new DeadAction);
	}

	void ActorProp::BeAttacked( int hpChanged )
	{
		GetBattleInfo()->SetHP(GetBattleInfo()->GetHP() + hpChanged);
		ActorEventBeAttacked event(hpChanged);
		NotifyChange(&event);
	}

	void ActorProp::AttachUI( GUI::UIProperty *uiProp )
	{
		uiProp->Detach();
		AttachObserver(uiProp);
		ActorEventAttachUI event(this);
		NotifyChange(&event);
	}

}
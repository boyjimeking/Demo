//
//  ActorEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_ActorEvents_h
#define Demo_ActorEvents_h

#include "Base/INotifyEvent.h"
#include "cocoa/CCGeometry.h"
#include "Base/GlobalDef.h"

namespace Tools
{
	class AvatarData;
}

namespace Game
{
	struct ENActorEvent
	{
		enum
		{
			enNone,
			enCreate,
			enRelease,
			enChangePos,
			enStop,
			enAttack,
			enChangeAvatar,
			enChangeEquip,
			enDead,
		};
	};

	struct ActorEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enCreate; }

		ActorEventCreate(ENActorType::Decl type);
		ENActorType::Decl GetType(void) const { return m_type; }
	private:
		ENActorType::Decl m_type;
	};

	struct ActorEventRelease
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enRelease; }
	};

	struct ActorEventChangePos
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enChangePos; }
		ActorEventChangePos(const cocos2d::CCPoint &worldPos);
		const cocos2d::CCPoint& GetLogicPos(void) const { return m_targetPos; };
	private:
		cocos2d::CCPoint m_targetPos;
	};

	struct ActorEventStop
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enStop; }
	};
	class ActorProp;
	struct ActorEventPlayAttack
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enAttack; }
		ActorEventPlayAttack(ActorProp *target, ActorProp *src) : m_target(target), m_src(src) {}
		ActorProp *m_target;
		ActorProp *m_src;
	};

	struct ActorEventChangeAvatar
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enChangeAvatar; }
		ActorEventChangeAvatar(Tools::AvatarData *avatar);
		Tools::AvatarData *m_avatar;
	};
	struct ActorEventChangeEquip
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enChangeEquip; }
		ActorEventChangeEquip(ENEquipType::Decl type, const char *equipFile) : m_type(type), m_equipFile(equipFile) {}
		ENEquipType::Decl m_type;
		const char *m_equipFile;
	};
	struct ActorEventDead
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENActorEvent::enDead; }
	};
}


#endif

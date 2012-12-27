//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/UI
//	created:	2012-12-27
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef UIEvents_h__
#define UIEvents_h__

#include "Base/INotifyEvent.h"

namespace GUI
{
	struct ENUIEvent
	{
		enum Decl
		{
			enError,
			enInit,
			enChangeTargetHp,
			enAttachActor,
		};
	};

	struct UIEventInit
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENUIEvent::enInit; }
	};
	struct UIEventChangeTargetHp
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENUIEvent::enChangeTargetHp; }
		UIEventChangeTargetHp(int hp) : m_hp(hp) {}
		int m_hp;
	};
	struct UIEventAttachActor
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENUIEvent::enAttachActor; }
		UIEventAttachActor(int maxHp, int hp) : m_maxHp(maxHp), m_hp(hp) {}
		int m_maxHp;
		int m_hp;
	};
}

#endif // UIEvents_h__

//
//  IPropBaseEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__IPropBaseEvents__
#define __Demo__IPropBaseEvents__

#include "INotifyEvent.h"
#include "cocoa/CCGeometry.h"

#ifndef PTM_RATIO
#define PTM_RATIO 32
#endif

namespace Game
{
	struct ENIPropBaseEvent
	{
		enum
		{
			enIPropBaseEvent = 0xffff,
			enIPropBaseEvent_UpdatePosition,
		};
	};

	class IPropBaseEvent
		:public INotifyEvent
	{
	public:
		virtual int GetNotifyEventType(void) const { return ENIPropBaseEvent::enIPropBaseEvent_UpdatePosition; }
		IPropBaseEvent(const cocos2d::CCPoint &pos) : m_position(pos) {}
	
		const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
	private:
		const cocos2d::CCPoint &m_position;
	};
}

#endif /* defined(__Demo__IPropBaseEvents__) */

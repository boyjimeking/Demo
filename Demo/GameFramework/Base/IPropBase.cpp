//
//  IPropBase.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#include "IPropBase.h"
#include "IPropBaseEvents.h"

namespace Game
{
	IPropBase::IPropBase(void)
	:m_position(cocos2d::CCPointZero)
	{

	}
	IPropBase::~IPropBase(void)
	{

	}
	void IPropBase::SetPosition(const cocos2d::CCPoint &pos)
	{
		m_position = pos;

		IPropBaseEvent event(m_position);
		NotifyChange(&event);
	}
}
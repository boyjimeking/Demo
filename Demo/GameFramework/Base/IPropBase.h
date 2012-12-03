//
//  IPropBase.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__IPropBase__
#define __Demo__IPropBase__

#include "INotifier.h"
#include "cocoa/CCGeometry.h"

namespace Game
{
	class IPropBase
		:public INotifier
	{
	public:
		IPropBase(void);
		~IPropBase(void);
		const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
		virtual void SetPosition(const cocos2d::CCPoint &pos);
	protected:
		cocos2d::CCPoint m_position;
	};
}

#endif /* defined(__Demo__IPropBase__) */

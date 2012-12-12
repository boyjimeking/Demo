//
//  UIControlEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-12.
//
//

#ifndef __Demo__UIControlEvents__
#define __Demo__UIControlEvents__

#include "Base/INotifyEvent.h"

namespace GUI
{
	struct ENUIControlEvent
	{
		enum
		{
			enNone,
			enInit,
		};
	};

	struct UIControlEventInit
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENUIControlEvent::enInit; }
	};
}

#endif /* defined(__Demo__UIControlEvents__) */

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
			enCreateWindow,
		};
	};

	struct UIControlEventInit
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENUIControlEvent::enInit; }
	};

	class UIWindow;
	struct UIControlEventCreateWindow
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENUIControlEvent::enCreateWindow; }
		UIControlEventCreateWindow(UIWindow *window) : m_window(window) {}
		UIWindow *m_window;
	};
}

#endif /* defined(__Demo__UIControlEvents__) */

//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/UI/UIControl.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UIControl_h__
#define UIControl_h__

#include "../Base/INotifier.h"
#include <map>
#include <string>
#include "UIControlEvents.h"
#include "cocoa/CCGeometry.h"

USING_NS_CC;

namespace GUI
{
	class UIProperty;
	class UIControl
		:public INotifier
	{
	public:
		_Decl_Notifier(UIControl);
		UIControl(void);
		virtual ~UIControl(void);

		void Init(void);

		template<typename Prop, typename Win>
		Prop* CreateUI(const std::string &windowName)
		{
			Prop *uiProp = new Prop;
			Win *window = new Win;
			uiProp->AttachObserver(window);
			uiProp->Init(windowName);

			UIControlEventCreateWindow event(window);
			NotifyChange(&event);

			m_uiMap.insert(std::make_pair(windowName, uiProp));
			return uiProp;
		}

		UIProperty* GetWindow(const std::string &windowName);

		const CCSize& GetSize(void) const { return m_size; }
	protected:
	private:
		typedef std::map<std::string, UIProperty*> UIMap;
		UIMap m_uiMap;
		CCSize m_size;
	};
}

#endif // UIControl_h__

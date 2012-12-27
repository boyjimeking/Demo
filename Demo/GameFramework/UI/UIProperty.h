//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/UI/UIProperty.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UIProperty_h__
#define UIProperty_h__

#include "../Base/INotifier.h"
#include <string>
#include "Base/IObserver.h"

namespace GUI
{
	class UIProperty
		:public INotifier
		,public IObserver
	{
	public:
		_Decl_Notifier(UIProperty);
		UIProperty(void);
		virtual ~UIProperty(void);
		virtual void Init(const std::string &windowName);
		const std::string& GetWindowName(void) const { return m_windowName; }
	protected:
	private:
		std::string m_windowName;
	};
}

#endif // UIProperty_h__

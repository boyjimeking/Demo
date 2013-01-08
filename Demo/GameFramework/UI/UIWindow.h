//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/UI/UIWindow.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UIWindow_h__
#define UIWindow_h__

#include "../Base/IObserver.h"
#include "base_nodes/CCNode.h"

USING_NS_CC;

namespace GUI
{
	class UIWindow
		:public IObserver
	{
	public:
		UIWindow(void);
		~UIWindow(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
		virtual CCNode* GetWindow(void) const = 0;
	protected:
	private:
	};
}

#endif // UIWindow_h__

//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/UI/UIWindow.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UIWindow_h__
#define UIWindow_h__

#include "../Base/IObserver.h"

namespace GUI
{
	class UIWindow
		:public IObserver
	{
	public:
		UIWindow(void);
		~UIWindow(void);

		virtual void OnNotifyChange( const INotifier *notify, const INotifyEvent *event );

	protected:
	private:
	};
}

#endif // UIWindow_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/UI
//	created:	2012-12-27
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef UITargetWindow_h__
#define UITargetWindow_h__

#include "UIWindow.h"
#include "extensions/ExtensionMacros.h"
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"

USING_NS_CC_EXT;

namespace GUI
{
	class UITargetWindow
		:public UIWindow
	{
	public:
		UITargetWindow(void);
		virtual ~UITargetWindow(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

		virtual cocos2d::CCNode* GetWindow( void ) const;

	protected:

	private:
		CCControlSlider *m_slider;
	};
}

#endif // UITargetWindow_h__

#include "UIControl.h"
#include "UIControlEvents.h"
#include "UIProperty.h"
#include "UIWindow.h"
#include "CCDirector.h"

namespace GUI
{
	UIControl::UIControl(void)
	{

	}
	UIControl::~UIControl(void)
	{

	}
	void UIControl::Init(void)
	{
		m_size = CCDirector::sharedDirector()->getWinSize();
		UIControlEventInit event;
		NotifyChange(&event);
	}

	UIProperty* UIControl::GetWindow( const std::string &windowName )
	{
		UIMap::iterator it = m_uiMap.find(windowName);
		if (m_uiMap.end() != it)
		{
			return it->second;
		}
		else
		{
			return NULL;
		}
	}

	void UIControl::registerScriptTouchHandler( int nHandler, bool bIsMultiTouches /*= false*/, int nPriority /*= INT_MIN*/, bool bSwallowsTouches /*= false*/ )
	{

	}

}
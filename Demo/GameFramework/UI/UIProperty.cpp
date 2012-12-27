#include "UIProperty.h"
#include "UIEvents.h"

namespace GUI
{
	UIProperty::UIProperty(void)
	{

	}
	UIProperty::~UIProperty(void)
	{

	}

	void UIProperty::Init(const std::string &windowName)
	{
		m_windowName = windowName;
		UIEventInit event;
		NotifyChange(&event);
	}

}
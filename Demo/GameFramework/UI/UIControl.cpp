#include "UIControl.h"
#include "UIControlEvents.h"

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
		UIControlEventInit event;
		NotifyChange(&event);
	}
}
#include "UITargetWindow.h"
#include "Base/INotifyEvent.h"
#include "UIEvents.h"
#include "../CCCommon.h"
#include "WorldManager.h"
#include "UIControl.h"

namespace GUI
{
	UITargetWindow::UITargetWindow(void)
		:m_slider(NULL)
	{

	}

	UITargetWindow::~UITargetWindow(void)
	{

	}

	void UITargetWindow::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
		case ENUIEvent::enInit:
			{
				m_slider = CCControlSlider::create("LifeBack.png", "LifeFront.png", "Empty.png");
				m_slider->setTouchEnabled(false);
				m_slider->setScaleX(5.0f);
				//const CCSize &size = Game::WorldManager::Instance()->GetUIControl()->GetSize();
				//m_slider->setPosition(CCPointMake(size.width / 2.0f, size.height - 30.0f));
			}
			break;
		case ENUIEvent::enAttachActor:
			{
				const UIEventAttachActor* targetEvent = reinterpret_cast<const UIEventAttachActor*>(event);
				m_slider->setMaximumValue(targetEvent->m_maxHp);
				m_slider->setValue(targetEvent->m_hp);
				CCLog("enAttachActor");
			}
			break;
		case ENUIEvent::enChangeTargetHp:
			{
				const UIEventChangeTargetHp* targetEvent = reinterpret_cast<const UIEventChangeTargetHp*>(event);
				m_slider->setValue(targetEvent->m_hp);
				CCLog("enChangeTargetHp");
			}
			break;
		default:
			UIWindow::OnNotifyChange(notify, event);
			break;
		}
	}

	CCNode* UITargetWindow::GetWindow( void ) const
	{
		return m_slider;
	}

}
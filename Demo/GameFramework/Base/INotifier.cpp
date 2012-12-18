#include "INotifier.h"
#include "IObserver.h"
//#include <typeinfo>
//#include "platform/CCCommon.h"
//#include "INotifyEvent.h"

INotifier::INotifier(void)
{

}
INotifier::~INotifier(void)
{

}

void INotifier::NotifyChange( const INotifyEvent *event )
{
	if (INotifier::NotifyMode)
	{
		m_observer->OnNotifyChange(this, event);
	}
	else
	{
		//cocos2d::CCLog("--Notify--\n\t%s\n\t%s\n\t%s", typeid(*this).name(), typeid(*m_observer).name(), typeid(*event).name());
	}
}

void INotifier::AttachObserver( IObserver *observer )
{
	m_observer = observer;
}

bool INotifier::NotifyMode = true;

#include "INotifier.h"
#include "IObserver.h"

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
}

void INotifier::AttachObserver( IObserver *observer )
{
	m_observer = observer;
}

bool INotifier::NotifyMode = true;;

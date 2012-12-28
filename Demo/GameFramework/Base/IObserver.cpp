#include "IObserver.h"
#include "INotifier.h"
#include <stddef.h>

IObserver::IObserver(void)
	:m_notifier(NULL)
{
	
}
IObserver::~IObserver(void)
{
	
}

void IObserver::Detach( void )
{
	if (NULL != m_notifier)
	{
		m_notifier->DetachObserver(this);
		m_notifier = NULL;
	}
}

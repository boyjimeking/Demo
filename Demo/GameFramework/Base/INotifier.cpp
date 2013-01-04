#include "INotifier.h"
#include "IObserver.h"
//#include <typeinfo>
//#include "platform/CCCommon.h"
//#include "INotifyEvent.h"
#include <algorithm>

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
		for (unsigned int index = 0; index < m_observerList.size(); ++index)
		{
			m_observerList[index]->OnNotifyChange(this, event);
		}
	}
	else
	{
		//cocos2d::CCLog("--Notify--\n\t%s\n\t%s\n\t%s", typeid(*this).name(), typeid(*m_observer).name(), typeid(*event).name());
	}
}

void INotifier::AttachObserver( IObserver *observer )
{
	ObserverList::iterator it = std::find(m_observerList.begin(), m_observerList.end(), observer);
	if (m_observerList.end() != it)
	{
		return;
	}
	m_observerList.push_back(observer);
	observer->SetNotifier(this);
}

void INotifier::DetachObserver( IObserver *observer )
{
	ObserverList::iterator it = std::find(m_observerList.begin(), m_observerList.end(), observer);
	if (m_observerList.end() == it)
	{
		return;
	}
	m_observerList.erase(it);
	observer->SetNotifier(NULL);
}

bool INotifier::NotifyMode = true;

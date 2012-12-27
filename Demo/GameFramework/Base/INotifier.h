//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/Base/INotifier.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef INotifier_h__
#define INotifier_h__
#include <vector>
#include "INotifierType.h"

class IObserver;
struct INotifyEvent;

class INotifier
{
public:
	virtual ENNotifierType::Decl GetType(void) const = 0;

	static bool NotifyMode;
	INotifier(void);
	virtual ~INotifier(void);

	void NotifyChange(const INotifyEvent *event);
	void AttachObserver(IObserver *observer);
	void DetachObserver(IObserver *observer);
protected:
	typedef std::vector<IObserver*> ObserverList;
	ObserverList m_observerList;
private:
};

#define _Decl_Notifier(className)\
	virtual ENNotifierType::Decl GetType(void) const { return GetNotifierType(className); };

#endif // INotifier_h__

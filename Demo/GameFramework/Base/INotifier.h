//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/Base/INotifier.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef INotifier_h__
#define INotifier_h__

class IObserver;
struct INotifyEvent;

class INotifier
{
public:
	INotifier(void);
	virtual ~INotifier(void);

	void NotifyChange(const INotifyEvent *event);
	void AttachObserver(IObserver *observer);
protected:
	IObserver *m_observer;
private:
};

#endif // INotifier_h__

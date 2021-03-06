//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/Base/IObserver.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef IObserver_h__
#define IObserver_h__

class INotifier;
struct INotifyEvent;

class IObserver
{
public:
	IObserver(void);
	virtual ~IObserver(void);
	virtual void OnNotifyChange(INotifier *notify, const INotifyEvent *event) = 0;

	void Detach(void);
	INotifier* GetNotifier(void) const { return m_notifier; }
	void SetNotifier(INotifier *val) { m_notifier = val; }
protected:
private:
	INotifier *m_notifier;
};

#endif // IObserver_h__

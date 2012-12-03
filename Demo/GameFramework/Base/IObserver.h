//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/Base/IObserver.h
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
	virtual void OnNotifyChange(const INotifier *notify, const INotifyEvent *event) = 0;
protected:
private:
};

#endif // IObserver_h__

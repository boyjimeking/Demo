//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/Base/INotifyEvent.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef INotifyEvent_h__
#define INotifyEvent_h__

#include "stddef.h"

struct INotifyEvent
{
	virtual int GetNotifyEventType(void) const = 0;
	virtual ~INotifyEvent(void);
};

#endif // INotifyEvent_h__

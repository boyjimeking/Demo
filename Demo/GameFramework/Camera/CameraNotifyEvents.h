//
//  CameraNotifyEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#ifndef Demo_CameraNotifyEvents_h
#define Demo_CameraNotifyEvents_h

#include "Base/INotifyEvent.h"
#include "cocoa/CCGeometry.h"

struct ENCameraEvent
{
	enum
	{
		enNone,
		enCameraEvent_PosChanged,
	};
};

struct CameraPosChanged
	:public INotifyEvent
{
	CameraPosChanged(const cocos2d::CCPoint &pos) : m_pos(pos) {}
	virtual int GetNotifyEventType(void) const { return ENCameraEvent::enCameraEvent_PosChanged; }
	const cocos2d::CCPoint& GetCameraPosition(void) const { return m_pos; }
private:
	const cocos2d::CCPoint &m_pos;
};

#endif

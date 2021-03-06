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

namespace Game
{
	struct ENCameraEvent
	{
		enum
		{
			enNone,
			enPosChanged,
			enScaleChanged,
			enShake,
			enReset,
		};
	};

	struct CameraPosChanged
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENCameraEvent::enPosChanged; }

		CameraPosChanged(const cocos2d::CCPoint &pos);
		const cocos2d::CCPoint& GetCameraPosition(void) const { return m_pos; }
	private:
		const cocos2d::CCPoint &m_pos;
	};
	struct CameraScaleChanged
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENCameraEvent::enScaleChanged; }
		CameraScaleChanged(float scale);
		float GetScale(void) const { return m_scale; }
	private:
		float m_scale;
	};
	struct CameraShake
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENCameraEvent::enShake; }
	};
	struct CameraReset
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENCameraEvent::enReset; }

		CameraReset(const cocos2d::CCPoint &pos);
		const cocos2d::CCPoint& GetCameraPosition(void) const { return m_pos; }
	private:
		const cocos2d::CCPoint &m_pos;
	};
}


#endif

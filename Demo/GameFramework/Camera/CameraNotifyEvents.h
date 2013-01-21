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

namespace cocos2d
{
	class CCLayer;
}

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
			enChangeMoveScale,
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
	struct CameraChangeLayerMoveScale
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENCameraEvent::enChangeMoveScale; }

		CameraChangeLayerMoveScale(cocos2d::CCLayer *layer, float moveScale) : m_layer(layer), m_moveScale(moveScale) {}

		cocos2d::CCLayer *m_layer;
		float m_moveScale;
	};
}


#endif

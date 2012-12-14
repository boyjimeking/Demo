//
//  GridEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__GridEvents__
#define __Demo__GridEvents__

#include "../Base/INotifyEvent.h"

namespace Game
{
	struct ENGridEventType
	{
		enum
		{
			enError,
			enLoad,
			enRelease,
		};
	};

	struct GridEvent_Load
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENGridEventType::enLoad; }

		GridEvent_Load(const char *imageName, float posX, float posY);

		const char* GetImageName(void) const { return m_imageName; }
		float GetPosX(void) const { return m_posX; }
		float GetPosY(void) const { return m_posY; }
	private:
		const char *m_imageName;
		float m_posX;
		float m_posY;
	};
	struct GridEvent_Release
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENGridEventType::enRelease; }
	};
}

#endif /* defined(__Demo__GridEvents__) */

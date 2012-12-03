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
			enGridEvent_Load,
		};
	};

	struct GridEvent_Load
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENGridEventType::enGridEvent_Load; }

		GridEvent_Load(const char *imageName, int width, int height, int posX, int posY);

		const char* GetImageName(void) const { return m_imageName; }
		int GetWidth(void) const { return m_width; }
		int GetHeight(void) const { return m_height; }
		int GetPosX(void) const { return m_posX; }
		int GetPosY(void) const { return m_posY; }
	private:
		const char *m_imageName;
		int m_width;
		int m_height;
		int m_posX;
		int m_posY;
	};
}

#endif /* defined(__Demo__GridEvents__) */

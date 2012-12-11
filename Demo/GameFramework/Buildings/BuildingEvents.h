//
//  BuildingEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-11.
//
//

#ifndef __Demo__BuildingEvents__
#define __Demo__BuildingEvents__

#include "Base/INotifyEvent.h"
#include <string>

namespace Game
{
	struct ENBuildingEvent
	{
		enum
		{
			enNone,
			enBuildingEvent_Create,
		};
	};

	struct BuildingEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENBuildingEvent::enBuildingEvent_Create; }

		BuildingEventCreate(const std::string &imageName) : m_imageName(imageName) {}

		const std::string& GetImageName(void) { return m_imageName; }
	private:
		const std::string &m_imageName;
	};
}

#endif /* defined(__Demo__BuildingEvents__) */

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
			enCreate,
			enInitLayer,
		};
	};

	struct BuildingEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENBuildingEvent::enCreate; }

		BuildingEventCreate(const std::string &imageName, float x, float y) : m_imageName(imageName), m_x(x), m_y(y) {}

		const std::string& GetImageName(void) const { return m_imageName; }
		float GetX(void) const { return m_x; }
		float GetY(void) const { return m_y; }
	private:
		const std::string &m_imageName;
		float m_x;
		float m_y;
	};

	class BuildingEntity;
	struct BuildingEventInitLayer
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENBuildingEvent::enInitLayer; }

		BuildingEventInitLayer(int size) : m_size(size), m_entity(new BuildingEntity*[size]) {}
		~BuildingEventInitLayer(void) { delete[] m_entity; }

		int m_size;
		BuildingEntity **m_entity;
	};
}

#endif /* defined(__Demo__BuildingEvents__) */

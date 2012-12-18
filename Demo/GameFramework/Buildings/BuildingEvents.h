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
#include "Tools/Scene.h"

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

	class BuildingProp;
	struct BuildingEventInitLayer
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENBuildingEvent::enInitLayer; }

		BuildingEventInitLayer(const Tools::Scene::ImageNameList &imageName, int size) : m_imageNameList(imageName), m_size(size), m_entity(new BuildingProp*[size]) {}
		~BuildingEventInitLayer(void) { delete[] m_entity; }

		const Tools::Scene::ImageNameList &m_imageNameList;
		int m_size;
		BuildingProp **m_entity;
	};
}

#endif /* defined(__Demo__BuildingEvents__) */

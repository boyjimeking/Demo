//
//  SceneObjectEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-11.
//
//

#ifndef __Demo__SceneObjectEvents__
#define __Demo__SceneObjectEvents__

#include "Base/INotifyEvent.h"
#include <string>
#include "Tools/Scene.h"

namespace Game
{
	struct ENSceneObjectEvent
	{
		enum
		{
			enNone,
			enCreate,
			enInitLayer,
		};
	};

	struct SceneObjectEventCreate
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENSceneObjectEvent::enCreate; }

		SceneObjectEventCreate(const std::string &imageName, float x, float y) : m_imageName(imageName), m_x(x), m_y(y) {}

		const std::string& GetImageName(void) const { return m_imageName; }
		float GetX(void) const { return m_x; }
		float GetY(void) const { return m_y; }
	private:
		const std::string &m_imageName;
		float m_x;
		float m_y;
	};

	class SceneObjectProp;
	struct SceneObjectEventInitLayer
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENSceneObjectEvent::enInitLayer; }

		SceneObjectEventInitLayer(const Tools::Scene::ImageNameList &imageName, int size) : m_imageNameList(imageName), m_size(size), m_entity(new SceneObjectProp*[size]) {}
		~SceneObjectEventInitLayer(void) { delete[] m_entity; }

		const Tools::Scene::ImageNameList &m_imageNameList;
		int m_size;
		SceneObjectProp **m_entity;
	};
}

#endif /* defined(__Demo__SceneObjectEvents__) */

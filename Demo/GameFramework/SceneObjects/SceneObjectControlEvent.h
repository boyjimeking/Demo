//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/SceneObjects
//	created:	2012-12-18
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectControlEvent_h__
#define SceneObjectControlEvent_h__

#include "Base/INotifyEvent.h"
#include "SceneObjectEntity.h"

namespace Game
{
	struct ENSceneObjectControl
	{
		enum
		{
			enNone,
			enAddObject,
			enAddObjectImage,
			enRemoveObjectImage,
		};
	};

	struct SceneObjectControlEventAddObject
		:public INotifyEvent
	{
		virtual int GetNotifyEventType( void ) const { return ENSceneObjectControl::enAddObject; }

		SceneObjectControlEventAddObject(SceneObjectEntity *entity, const char *layerName);

		SceneObjectEntity *m_entity;
		const char *m_layerName;
	};

	struct SceneObjectEventAddObjectImage
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENSceneObjectControl::enAddObjectImage; }

		SceneObjectEventAddObjectImage(const std::string &imageName);

		const std::string &m_imageName;
	};

	struct SceneObjectEventRemoveObjectImage
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENSceneObjectControl::enRemoveObjectImage; }

		SceneObjectEventRemoveObjectImage(const std::string &imageName);

		const std::string &m_imageName;
	};
}

#endif // SceneObjectControlEvent_h__

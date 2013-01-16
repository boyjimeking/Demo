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
#include "../Tools/Scene.h"
#include "cocoa/CCGeometry.h"
#include "SceneObjectEntity.h"

namespace Game
{
	struct ENSceneObjectEvent
	{
		enum
		{
			enNone,
			enInitObject,
			enRemoveObject,
		};
	};

	class SceneObjectProp;
	struct SceneObjectEventInit
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENSceneObjectEvent::enInitObject; }
		SceneObjectEventInit(Tools::ObjectInfo *objInfo);

		Tools::ObjectInfo *m_objInfo;
	};

	struct SceneObjectEventRemove
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENSceneObjectEvent::enRemoveObject; }
	};

}

#endif /* defined(__Demo__SceneObjectEvents__) */

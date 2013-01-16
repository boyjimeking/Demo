#include "SceneObjectProp.h"
#include "SceneObjectEntity.h"
#include "../Tools/Scene.h"
#include "SceneObjectEvents.h"

namespace Game
{
	SceneObjectProp::SceneObjectProp(void)
	{

	}
	SceneObjectProp::~SceneObjectProp(void)
	{

	}

	void SceneObjectProp::Init( Tools::ObjectInfo *objInfo )
	{
		m_id = objInfo->m_id;
		m_position = cocos2d::CCPointMake(objInfo->m_x, objInfo->m_y);
		m_size = cocos2d::CCSizeMake(objInfo->width, objInfo->height);
		SceneObjectEventInit event(objInfo);
		NotifyChange(&event);
	}

	void SceneObjectProp::Remove( void )
	{
		SceneObjectEventRemove event;
		NotifyChange(&event);
	}

}
#include "SceneObjectProp.h"
#include "SceneObjectEntity.h"
#include "Tools/Scene.h"
#include "SceneObjectEvents.h"

namespace Game
{
	SceneObjectProp* SceneObjectProp::Create(const Tools::ObjectInfo *sceneInfo)
	{
		SceneObjectProp *prop = new SceneObjectProp();
		prop->Init(sceneInfo);
		return prop;
	}
	SceneObjectProp::SceneObjectProp(void)
	{

	}
	SceneObjectProp::~SceneObjectProp(void)
	{

	}
	void SceneObjectProp::Init(const Tools::ObjectInfo *sceneInfo)
	{
		m_position = cocos2d::CCPointMake(sceneInfo->m_x, sceneInfo->m_y);
		m_imageName = sceneInfo->m_imageName;
	}
	SceneObjectEntity* SceneObjectProp::CreateEntity(void)
	{
		SceneObjectEntity *entity = SceneObjectEntity::Create();
		AttachObserver(entity);

		SceneObjectEventCreate event(m_imageName, m_position.x, m_position.y);
		NotifyChange(&event);
		return entity;
	}
}
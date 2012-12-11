#include "BuildingProp.h"
#include "BuildingEntity.h"
#include "Tools/Scene.h"
#include "BuildingEvents.h"

namespace Game
{
	BuildingProp* BuildingProp::Create(const Tools::SceneInfo *sceneInfo)
	{
		BuildingProp *prop = new BuildingProp();
		prop->Init(sceneInfo);
		return prop;
	}
	BuildingProp::BuildingProp(void)
	{

	}
	BuildingProp::~BuildingProp(void)
	{

	}
	void BuildingProp::Init(const Tools::SceneInfo *sceneInfo)
	{
		m_position = cocos2d::CCPointMake(sceneInfo->m_x, sceneInfo->m_y);
		m_imageName = sceneInfo->m_imageName;
	}
	BuildingEntity* BuildingProp::CreateEntity(void)
	{
		BuildingEntity *entity = BuildingEntity::Create();
		AttachObserver(entity);

		BuildingEventCreate event(m_imageName);
		NotifyChange(&event);
		return entity;
	}
}
#include "TerrainProp.h"
#include "TerrainEvent.h"
#include "GridProp.h"
#include "GridEntity.h"
#include "WorldManager.h"
#include "support/CCPointExtension.h"
#include "Tools/Scene.h"
#include "sprite_nodes/CCSpriteFrameCache.h"

namespace Game
{
	TerrainProp::TerrainProp(void)
	{

	}
	TerrainProp::~TerrainProp(void)
	{
		Clear();
	}

	void TerrainProp::Init(const Tools::Scene *sceneFile)
	{
		Clear();
		typedef Tools::Scene::TerrainInfoList InfoList;
		const InfoList &list = sceneFile->GetTerrainList();
		for (InfoList::const_iterator it = list.begin(); list.end() != it; ++it)
		{
			Tools::TerrainInfo *info = (*it);
			AddTerrainGrid(info->m_id, info->m_imageName, info->m_x, info->m_y, info->m_width, info->m_height);
		}
	}

	void TerrainProp::AddTerrainGrid( int id, const char *imageName, float x, float y, float width, float height )
	{
		GridProp *prop = new GridProp;
		GridEntity *entity = new GridEntity;

		TerrainEvent_AddTerrain event(entity);
		NotifyChange(&event);

		prop->AttachObserver(entity);
		prop->Init(id, imageName, x, y, width, height);
		m_gridList.push_back(prop);
	}

	void TerrainProp::ChangeTerrainGrid( int id, const char *imageName, float x, float y, float width, float height )
	{
		GridProp *prop = LookupGrid(id);
		prop->Init(id, imageName, x, y, width, height);
	}

	void TerrainProp::RemoveTerrainGrid( int id )
	{
		for (GridList::iterator it = m_gridList.begin(); m_gridList.end() != it; ++it)
		{
			if ((*it)->GetID() == id)
			{
				GridProp *prop = *it;
				m_gridList.erase(it);
				prop->Remove();
				delete prop;
				break;
			}
		}
	}

	GridProp* TerrainProp::LookupGrid( int id )
	{
		for (GridList::iterator it = m_gridList.begin(); m_gridList.end() != it; ++it)
		{
			if ((*it)->GetID() == id)
			{
				return *it;
			}
		}
		return NULL;
	}

	void TerrainProp::Clear( void )
	{
		for (GridList::iterator it = m_gridList.begin(); m_gridList.end() != it; ++it)
		{
			GridProp *prop = *it;
			prop->Remove();
			delete prop;
		}
		m_gridList.clear();
	}

}

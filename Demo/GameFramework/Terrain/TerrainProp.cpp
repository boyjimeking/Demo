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
		const Tools::Scene::TerrainInfoList &list = sceneFile->GetTerrainList();
		TerrainEvent_LoadTerrain event(list.size());
		m_gridList.resize(list.size());
		int currentIndex = 0;
		for (Tools::Scene::TerrainInfoList::const_iterator it = list.begin(); it != list.end(); ++it, ++currentIndex)
        {
        	m_gridList[currentIndex] = new GridProp;
			event.m_entityArray[currentIndex] = new GridEntity;
			m_gridList[currentIndex]->AttachObserver(event.m_entityArray[currentIndex]);
			m_gridList[currentIndex]->Load((*it)->m_imageName, (*it)->m_x, (*it)->m_y);
        }

		NotifyChange(&event);
	}

	void TerrainProp::Clear( void )
	{
		for (int index = 0; index < m_gridList.size() ; ++index)
		{
			delete m_gridList[index];
		}
		m_gridList.clear();
	}

	bool TerrainProp::AddGrid(GridProp *grid)
	{
		if (m_gridList.end() != std::find(m_gridList.begin(), m_gridList.end(), grid))
		{
			return false;
		}
		m_gridList.push_back(grid);
		return true;
	}

	void TerrainProp::RemoveGrid( GridProp *grid )
	{
		for (GridList::iterator it = m_gridList.begin(); m_gridList.end() != it; ++it)
		{
			if (*it == grid)
			{
				grid->Release();
				delete *it;
				m_gridList.erase(it);
				break;
			}
		}
	}

}

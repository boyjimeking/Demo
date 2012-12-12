#include "TerrainProp.h"
#include "TerrainEvent.h"
#include "GridProp.h"
#include "GridEntity.h"
#include "WorldManager.h"
#include "support/CCPointExtension.h"
#include "Tools/Scene.h"

namespace Game
{
	TerrainProp::TerrainProp(void)
	:m_gridList(NULL)
	{

	}
	TerrainProp::~TerrainProp(void)
	{
		if (NULL != m_gridList)
		{
			delete[] m_gridList;
		}
	}

	void TerrainProp::Init(const Tools::Scene *sceneFile)
	{
		if (NULL != m_gridList)
		{
			delete[] m_gridList;
		}

		const Tools::Scene::TerrainInfoList &list = sceneFile->GetTerrainList();
		GridEntity **entityArray = new GridEntity*[list.size()];
		m_gridList = new GridProp*[list.size()];
		int currentIndex = 0;
		for (Tools::Scene::TerrainInfoList::const_iterator it = list.begin(); it != list.end(); ++it, ++currentIndex)
        {
        	m_gridList[currentIndex] = new GridProp;
			entityArray[currentIndex] = new GridEntity;
			m_gridList[currentIndex]->AttachObserver(entityArray[currentIndex]);
			m_gridList[currentIndex]->Load(it->m_imageName, it->m_x, it->m_y );
        }

		TerrainEvent_LoadTerrain event(entityArray, list.size());
		NotifyChange(&event);
		delete[] entityArray;
	}

}
#include "TerrainProp.h"
#include "TerrainEvent.h"
#include "GridProp.h"
#include "GridEntity.h"
#include "WorldManager.h"
#include "support/CCPointExtension.h"

namespace Game
{
	TerrainProp::TerrainProp(void)
	:m_gridList(NULL)
	,m_width(4)
	,m_height(3)
	,m_terrainName(NULL)
	{

	}
	TerrainProp::~TerrainProp(void)
	{
		if (NULL != m_gridList)
		{
			delete[] m_gridList;
		}
	}

	void TerrainProp::Load(const char *mapName, const char *imageName)
	{
		if (NULL != m_gridList)
		{
			delete[] m_gridList;
		}
		m_terrainName = mapName;

		//测试用地图，之后需要替换为正式地图及其加载方式
		GridEntity **entityArray = new GridEntity*[m_width * m_height];
		m_gridList = new GridProp*[m_width * m_height];
		char temp[32] = {0};
		for (int index = 0; index < m_width; ++index)
		{
			for (int innerIndex = 0; innerIndex < m_height; ++innerIndex)
			{
				int currentIndex = index + innerIndex * m_width;
				m_gridList[currentIndex] = new GridProp;
				entityArray[currentIndex] = new GridEntity;
				m_gridList[currentIndex]->AttachObserver(entityArray[currentIndex]);
				sprintf(temp, "terrain_%d.png", currentIndex + 1);
				m_gridList[currentIndex]->Load(temp, index * 960, (m_height - innerIndex - 1) * 640 );
			}
		}

		TerrainEvent_LoadTerrain event(entityArray, m_width * m_height);
		NotifyChange(&event);
		delete[] entityArray;
	}

}
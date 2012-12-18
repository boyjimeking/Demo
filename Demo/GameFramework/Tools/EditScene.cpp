#include "EditScene.h"
#include <stddef.h>

namespace Tools
{
	EditScene::EditScene(void)
		:m_terrainCount(0)
		,m_objectCount(0)
	{

	}

	EditScene::~EditScene(void)
	{

	}

	void EditScene::Load( unsigned char *data, int dataLength )
	{
		Read(data, dataLength);
	}

	void EditScene::Create(float width, float height, float gridSize, int transScale)
	{
		m_width = width;
		m_height = height;
		m_gridSize = gridSize;
		if (NULL != m_grid)
		{
			delete[] m_grid;
		}
		m_gridColumn = m_width / m_gridSize;
		m_gridRow = m_height / m_gridSize;
		m_gridArrayLength = m_gridColumn * m_gridRow / 8;
		m_grid = new char[m_gridArrayLength];
		memset(m_grid, 0, m_gridArrayLength);
		m_transScale = transScale;
	}

	int EditScene::Save( unsigned char *data, int dataLength )
	{
		return Write(data, dataLength);
	}

	void EditScene::SetSceneName( const char *sceneName )
	{
		strcpy(m_sceneName, sceneName);
	}

	void EditScene::SetGridPassState( int x, int y, bool isPass )
	{
		int pos = y * m_gridColumn + x;
		int index = pos / 8;
		int charPos = pos % 8;
		if (isPass)
		{
			m_grid[index] |= (1 << charPos);
		}
		else
		{
			m_grid[index] &= (1 << charPos);
		}
	}

	void EditScene::AddObjectImage( const char *imageName )
	{
		m_imageName.push_back(std::string(imageName));
	}

	void EditScene::RemoveObjectImage( const char *imageName )
	{
		for (ImageNameList::iterator it = m_imageName.begin(); m_imageName.end() != it; ++it)
		{
			if (0 == (*it).compare(imageName))
			{
				m_imageName.erase(it);
				break;
			}
		}
	}

	int EditScene::AddObject( const char *image, float x, float y, float width, float height )
	{
		ObjectInfo *info = new ObjectInfo;
		info->m_id = ++m_objectCount;
		strcpy(info->m_imageName, image);
		info->m_x = x;
		info->m_y = y;
		info->m_width = width;
		info->m_height = height;
		m_objectInfoList.push_back(info);
		return info->m_id;
	}

	void EditScene::ChangeObject( int id, const char *image, float x, float y, float width, float height )
	{
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				ObjectInfo *info = (*it);
				strcpy(info->m_imageName, image);
				info->m_x = x;
				info->m_y = y;
				info->m_width = width;
				info->m_height = height;
				break;
			}
		}
	}

	void EditScene::RemoveObject( int id )
	{
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				ObjectInfo *info = (*it);
				m_objectInfoList.erase(it);
				delete info;
				break;
			}
		}
	}

	int EditScene::AddTerrain( const char *image, float x, float y, float width, float height )
	{
		TerrainInfo *info = new TerrainInfo;
		info->m_id = ++m_terrainCount;
		strcpy(info->m_imageName, image);
		info->m_x = x;
		info->m_y = y;
		info->m_width = width;
		info->m_height = height;
		m_terrainInfoList.push_back(info);
		return info->m_id;
	}

	void EditScene::ChangeTerrain( int id, const char *image, float x, float y, float width, float height )
	{
		for (ObjectInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				TerrainInfo *info = (*it);
				strcpy(info->m_imageName, image);
				info->m_x = x;
				info->m_y = y;
				info->m_width = width;
				info->m_height = height;
				break;
			}
		}
	}

	void EditScene::RemoveTerrain(int id)
	{
		for (ObjectInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				TerrainInfo *info = (*it);
				m_terrainInfoList.erase(it);
				delete info;
				break;
			}
		}
	}
}
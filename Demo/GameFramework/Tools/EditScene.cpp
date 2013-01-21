#include "EditScene.h"
#include "WorldManager.h"
#include "SceneObjects/SceneObjectsControl.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "Terrain/TerrainProp.h"
#include "SceneInfo.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "Camera/CameraNotifyEvents.h"
#include "Camera/Camera.h"

#ifndef max
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#endif // !max
#ifndef min
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif // !min


namespace Tools
{
	struct EditObjectInfo
		:public ObjectInfo
	{

	};
	EditScene::EditScene(void)
		:m_terrainCount(0)
		,m_objectCount(0)
	{

	}

	EditScene::~EditScene(void)
	{
		Clear();
		if (NULL != m_grid)
		{
			delete[] m_grid;
			m_grid = NULL;
			m_gridArrayLength = 0;
		}
	}

	void EditScene::Load( unsigned char *data, int dataLength )
	{
		Clear();
		Read(data, dataLength);
		m_objectCount = 0;
		m_terrainCount = 0;
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			ObjectInfo *info = (*it);
			m_objectCount = max(info->m_id, m_objectCount);
		}
		for (ObjectInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			TerrainInfo *info = (*it);
			m_terrainCount = max(info->m_id, m_terrainCount);
		}
		Game::WorldManager::Instance()->InitScene(this);
	}

	void EditScene::Create(float width, float height, float gridSize, float transScale)
	{
		Clear();
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

		Game::WorldManager::Instance()->InitScene(this);
	}

	int EditScene::Save( unsigned char *data, int dataLength )
	{
		return Write(data, dataLength);
	}

	void EditScene::SetSceneName( const char *sceneName )
	{
		strcpy(m_sceneName, sceneName);
		Game::WorldManager::Instance()->GetSceneInfo()->SetSceneName(sceneName);
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
			m_grid[index] &= ~(1 << charPos);
		}
		Game::WorldManager::Instance()->GetSceneInfo()->SetGridPass(x, y, isPass);
	}

	void EditScene::AddObjectImage( const char *imageName )
	{
		for (ImageNameList::iterator it = m_imageName.begin(); m_imageName.end() != it; ++it)
		{
			if (0 == (*it).compare(imageName))
			{
				return;
			}
		}
		m_imageName.push_back(std::string(imageName));
		Game::WorldManager::Instance()->GetSceneObjectsControl()->AddObjectImage(imageName);
	}

	void EditScene::RemoveObjectImage( const char *imageName )
	{
		for (ImageNameList::iterator it = m_imageName.begin(); m_imageName.end() != it; ++it)
		{
			if (0 == (*it).compare(imageName))
			{
				m_imageName.erase(it);
				Game::WorldManager::Instance()->GetSceneObjectsControl()->RemoveObjectImage(imageName);
				break;
			}
		}
	}

	int EditScene::AddObject(const char *image, const char *layerName, float x, float y, float width, float height)
	{
		ObjectInfo *info = new ObjectInfo;
		info->m_id = ++m_objectCount;
		info->m_layerName = layerName;
		info->m_frame.push_back(image);
		info->m_x = x;
		info->m_y = y;
		info->width = width;
		info->height = height;
		m_objectInfoList.push_back(info);

		Game::WorldManager::Instance()->GetSceneObjectsControl()->AddSceneObject(info);

		return info->m_id;
	}

	void EditScene::ChangeObject(int id, const char *layerName, const char *image, float x, float y, float width, float height)
	{
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				ObjectInfo *info = (*it);
				info->m_layerName = layerName;
				info->m_frame.back() = image;
				info->m_x = x;
				info->m_y = y;
				info->width = width;
				info->height = height;
				Game::WorldManager::Instance()->GetSceneObjectsControl()->ChangeSceneObject(info);
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
				Game::WorldManager::Instance()->GetSceneObjectsControl()->RemoveSceneObject(id);
				break;
			}
		}
	}

	int EditScene::AddTerrain(const char *image, const char *layerName, float x, float y, float width, float height)
	{
		TerrainInfo *info = new TerrainInfo;
		info->m_id = ++m_terrainCount;
		info->m_layerName = layerName;
		info->m_frame.push_back(image);
		info->m_x = x;
		info->m_y = y;
		info->width = width;
		info->height = height;
		m_terrainInfoList.push_back(info);
		Game::WorldManager::Instance()->GetTerrainProp()->AddTerrainGrid(info->m_id, layerName, image, x, y, width, height);
		return info->m_id;
	}

	void EditScene::ChangeTerrain(int id, const char *layerName, const char *image, float x, float y, float width, float height)
	{
		for (ObjectInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				TerrainInfo *info = (*it);
				info->m_layerName = layerName;
				info->m_frame.back() = image;
				info->m_x = x;
				info->m_y = y;
				info->width = width;
				info->height = height;

				Game::WorldManager::Instance()->GetTerrainProp()->ChangeTerrainGrid(info->m_id, layerName, image, x, y, width, height);
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
				Game::WorldManager::Instance()->GetTerrainProp()->RemoveTerrainGrid(id);
				break;
			}
		}
	}

	void EditScene::Clear( void )
	{
		memset(m_grid, 0, m_gridArrayLength);
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			ObjectInfo *info = (*it);
			Game::WorldManager::Instance()->GetSceneObjectsControl()->RemoveSceneObject(info->m_id);
			delete info;
		}
		m_objectInfoList.clear();
		for (ObjectInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			TerrainInfo *info = (*it);
			Game::WorldManager::Instance()->GetTerrainProp()->RemoveTerrainGrid(info->m_id);
			delete info;
		}
		m_terrainInfoList.clear();
		for (ImageNameList::iterator it = m_imageName.begin(); m_imageName.end() != it; ++it)
		{
			Game::WorldManager::Instance()->GetSceneObjectsControl()->RemoveObjectImage((*it).c_str());
		}
		m_imageName.clear();
	}

	void EditScene::AddLayer( const char *layerName, int zOrder, float moveScale )
	{
		m_layerList.resize(m_layerList.size() + 1);
		m_layerList.back().m_layerName = layerName;
		m_layerList.back().m_zOrder = zOrder;
		m_layerList.back().m_moveScale = moveScale;
		Game::WorldManager::Instance()->CreateLayer(layerName, zOrder, moveScale);
	}

	void EditScene::ChangeLayer( const char *layerName, int zOrder, float moveScale )
	{
		for (int index = 0; index < m_layerList.size(); ++index)
		{
			if (0 == m_layerList[index].m_layerName.compare(layerName))
			{
				m_layerList[index].m_zOrder = zOrder;
				m_layerList[index].m_moveScale = moveScale;
				cocos2d::CCLayer *layer = Game::WorldManager::Instance()->LookupLayer(layerName);
				layer->setZOrder(zOrder);
				Game::CameraChangeLayerMoveScale event(layer, moveScale);
				Game::WorldManager::Instance()->GetCamera()->NotifyChange(&event);
				break;
			}
		}
	}

	void EditScene::RemoveLayer( const char *layerName )
	{
		for (int index = 0; index < m_layerList.size(); ++index)
		{
			if (0 == m_layerList[index].m_layerName.compare(layerName))
			{
				m_layerList.erase(m_layerList.begin() + index);
				break;
			}
		}
		cocos2d::CCLayer *layer = Game::WorldManager::Instance()->LookupLayer(layerName);
		if (NULL != layer)
		{
			layer->release();
		}
	}

}
#include "SceneControl.h"
#include "platform/CCFileUtils.h"
#include "Tools/Scene.h"
#include "platform/CCCommon.h"
#include "BuildingProp.h"
#include "BuildingEvents.h"
#include "sprite_nodes/CCSpriteFrameCache.h"

namespace Game
{
	SceneControl::SceneControl(void)
	:m_width(0)
	,m_height(0)
	,m_gridSize(0)
	,m_gridColumn(0)
	,m_gridRow(0)
	,m_grid(NULL)
	,m_gridArrayLength(0)
	{

	}
	SceneControl::~SceneControl(void)
	{
		if (NULL != m_grid)
		{
			delete m_grid;
		}
		for (int index = 0; index < m_buildings.size(); ++index)
		{
			delete m_buildings[index];
		}
		m_buildings.clear();
	}

	void SceneControl::Load(const char *fileName)
	{
		std::string fullPath;
		fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rb", &size);
		Tools::Scene scene;
		scene.Read(buff, size);
		delete[] buff;
        
        cocos2d::CCLog("%s", scene.GetSceneName());

        cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(scene.GetImageName());

        m_sceneName = scene.GetSceneName();
        m_width = scene.GetWidth();
        m_height = scene.GetHeight();
        m_gridSize = scene.GetGridSize();
        m_gridColumn = scene.GetColumn();
        m_gridRow = scene.GetRow();
        m_gridArrayLength = scene.GetGridArrayLength();
        m_grid = new char[m_gridArrayLength];
        memcpy(m_grid, scene.GetGrid(), m_gridArrayLength);
        const Tools::Scene::InfoList &list = scene.GetInfoList();
        m_buildings.resize(list.size());
        BuildingEventInitLayer event(list.size());
        int index = 0;
        for (Tools::Scene::InfoList::const_iterator it = list.begin(); it != list.end() && index < m_gridArrayLength; ++it, ++index)
        {
        	m_buildings[index] = BuildingProp::Create(&(*it));
        	event.m_entity[index] = m_buildings[index]->CreateEntity();
        }
        NotifyChange(&event);
	}
	bool SceneControl::GetGrid(int x, int y)
	{
		int pos = y * m_gridColumn + x;
		int index = pos / sizeof(char);
		int charPos = pos % sizeof(char);
		return 0 != (m_grid[index] & (1 << charPos));
	}
}
#include "SceneObjectsControl.h"
#include "platform/CCFileUtils.h"
#include "Tools/Scene.h"
#include "platform/CCCommon.h"
#include "SceneObjectProp.h"
#include "SceneObjectEvents.h"

namespace Game
{
	SceneObjectsControl::SceneObjectsControl(void)
	:m_width(0)
	,m_height(0)
	,m_gridSize(0)
	,m_gridColumn(0)
	,m_gridRow(0)
	,m_grid(NULL)
	,m_gridArrayLength(0)
	{

	}
	SceneObjectsControl::~SceneObjectsControl(void)
	{
		if (NULL != m_grid)
		{
			delete m_grid;
		}
		for (int index = 0; index < m_SceneObjects.size(); ++index)
		{
			delete m_SceneObjects[index];
		}
		m_SceneObjects.clear();
	}

	void SceneObjectsControl::Init(const Tools::Scene *sceneFile)
	{
		const Tools::Scene &scene = *sceneFile;

        m_sceneName = scene.GetSceneName();
        m_width = scene.GetWidth();
        m_height = scene.GetHeight();
        m_gridSize = scene.GetGridSize();
        m_gridColumn = scene.GetColumn();
        m_gridRow = scene.GetRow();
        m_gridArrayLength = scene.GetGridArrayLength();
		if (NULL != m_grid)
		{
			delete[] m_grid;
		}
        m_grid = new char[m_gridArrayLength];
        memcpy(m_grid, scene.GetGrids(), m_gridArrayLength);
        const Tools::Scene::ObjectInfoList &list = scene.GetObjectInfoList();
        m_SceneObjects.resize(list.size());
        SceneObjectEventInitLayer event(scene.GetImageNameList(), list.size());
        int index = 0;
        for (Tools::Scene::ObjectInfoList::const_iterator it = list.begin(); it != list.end() && index < m_SceneObjects.size(); ++it, ++index)
        {
        	m_SceneObjects[index] = SceneObjectProp::Create(*it);
        	event.m_entity[index] = m_SceneObjects[index];
        }
        NotifyChange(&event);
	}
	bool SceneObjectsControl::GetGridPass(int x, int y)
	{
		int pos = y * m_gridColumn + x;
		int index = pos / 8;
		int charPos = pos % 8;
		return 0 == (m_grid[index] & (1 << charPos));
	}
	bool SceneObjectsControl::IsPointCanStanc(const cocos2d::CCPoint &point)
	{
		int x = (point.x) / GetGridSize();
		int y = (point.y + GetGridSize() / 2) / GetGridSize();
		if (GetGridPass(x, y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool SceneObjectsControl::AddSceneObject( SceneObjectProp *SceneObject )
	{
		return true;
	}

	void SceneObjectsControl::RemoveSceneObject( SceneObjectProp *SceneObject )
	{

	}

}
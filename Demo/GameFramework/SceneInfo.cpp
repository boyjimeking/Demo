#include "SceneInfo.h"
#include "Tools/Scene.h"

namespace Game
{
	SceneInfo::SceneInfo(void)
		:m_width(0)
		,m_height(0)
		,m_gridSize(0)
		,m_gridColumn(0)
		,m_gridRow(0)
		,m_grid(NULL)
		,m_gridArrayLength(0)
	{

	}

	SceneInfo::~SceneInfo(void)
	{
		if (NULL != m_grid)
		{
			delete m_grid;
		}
	}

	void SceneInfo::Init( const Tools::Scene *sceneFile )
	{
		m_sceneName = sceneFile->GetSceneName();
		m_width = sceneFile->GetWidth();
		m_height = sceneFile->GetHeight();
		m_gridSize = sceneFile->GetGridSize();
		m_gridColumn = sceneFile->GetColumn();
		m_gridRow = sceneFile->GetRow();
		m_gridArrayLength = sceneFile->GetGridArrayLength();
		if (NULL != m_grid)
		{
			delete[] m_grid;
		}
		m_grid = new char[m_gridArrayLength];
		memcpy(m_grid, sceneFile->GetGrids(), m_gridArrayLength);
	}
	bool SceneInfo::GetGridPass(int x, int y)
	{
		if (x < 0 || x >= m_gridColumn || y < 0 || y >= m_gridRow)
		{
			return false;
		}
		int pos = y * m_gridColumn + x;
		int index = pos / 8;
		int charPos = pos % 8;
		return 0 != (m_grid[index] & (1 << charPos));
	}
	bool SceneInfo::IsPointCanStanc(const cocos2d::CCPoint &point)
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

}
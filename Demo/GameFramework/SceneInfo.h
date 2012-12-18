//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework
//	created:	2012-12-18
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneInfo_h__
#define SceneInfo_h__

#include <string>
#include "cocoa/CCGeometry.h"

namespace Tools
{
	class Scene;
}

namespace Game
{
	class SceneInfo
	{
	public:
		SceneInfo(void);
		virtual ~SceneInfo(void);

		void Init(const Tools::Scene *sceneFile);

		bool GetGridPass(int x, int y);
		bool IsPointCanStanc(const cocos2d::CCPoint &point);

		int GetWidth(void) const { return m_width; }
		int GetHeight(void) const { return m_height; }
		int GetColumn(void) const { return m_gridColumn; }
		int GetRow(void) const { return m_gridRow; }
		int GetGridSize(void) const { return m_gridSize; }

		int GetGridArrayLength(void) const { return m_gridArrayLength; }

		const std::string& GetSceneName() const { return m_sceneName; }
		void SetSceneName(const std::string &val);
		void SetSceneScale(float scale);
		int GetTransScale(void) const { return m_transScale; }
	protected:
		std::string m_sceneName;
		int m_width;
		int m_height;
		int m_gridSize;
		int m_gridColumn;
		int m_gridRow;
		char *m_grid;
		int m_gridArrayLength;
		int m_transScale;
	private:

	};
}

#endif // SceneInfo_h__

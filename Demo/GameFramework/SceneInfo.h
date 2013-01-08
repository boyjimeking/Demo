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
using namespace cocos2d;
using namespace Tools;
namespace Game
{
	class SceneInfo
	{
	public:
		SceneInfo(void);
		virtual ~SceneInfo(void);

		void Init(const Scene *sceneFile);

		bool GetGridPass(int x, int y);
		bool IsPointCanStanc(const CCPoint &point);

		float GetWidth(void) const { return m_width; }
		float GetHeight(void) const { return m_height; }
		int GetColumn(void) const { return m_gridColumn; }
		int GetRow(void) const { return m_gridRow; }
		float GetGridSize(void) const { return m_gridSize; }

		int GetGridArrayLength(void) const { return m_gridArrayLength; }

		const std::string& GetSceneName() const { return m_sceneName; }
		void SetSceneName(const std::string &val) { m_sceneName = val; }

		void SetGridPass(int x, int y, bool isPass);

		//设置碰撞是否生效
		void SetCollidable(bool isCollide);
	protected:
		std::string m_sceneName;
		float m_width;
		float m_height;
		float m_gridSize;
		int m_gridColumn;
		int m_gridRow;
		char *m_grid;
		int m_gridArrayLength;
	private:
		bool m_isCollidable;
	};
}

#endif // SceneInfo_h__

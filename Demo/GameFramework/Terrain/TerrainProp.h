//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/Terrain/TerrainProp.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef TerrainProp_h__
#define TerrainProp_h__

#include "../Base/INotifier.h"
#include <vector>

namespace Tools
{
	class Scene;
}
using namespace Tools;
namespace Game
{
	class GridProp;
	/*
	 *	地形属性，用于记录和控制地形数据
	 */
	class TerrainProp
		:public INotifier
	{
	public:
		_Decl_Notifier(TerrainProp);
		TerrainProp(void);
		virtual ~TerrainProp(void);

		void Init(const Scene *sceneFile);

		void AddTerrainGrid(int id, const char *imageName, float x, float y, float width, float height);
		void ChangeTerrainGrid(int id, const char *imageName, float x, float y, float width, float height);
		void RemoveTerrainGrid(int id);
		GridProp* LookupGrid(int id);

		void Clear(void);
	protected:
	private:
		typedef std::vector<GridProp*> GridList;
		GridList m_gridList;
	};
}

#endif // TerrainProp_h__

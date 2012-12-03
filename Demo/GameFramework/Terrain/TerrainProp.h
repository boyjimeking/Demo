//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/Terrain/TerrainProp.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef TerrainProp_h__
#define TerrainProp_h__

#include "../Base/INotifier.h"

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
		TerrainProp(void);
		virtual ~TerrainProp(void);

		void Load(const char *mapName, const char *imageName);
	protected:
	private:
		GridProp **m_gridList;
		int m_width;
		int m_height;
		const char *m_terrainName;
	};
}

#endif // TerrainProp_h__

//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/BuildingManager/SceneControl.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneControl_h__
#define SceneControl_h__

#include "../Base/INotifier.h"
#include <string>

namespace Game
{
	class BuildingProp;
	/*
	 *	建筑控制类，用于控制全部建筑的逻辑处理及控制场景建筑层的改变
	 */
	class SceneControl
		:public INotifier
	{
	public:
		SceneControl(void);
		virtual ~SceneControl(void);

		void Load(const char *fileName);

		bool GetGrid(int x, int y);
	protected:
	private:
		std::string m_sceneName;
		int m_width;
		int m_height;
		int m_gridSize;
		int m_gridColumn;
		int m_gridRow;
		char *m_grid;
		int m_gridArrayLength;
		BuildingProp **m_buildings;
	};
}

#endif // SceneControl_h__

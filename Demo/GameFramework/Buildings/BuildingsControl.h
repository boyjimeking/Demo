//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/BuildingManager/BuildingsControl.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef BuildingsControl_h__
#define BuildingsControl_h__

#include "../Base/INotifier.h"

namespace Tools
{
	class Scene;
}

namespace Game
{
	/*
	 *	建筑控制类，用于控制全部建筑的逻辑处理及控制场景建筑层的改变
	 */
	class BuildingsControl
		:public INotifier
	{
	public:
		BuildingsControl(void);
		virtual ~BuildingsControl(void);

		void Load(const char *fileName);
	protected:
	private:
		Tools::Scene *m_scene;
	};
}

#endif // BuildingsControl_h__

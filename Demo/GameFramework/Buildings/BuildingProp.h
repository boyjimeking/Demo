//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/BuildingManager/BuildingProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef BuildingProp_h__
#define BuildingProp_h__

#include "../Base/INotifier.h"

namespace Game
{
	/*
	 *	建筑属性，用于记录建筑的各项信息及控制建筑的改变
	 */
	class BuildingProp
		:public INotifier
	{
	public:
		BuildingProp(void);
		virtual ~BuildingProp(void);
	protected:
	private:
	};
}

#endif // BuildingProp_h__

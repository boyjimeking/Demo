//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/BuildingManager/BuildingProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef BuildingProp_h__
#define BuildingProp_h__

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"
#include <string>

namespace Tools
{
	struct ObjectInfo;
}

namespace Game
{
	class BuildingEntity;
	/*
	 *	建筑属性，用于记录建筑的各项信息及控制建筑的改变
	 */
	class BuildingProp
		:public INotifier
	{
	public:
		static BuildingProp* Create(const Tools::ObjectInfo *sceneInfo);
		BuildingProp(void);
		virtual ~BuildingProp(void);
		
		void Init(const Tools::ObjectInfo *sceneInfo);
		BuildingEntity* CreateEntity(void);
	protected:
	private:
		cocos2d::CCPoint m_position;
		std::string m_imageName;
	};
}

#endif // BuildingProp_h__

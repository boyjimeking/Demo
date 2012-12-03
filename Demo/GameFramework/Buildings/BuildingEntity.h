//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/BuildingManager/BuildingEntity.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef BuildingEntity_h__
#define BuildingEntity_h__

#include "sprite_nodes/CCSprite.h"
#include "../Base/IObserver.h"

namespace Game
{
	/*
	 *	建筑实体类，用于表示场景中可创建销毁及可触发的地面物件
	 */
	class BuildingEntity
		:public cocos2d::CCSprite
		,public IObserver
	{
	public:
		BuildingEntity(void);
		virtual ~BuildingEntity(void);
	protected:
	private:
	};
}

#endif // BuildingEntity_h__

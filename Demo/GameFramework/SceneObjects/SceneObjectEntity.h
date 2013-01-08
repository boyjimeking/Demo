//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/SceneObjectManager/SceneObjectEntity.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectEntity_h__
#define SceneObjectEntity_h__

#include "sprite_nodes/CCSprite.h"
#include "../Base/IObserver.h"

USING_NS_CC;

namespace Game
{
	/*
	 *	建筑实体类，用于表示场景中可创建销毁及可触发的地面物件
	 */
	class SceneObjectEntity
		:public CCSprite
		,public IObserver
	{
	public:
		static SceneObjectEntity* Create(void);
		SceneObjectEntity(void);
		virtual ~SceneObjectEntity(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
	protected:
	private:
	};
}

#endif // SceneObjectEntity_h__

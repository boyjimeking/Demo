//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/SceneObjectManager/SceneObjectEntity.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectEntity_h__
#define SceneObjectEntity_h__

#include "../Base/IObserver.h"
#include "base_nodes/CCNode.h"

namespace cocos2d
{
	class CCSpriteBatchNode;
}

namespace Game
{
	/*
	 *	建筑实体类，用于表示场景中可创建销毁及可触发的地面物件
	 */
	class SceneObjectEntity
		:public cocos2d::CCNode
		,public IObserver
	{
	public:
		static SceneObjectEntity* Create(void);
		SceneObjectEntity(void);
		virtual ~SceneObjectEntity(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
	protected:
	private:
		cocos2d::CCSpriteBatchNode *m_batchNode;
	};
}

#endif // SceneObjectEntity_h__

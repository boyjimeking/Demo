//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/SceneObjectManager/SceneObjectsLayer.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectsLayer_h__
#define SceneObjectsLayer_h__

#include "../Base/IObserver.h"

namespace cocos2d
{
	class CCLayer;
}

using namespace cocos2d;

namespace Game
{
	/*
	 *	建筑层，用于在场景中组织及显示建筑
	 */
	class SceneObjectsLayer
		:public IObserver
	{
	public:
		SceneObjectsLayer(CCLayer *entityLayer);
		~SceneObjectsLayer(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

	protected:
	private:
		CCLayer *m_entityLayer;
	};
}

#endif // SceneObjectsLayer_h__

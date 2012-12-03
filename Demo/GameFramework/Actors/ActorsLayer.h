//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/ActorManager/Base/ActorsLayer.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorsLayer_h__
#define ActorsLayer_h__

#include "../Base/IObserver.h"

namespace cocos2d
{
	class CCLayer;
}

namespace Game
{
	/*
	 *	角色层，用于在场景中显示角色
	 */
	class ActorsLayer
		:public IObserver
	{
	public:
		ActorsLayer(cocos2d::CCLayer *entityLayer);
		virtual ~ActorsLayer(void);

		virtual void OnNotifyChange( const INotifier *notify, const INotifyEvent *event );

	protected:
	private:
		cocos2d::CCLayer *m_entityLayer;
	};
}

#endif // ActorsLayer_h__

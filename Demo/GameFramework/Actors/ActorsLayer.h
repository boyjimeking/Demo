//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/ActorManager/Base/ActorsLayer.h
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
		ActorsLayer(void);
		virtual ~ActorsLayer(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

	protected:
	private:
	};
}

#endif // ActorsLayer_h__

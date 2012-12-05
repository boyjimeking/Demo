//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/ActorManager/ActorEntity.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorEntity_h__
#define ActorEntity_h__

#include "../Base/IObserver.h"
#include "sprite_nodes/CCSprite.h"
#include "touch_dispatcher/CCTouchDelegateProtocol.h"

namespace Game
{
	class ActorProp;
	/*
	 *	角色实体类，用于角色在场景当中的显示及在场景中的响应处理
	 */
	class ActorEntity
		:public cocos2d::CCSprite
		,public IObserver
		,public cocos2d::CCTouchDelegate
	{
	public:
		ActorEntity(ActorProp *prop);
		virtual ~ActorEntity(void);

		virtual void OnNotifyChange( const INotifier *notify, const INotifyEvent *event );

		virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
		virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	protected:
		enum ENDirection
		{
			enError = -1,
			enActorDirection_Down,
			enActorDirection_Left,
			enActorDirection_Right,
			enActorDirection_Up,
		};
		enum ENActionTag
		{
			enNone,
			enActorAction_PlayAnimation,
			enActorAction_MoveTo,
		};
	protected:
		void PlayAnimation(ENDirection direction);
		ENDirection CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos);

		ActorProp *m_prop;
	private:
		ENDirection m_currentDirection;
		bool m_isMain;
	};
}

#endif // ActorEntity_h__

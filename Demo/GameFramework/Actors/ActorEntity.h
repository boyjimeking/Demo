//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/ActorManager/ActorEntity.h
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
	class ITouch;
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

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

		virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
		virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	protected:
		enum ENDirection
		{
			enError = -1,
			enDirection_East,		//→	0
			enDirection_NorthEast,	//↗	π/4
			enDirection_North,		//↑	π/2
			enDirection_NorthWest,	//↖	3π/4
			enDirection_West,		//←	π
			enDirection_SouthWest,	//↙	-3π/4
			enDirection_South,		//↓	-π/2
			enDirection_SouthEast,	//↘	-π/4
		};
		struct ENAction
		{
			enum Type
			{
				enIdle,
				enMove,
				enAttack,

				Count,
			};
		};
		enum ENCocos2dActionTag
		{
			enNone,
			enActorAction_PlayAnimation,
			enActorAction_MoveTo,
		};
	protected:
		void PlayAnimation(ENAction::Type type, ENDirection direction);
		ENDirection CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos);

	private:
		ENDirection m_currentDirection;
		ENAction::Type m_currentAction;
		char *m_actionTable[ENAction::Count];
		ITouch *m_touchCallBack;
	};
}

#endif // ActorEntity_h__

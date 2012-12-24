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
#include "Base/GlobalDef.h"

namespace Tools
{
	class AvatarData;
}

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


		virtual void setTextureRect(const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCSize& untrimmedSize);

	protected:
		
		enum ENCocos2dActionTag
		{
			enNone,
			enActorAction_PlayAnimation,
			enActorAction_MoveTo,
		};
	protected:
		void PlayAnimation(ENAnimation::Decl type, ENDirection::Decl direction);
		ENDirection::Decl CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos);

		void LoadAvatarFromFile(const char *file);
		void LoadAvatar(unsigned char *data, unsigned int size);
		void SetAvatar(Tools::AvatarData *avatar);
		Tools::AvatarData* GetAvatar(void) const { return m_avatar; }
	private:
		ENDirection::Decl m_currentDirection;
		ENAnimation::Decl m_currentAnimation;
		ITouch *m_touchCallBack;
		Tools::AvatarData *m_avatar;
	};
}

#endif // ActorEntity_h__

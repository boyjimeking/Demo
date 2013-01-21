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
	class BoneAvatarData;
}
class SkeletonCocos2D;
class FrameAnimation;
class BoneAnimation;

using namespace Tools;
namespace Game
{
	class ActorProp;
	class ITouch;
	class EquipObject;
	/*
	 *	角色实体类，用于角色在场景当中的显示及在场景中的响应处理
	 */
	class ActorEntity
		:public cocos2d::CCNode
		,public IObserver
	{
	public:
		static ActorEntity* Create(void);
		ActorEntity(void);
		virtual ~ActorEntity(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
	protected:
		void PlayAnimation(const char *type, ENDirection::Decl direction, bool isLoop = true);
		void RePlayAnimation(void);
		ENDirection::Decl CalDirection(const cocos2d::CCPoint &targetPos, const cocos2d::CCPoint &currentPos);

	private:
		FrameAnimation *m_frameAnimation;
		BoneAnimation *m_boneAnimation;
	};
}

#endif // ActorEntity_h__

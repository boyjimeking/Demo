//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/ActorManager/ActorProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorProp_h__
#define ActorProp_h__

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"
#include "../Base/GlobalDef.h"
#include <list>
#include "ActorAction.h"
#include "../../Demo/Comm/CommDef.h"

namespace Tools
{
	class AvatarData;
}
namespace GUI
{
	class UIProperty;
}
class ActorBattleInfo;
namespace Game
{
	class ActorEntity;
	class PhysicalObj;
	class IAction;
	/*
	 *	角色属性类，用于记录并控制角色的各项属性
	 */
	class ActorProp
		:public INotifier
	{
	public:
		_Decl_Notifier(ActorProp);

		ActorProp(ENActorType::Decl type, int id);
		virtual ~ActorProp(void);

		int GetID(void) const { return m_id; }
		ENActorType::Decl GetActorType(void) const { return m_type; }
		const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
		float GetSpeed(void) const { return m_speed; }

		void Init(void);
		ActorEntity* Create(void);
		void Release(void);

		void MoveTo(const cocos2d::CCPoint &pos);
		void Stop(void);
		void Dead(void);
		void StartAttack(ActorProp *target);
		void ChangeAvatar(Tools::AvatarData *avatar);
		void ChangeEquip(ENEquipType::Decl type, const char *avatarFile);
		void SendAttack(int targetID);
		void BeAttacked(int hpChanged);

		void AttachUI(GUI::UIProperty *uiProp);

		void SetPosition(const cocos2d::CCPoint &pos);

		void Tick(float dt);

		ActorBattleInfo* GetBattleInfo(void) const { return m_battleInfo; }
	protected:
		cocos2d::CCPoint m_position;
		int m_id;
		ENActorType::Decl m_type;
		float m_speed;
		ActorBattleInfo *m_battleInfo;
		ActionControl *m_actionControl;
	private:
	};
}

#endif // ActorProp_h__

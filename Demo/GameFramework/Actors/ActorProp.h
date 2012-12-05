//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/ActorManager/ActorProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorProp_h__
#define ActorProp_h__

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"

namespace Game
{
	class ActorEntity;
	class PhysicalObj;
	/*
	 *	角色属性类，用于记录并控制角色的各项属性
	 */
	class ActorProp
		:public INotifier
	{
	public:
		ActorProp(void);
		virtual ~ActorProp(void);

		ActorEntity* Create(void);
		void Release(void);

		void MoveTo(const cocos2d::CCPoint &pos);

		void SetPosition(const cocos2d::CCPoint &pos);

		void SetIsMain(bool isMain) { m_isMain = isMain; }
		bool IsMain(void) const { return m_isMain; }

		PhysicalObj* GetPhysicalObj(void) const { return m_physicalObj; }
	protected:
		PhysicalObj *m_physicalObj;
		cocos2d::CCPoint m_position;
	private:
		bool m_isMain;
	};
}

#endif // ActorProp_h__

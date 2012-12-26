//////////////////////////////////////////////////////////////////////////
//
//	file path:	VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef IActor_h__
#define IActor_h__

#include "ISimulateObject.h"

class ActorBattleInfo;
namespace Server
{
	class IActor
		:public ISimulateObject
	{
	public:
		_Decl_Simulate(IActor, ISimulateObject);
		IActor(void);
		virtual ~IActor(void);

		virtual void Process(IMessage *message);
		virtual void Tick( float dt );

		float GetX(void) const { return m_x; }
		float GetY(void) const { return m_y; }

		void SetX(float x) { m_x = x; }
		void SetY(float y) { m_y = y; }

		virtual void SycInfo(void);

		//向客户端同步位置
		virtual void SycPosition(void);
		//更换装备
		virtual void ChangeEquip(void);
		//攻击
		virtual void Attack(int targetID);
		//同步战斗属性信息
		void SycBattleInfo(void);
		//死亡
		virtual void Dead(void);

		ActorBattleInfo* GetBattleInfo(void) const { return m_battleInfo; }
	protected:
		ActorBattleInfo *m_battleInfo;
	private:
		float m_x;
		float m_y;

	};
}

#endif // IActor_h__

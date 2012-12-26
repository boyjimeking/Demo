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

namespace Server
{
	class IActor
		:public ISimulateObject
	{
	public:
		_Decl_Simulate(IActor);
		IActor(void);
		virtual ~IActor(void);

		virtual void Process(IMessage *message);

		float GetX(void) const { return m_x; }
		float GetY(void) const { return m_y; }

		void SetX(float x) { m_x = x; }
		void SetY(float y) { m_y = y; }

		//向客户端同步位置
		virtual void SycPosition(void);
		//更换装备
		virtual void ChangeEquip(void);
		//攻击
		virtual void Attack(int targetID);
	protected:

	private:
		float m_x;
		float m_y;

	};
}

#endif // IActor_h__

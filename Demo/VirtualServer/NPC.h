//////////////////////////////////////////////////////////////////////////
//
//	file path:	VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef NPC_h__
#define NPC_h__

#include "IActor.h"

namespace Server
{
	class AIControl;
	class NPC
		:public IActor
	{
	public:
		_Decl_Simulate(NPC, IActor);
		NPC(void);
		virtual ~NPC(void);

		virtual void Tick( float dt );

		virtual void SycInfo( void );
		//死亡
		virtual void Dead(void);

		AIControl * GetControl(void) const { return m_control; }
		int GetTarget(void) const { return m_target; }
		void SetTarget(int val) { m_target = val; }

		virtual void BeAttacked( int targetID );

	protected:

		AIControl *m_control;
	private:
		int m_target;
	};
}

#endif // NPC_h__

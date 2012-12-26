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
	class NPC
		:public IActor
	{
	public:
		_Decl_Simulate(NPC);
		NPC(void);
		virtual ~NPC(void);

		virtual void Tick( float dt );
		void ChangeTarget(void);
	protected:

		float m_totalTime;
	private:

	};
}

#endif // NPC_h__

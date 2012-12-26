//////////////////////////////////////////////////////////////////////////
//
//	file path:	VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef Player_h__
#define Player_h__

#include "IActor.h"

namespace Server
{
	class Player
		:public IActor
	{
	public:
		_Decl_Simulate(Player, IActor);
		Player(void);
		virtual ~Player(void);

		virtual void Process(IMessage *message);
		virtual void SycInfo( void );
	protected:
		void ProcessCSAttackTarget_C2S(IMessage *message);
	private:

	};
}

#endif // Player_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef GameServer_h__
#define GameServer_h__

#include "ISimulateLayer.h"

namespace Server
{
	class GameServer
		:public ISimulateLayer
	{
	public:
		static float Width;
		static float Height;
		static float GridSize;
		static float TranScale;//一米多少点

		static int RandX(void);
		static int RandY(void);

		GameServer(void);
		virtual ~GameServer(void);

		virtual void Init(void);

		virtual void Send(IMessage *message) const;
	protected:
		virtual void Process(IMessage *message);
	private:

	};
}

#endif // GameServer_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Tools
//	created:	2012-12-14
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef DebugLayer_h__
#define DebugLayer_h__

#include "base_nodes/CCNode.h"

namespace Tools
{
	class DebugLayer
		:public cocos2d::CCNode
	{
	public:
		DebugLayer(void);
		virtual ~DebugLayer(void);

		virtual void draw(void);
	protected:

	private:

	};
}

#endif // DebugLayer_h__

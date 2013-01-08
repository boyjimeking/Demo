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
USING_NS_CC;

namespace Tools
{
	class DebugLayer
		:public CCNode
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

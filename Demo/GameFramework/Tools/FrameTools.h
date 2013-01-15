//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Tools
//	created:	2013-1-15
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef FrameTools_h__
#define FrameTools_h__

#include "../Tools/AnimationData.h"
#include "sprite_nodes/CCSpriteBatchNode.h"

namespace Tools
{
	struct FrameTools 
	{
		static cocos2d::CCSpriteBatchNode* CreateBatchNode(const FrameInfo &info);
		static void RefreshBatchNode(cocos2d::CCSpriteBatchNode *batchNode, const FrameInfo &info);
	};
}

#endif // FrameTools_h__

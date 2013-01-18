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
#include "../Tools/Singleton.h"
#include <vector>

using namespace cocos2d;

namespace Tools
{
	struct FrameTools
	{
		static cocos2d::CCSpriteBatchNode* CreateBatchNode(const FrameInfo &info);
		static void RefreshBatchNode(cocos2d::CCSpriteBatchNode *batchNode, const FrameInfo &info);
	};

	class FrameInfoCache
		:public Singleton<FrameInfoCache>
	{
	public:
		void AddFrameInfoByFile(const char *fileName);
		void RemoveFrameInfoByFile(const char *fileName);
		FrameInfo* Lookup(const std::string &key);
	private:
		struct CacheInfo 
		{
			std::string m_fileName;
			int m_ref;
			FramePList *m_frameList;
			CacheInfo(void):m_ref(0){}
		};
		typedef std::vector<CacheInfo> FrameFileList;
		FrameFileList m_list;
	};
}

#endif // FrameTools_h__

#include "FrameTools.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCSprite.h"
#include "../CCFileUtils.h"

namespace Tools
{
	cocos2d::CCSpriteBatchNode* FrameTools::CreateBatchNode( const FrameInfo &info )
	{
		cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(info.m_frame.back().c_str());
		if (NULL == frame)
		{
			return NULL;
		}
		cocos2d::CCSpriteBatchNode* batchNode = cocos2d::CCSpriteBatchNode::createWithTexture(frame->getTexture());

		for (int index = 0; index < info.m_frame.size() ; ++index)
		{
			cocos2d::CCSprite *partSprite = cocos2d::CCSprite::createWithSpriteFrameName(info.m_frame[index].c_str());
			batchNode->appendChild(partSprite);
		}
		return batchNode;
	}

	void FrameTools::RefreshBatchNode( cocos2d::CCSpriteBatchNode *batchNode, const FrameInfo &info )
	{
		cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(info.m_frame.back().c_str());
		if (NULL == frame)
		{
			return;
		}
		batchNode->setTexture(frame->getTexture());
		batchNode->removeAllChildren();
		for (int index = 0; index < info.m_frame.size() ; ++index)
		{
			cocos2d::CCSprite *partSprite = cocos2d::CCSprite::createWithSpriteFrameName(info.m_frame[index].c_str());
			batchNode->appendChild(partSprite);
		}
	}

	FrameInfo* Tools::FrameInfoCache::Lookup( const std::string &key )
	{
		for (unsigned int index = 0; index < m_list.size() ; ++index)
		{
			FrameInfo *info = m_list[index].m_frameList->Lookup(key);
			if (NULL != info)
			{
				return info;
			}
		}
		return NULL;
	}

	void FrameInfoCache::AddFrameInfoByFile( const char *fileName )
	{
		for (unsigned int index = 0; index < m_list.size() ; ++index)
		{
			CacheInfo &info = m_list[index];
			if (0 == info.m_fileName.compare(fileName))
			{
				++info.m_ref;
				return;
			}
		}
		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
		FramePList *frameList = new FramePList;
		frameList->Read(buff, size);
		delete[] buff;

		CacheInfo info;
		info.m_fileName = fileName;
		info.m_frameList = frameList;
		++info.m_ref;
		m_list.push_back(info);
	}

	void FrameInfoCache::RemoveFrameInfoByFile( const char *fileName )
	{
		for (unsigned int index = 0; index < m_list.size() ; ++index)
		{
			CacheInfo &info = m_list[index];
			if (info.m_fileName.compare(fileName))
			{
				--info.m_ref;
				if (info.m_ref <= 0)
				{
					delete info.m_frameList;
					info.m_frameList = NULL;
					m_list.erase(m_list.begin() + index);
				}
				return;
			}
		}
	}

}

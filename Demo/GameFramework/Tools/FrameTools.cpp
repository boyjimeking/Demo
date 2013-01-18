#include "FrameTools.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCSprite.h"
#include "../CCFileUtils.h"
#include "cocoa/CCObject.h"
#include "textures/CCTextureCache.h"

using namespace cocos2d;

namespace Tools
{
	cocos2d::CCSpriteBatchNode* FrameTools::CreateBatchNode( const FrameInfo &info )
	{
		//const char *frameName = NULL;
		cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(info.m_frame.back().c_str());
		if (NULL == frame)
		{
			//frameName = "menu1.png";
			//frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("menu1.png");
			//if (NULL == frame)
			//{
			//	LoadImage *loadCallback = new LoadImage("menu1.png");
			//	frame = loadCallback->Init();
			//}
			return NULL;
		}
		cocos2d::CCSpriteBatchNode* batchNode = NULL;
		//if (NULL != frameName)
		//{
		//	batchNode = cocos2d::CCSpriteBatchNode::create("menu1.png");
		//	cocos2d::CCSprite *partSprite = cocos2d::CCSprite::createWithSpriteFrameName(frameName);
		//	batchNode->appendChild(partSprite);
		//	batchNode->setContentSize(frame->getOriginalSize());
		//}
		//else
		{
			batchNode = cocos2d::CCSpriteBatchNode::createWithTexture(frame->getTexture());
			for (int index = 0; index < info.m_frame.size() ; ++index)
			{
				cocos2d::CCSprite *partSprite = cocos2d::CCSprite::createWithSpriteFrameName(info.m_frame[index].c_str());
				batchNode->appendChild(partSprite);
			}
			batchNode->setContentSize(CCSizeMake(info.width, info.height));
		}
		batchNode->setAnchorPoint(CCPointMake(info.anchorPointX, info.anchorPointY));
		return batchNode;
	}

	void FrameTools::RefreshBatchNode( cocos2d::CCSpriteBatchNode *batchNode, const FrameInfo &info )
	{
		//const char *frameName = NULL;
		cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(info.m_frame.back().c_str());
		if (NULL == frame)
		{
			//frameName = "menu1.png";
			//frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("menu1.png");
			//if (NULL == frame)
			//{
			//	LoadImage *loadCallback = new LoadImage("menu1.png");
			//	frame = loadCallback->Init();
			//}
			return;
		}
		batchNode->setTexture(frame->getTexture());
		batchNode->removeAllChildren();
		//if (NULL != frameName)
		//{
		//	cocos2d::CCSprite *partSprite = cocos2d::CCSprite::createWithSpriteFrameName(frameName);
		//	batchNode->appendChild(partSprite);
		//	batchNode->setContentSize(frame->getOriginalSize());
		//}
		//else
		{
			for (int index = 0; index < info.m_frame.size() ; ++index)
			{
				cocos2d::CCSprite *partSprite = cocos2d::CCSprite::createWithSpriteFrameName(info.m_frame[index].c_str());
				batchNode->appendChild(partSprite);
			}
			batchNode->setContentSize(CCSizeMake(info.width, info.height));
		}
		batchNode->setAnchorPoint(CCPointMake(info.anchorPointX, info.anchorPointY));
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

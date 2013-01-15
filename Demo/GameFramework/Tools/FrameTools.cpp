#include "FrameTools.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCSprite.h"


cocos2d::CCSpriteBatchNode* Tools::FrameTools::CreateBatchNode( const FrameInfo &info )
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

void Tools::FrameTools::RefreshBatchNode( cocos2d::CCSpriteBatchNode *batchNode, const FrameInfo &info )
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

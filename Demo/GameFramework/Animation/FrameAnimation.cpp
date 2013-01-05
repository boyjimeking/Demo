#include "FrameAnimation.h"
#include "../Tools/AvatarData.h"
#include "../Tools/AnimationGroup.h"
#include "../Tools/AnimationData.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCAnimation.h"
#include "actions/CCActionInterval.h"
#include "Actors/EquipObject.h"
#include "../CCFileUtils.h"

FrameAnimation::FrameAnimation(void)
	:m_avatar(NULL)
	,m_currentDirection(ENDirection::enError)
	,m_currentAnimation(ENAnimation::enError)
{
	
}

FrameAnimation::~FrameAnimation(void)
{
	delete m_avatar;
}

void FrameAnimation::LoadAvatarFromFile(const char *fileName)
{
	const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
	unsigned long size = 0;
	unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
	LoadAvatar(buff, size);
	delete[] buff;
}

void FrameAnimation::PlayAnimation( ENAnimation::Decl type, ENDirection::Decl direction, bool isLoop /*= true*/ )
{
	if (m_currentDirection == direction && m_currentAnimation == type)
	{
		return;
	}
	if (ENAnimation::enError == type)
	{
		//使用当前
		type = m_currentAnimation;
	}
	if (ENDirection::enError == direction)
	{
		//使用当前
		direction = m_currentDirection;
	}
	m_currentDirection = direction;
	m_currentAnimation = type;

	if (NULL == GetAvatar())
	{
		return;
	}
	Tools::AnimationGroup *animGroup = GetAvatar()->Lookup(type);
	if (NULL == animGroup)
	{
		return;
	}
	Tools::AnimationData *animData = animGroup->LookupAnimation(direction);
	if (NULL == animData)
	{
		return;
	}
	cocos2d::CCArray *frameArray = cocos2d::CCArray::createWithCapacity(animData->GetFrameCount());
	for (unsigned int index = 0; index < animData->GetFrameCount(); ++index)
	{
		cocos2d::CCSpriteFrame *frame = cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(animData->GetFrame(index));
		if (NULL == frame)
		{
			continue;
		}
		frameArray->addObject(frame);
	}
	this->initWithSpriteFrame(reinterpret_cast<cocos2d::CCSpriteFrame*>(frameArray->lastObject()));
	setAnchorPoint(cocos2d::CCPointMake(0.5f, 0.3f));
	cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, animData->GetDelay());
	cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
	cocos2d::CCAction *action = isLoop ? (cocos2d::CCAction*)cocos2d::CCRepeatForever::create(animate) : (cocos2d::CCAction*)animate;
	this->stopActionByTag(enActorAction_PlayAnimation);
	action->setTag(enActorAction_PlayAnimation);
	this->runAction(action);

	cocos2d::CCArray *childArray = getChildren();
	CCObject* pObj = NULL;
	CCARRAY_FOREACH(childArray,pObj)
	{
		Game::EquipObject* child = (Game::EquipObject*)pObj;
		child->PlayAnimation(type, direction);
	}
}

void FrameAnimation::LoadAvatar( unsigned char *data, unsigned int size )
{
	if (0 == size)
	{
		return;
	}
	if (NULL == m_avatar)
	{
		m_avatar = new Tools::AvatarData;
	}
	m_avatar->Read(data, size);
	cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(GetAvatar()->GetPList());
}

float FrameAnimation::GetTransScale( void ) const
{
	return m_avatar->GetTransScale();
}

#include "FrameAnimation.h"
#include "../Tools/AvatarData.h"
#include "../Tools/AnimationGroup.h"
#include "../Tools/AnimationData.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "sprite_nodes/CCAnimation.h"
#include "actions/CCActionInterval.h"
#include "../CCFileUtils.h"
#include "support/CCPointExtension.h"
#include "SimpleAudioEngine.h"
#include "../CCCommon.h"
#include "sprite_nodes/CCSpriteBatchNode.h"
#include "Tools/FrameTools.h"
#include "Tools/AvatarManager.h"

using namespace CocosDenshion;

FrameAnimation::FrameAnimation(void)
	:m_avatar(NULL)
	,m_currentDirection(ENDirection::enError)
	,m_currentAnimation(ENAnimation::Error)
	,m_animationIndex(0)
	,m_frameTime(0.0f)
	,m_soundTime(0.0f)
	,m_isLoop(false)
	,m_isPlayOver(false)
	,m_batchNode(NULL)
{
	
}

FrameAnimation::~FrameAnimation(void)
{
	delete m_avatar;
}

void FrameAnimation::LoadAvatarFromFile(const char *fileName)
{
	m_avatar = Tools::AvatarManager::getSingleton()->AddAvatarData(fileName);
#ifndef __BatchNode_Frame_
	init();
#endif
}

void FrameAnimation::PlayAnimation(const char *type, ENDirection::Decl direction, bool isLoop /* = true */)
{
	if (m_currentDirection == direction && m_currentAnimation == type)
	{
		return;
	}
	if (ENAnimation::Error == type)
	{
		//使用当前
		type = m_currentAnimation.c_str();
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

	m_isLoop = isLoop;
	m_isPlayOver = false;

	m_animationIndex = 0;
	m_frameTime = 0.0f;
	m_soundTime = 0.0f;
	m_isPlaySound = false;

	CreateFrame(animData, m_animationIndex);

	cocos2d::CCArray *childArray = getChildren();
	CCObject* pObj = NULL;
	CCARRAY_FOREACH(childArray,pObj)
	{
		if (pObj != m_batchNode)
		{
			FrameAnimation* child = (FrameAnimation*)pObj;
			child->PlayAnimation(type, direction, isLoop);
		}
	}
}

//void FrameAnimation::LoadAvatar( unsigned char *data, unsigned int size )
//{
//	if (0 == size)
//	{
//		return;
//	}
//	if (NULL == m_avatar)
//	{
//		m_avatar = new Tools::AvatarData;
//	}
//	else
//	{
//		cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(GetAvatar()->GetPList());
//	}
//	m_avatar->Read(data, size);
//#ifndef __BatchNode_Frame_
//	init();
//#endif
//	cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(GetAvatar()->GetPList());
//	FrameInfoCache::getSingleton()->AddFrameInfoByFile(GetAvatar()->GetFrameList());
//}

float FrameAnimation::GetTransScale( void ) const
{
	return m_avatar->GetTransScale();
}

void FrameAnimation::ChangeEquip( ENEquipType::Decl type, const char *equipFile )
{
	CCNode *equip = getChildByTag(type);
	if (NULL == equip)
	{
		if (NULL == equipFile)
		{
			return;
		}
		FrameAnimation *newEquip = new FrameAnimation;
		newEquip->LoadAvatarFromFile(equipFile);
		newEquip->setTag(type);
		addChild(newEquip);
		newEquip->setPosition(cocos2d::ccpMult(cocos2d::ccpFromSize(getContentSize()), 0.5f));
	}
	else
	{
		if (NULL == equipFile)
		{
			removeChild(equip, true);
			return;
		}
		FrameAnimation *oldEquip = (FrameAnimation*)equip;
		oldEquip->LoadAvatarFromFile(equipFile);
	}
}

void FrameAnimation::update( float fDelta )
{
	cocos2d::CCArray *childArray = getChildren();
	CCObject* pObj = NULL;
	CCARRAY_FOREACH(childArray,pObj)
	{
		if (pObj != m_batchNode)
		{
			FrameAnimation* child = (FrameAnimation*)pObj;
			child->update(fDelta);
		}
	}
	if (m_isPlayOver)
	{
		return;
	}
	Tools::AnimationGroup *animGroup = GetAvatar()->Lookup(m_currentAnimation.c_str());
	if (NULL == animGroup)
	{
		return;
	}
	Tools::AnimationData *animData = animGroup->LookupAnimation(m_currentDirection);
	if (NULL != animData)
	{
		//////////////////////////////////////////////////////////////////////////
		//播放动画帧
		m_frameTime += fDelta;
		if (m_frameTime >= animData->GetDelay())
		{
			m_frameTime = 0.0f;
			++m_animationIndex;
			if (m_animationIndex >= animData->GetFrameCount())
			{
				if (m_isLoop)
				{
					m_isPlaySound = false;
					m_animationIndex = 0;
				}
				else
				{
					m_isPlayOver = true;
				}
			}
			if (!m_isPlayOver)
			{
				CreateFrame(animData, m_animationIndex);
			}
		}

		//////////////////////////////////////////////////////////////////////////
		//播放声音
		if (!m_isPlaySound)
		{
			m_soundTime += fDelta;
			if (m_soundTime >= animGroup->GetSoundDelay())
			{
				m_isPlaySound = true;
				if (!animGroup->GetSoundEffect().empty())
				{
					SimpleAudioEngine::sharedEngine()->playEffect(animGroup->GetSoundEffect().c_str());
				}
			}
		}
	}
}

void FrameAnimation::CreateFrame(AnimationData *animData, int index)
{
	const std::string &frameName = animData->GetFrame(index);
	FrameInfo *info = FrameInfoCache::getSingleton()->Lookup(frameName);
	if (NULL == info)
	{
		return;
	}

	if (NULL == m_batchNode)
	{
		m_batchNode = Tools::FrameTools::CreateBatchNode(*info);
		addChild(m_batchNode);
	}
	else
	{
		Tools::FrameTools::RefreshBatchNode(m_batchNode, *info);
	}
}

cocos2d::CCSize FrameAnimation::getTouchSize( void )
{
	return m_batchNode->getContentSize();
}



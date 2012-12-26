#include "EquipObject.h"
#include "../Tools/AvatarData.h"
#include "../CCFileUtils.h"
#include "sprite_nodes/CCAnimation.h"
#include "ActorEntity.h"
#include "../Tools/AnimationData.h"
#include "../Tools/AnimationGroup.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "actions/CCActionInterval.h"
#include "support/CCPointExtension.h"

namespace Game
{
	EquipObject::EquipObject(void)
		:m_avatar(NULL)
		,m_type(ENEquipType::enError)
	{

	}

	EquipObject::~EquipObject(void)
	{

	}

	void EquipObject::PlayAnimation( ENAnimation::Decl type, ENDirection::Decl direction )
	{
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
		//setAnchorPoint(cocos2d::CCPointMake(0.5f, 0.3f));
		cocos2d::CCAnimation *animation = cocos2d::CCAnimation::createWithSpriteFrames(frameArray, animData->GetDelay());
		cocos2d::CCAnimate *animate = cocos2d::CCAnimate::create(animation);
		cocos2d::CCAction *action = cocos2d::CCRepeatForever::create(animate);
		this->stopActionByTag(ActorEntity::enActorAction_PlayAnimation);
		action->setTag(ActorEntity::enActorAction_PlayAnimation);
		this->runAction(action);
	}
	void EquipObject::LoadAvatarFromFile( const char *file )
	{
		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(file);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
		LoadAvatar(buff, size);
		delete[] buff;
	}

	void EquipObject::LoadAvatar( unsigned char *data, unsigned int size )
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

		//setScale(GetAvatar()->GetTransScale());
		setPosition(cocos2d::ccpMult(cocos2d::ccpFromSize(getParent()->getContentSize()), 0.5f));
		cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(GetAvatar()->GetPList());
	}

	void EquipObject::SetAvatar( Tools::AvatarData *avatar )
	{
		if (m_avatar == avatar)
		{
			return;
		}
		if (NULL != m_avatar)
		{
			delete m_avatar;
		}
		m_avatar = avatar;
	}

	EquipObject* EquipObject::Create( void )
	{
		EquipObject *pSprite = new EquipObject();
		if (pSprite && pSprite->init())
		{
			pSprite->autorelease();
			return pSprite;
		}
		CC_SAFE_DELETE(pSprite);
		return NULL;
	}

}
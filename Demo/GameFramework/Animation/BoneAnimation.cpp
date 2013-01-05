#include "BoneAnimation.h"
#include "../Tools/BoneAvatarData.h"
#include "../Tools/BoneAnimationGroup.h"
#include "../Tools/BoneAnimationData.h"

BoneAnimation::BoneAnimation(void)
	:m_boneAvatar(NULL)
	,m_currentDirection(ENDirection::enError)
	,m_currentAnimation(ENAnimation::enError)
{
	
}

BoneAnimation::~BoneAnimation(void)
{
	delete m_boneAvatar;
}

void BoneAnimation::LoadAvatarFromFile( const char *fileName )
{
	const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
	unsigned long size = 0;
	unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
	LoadBoneAvatar(buff, size);
	delete[] buff;
}

void BoneAnimation::PlayAnimation( ENAnimation::Decl type, ENDirection::Decl direction, bool isLoop )
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

	if (NULL == m_boneAvatar)
	{
		return;
	}
	char buff[16];
	sprintf(buff, "%d", type);
	Tools::BoneAnimationGroup *animGroup = m_boneAvatar->Lookup(buff);
	if (NULL == animGroup)
	{
		return;
	}
	Tools::BoneAnimationData *animData = animGroup->LookupAnimation(direction);
	if (NULL == animData)
	{
		return;
	}
	GetSkeleton()->PlayAnimation(animData->GetAnimationName(), animData->GetSpeed(), -1, isLoop && animData->IsLoop());
}

void BoneAnimation::LoadBoneAvatar( unsigned char *data, unsigned int size )
{
	if (0 == size)
	{
		return;
	}
	if (NULL == m_boneAvatar)
	{
		m_boneAvatar = new Tools::BoneAvatarData;
	}
	m_boneAvatar->Read(data, size);
	Load(m_boneAvatar->GetSkelFilename().c_str(), m_boneAvatar->GetTexFilenameDesc().c_str(), m_boneAvatar->GetTexFilename().c_str(), m_boneAvatar->GetUseSkeletonName().c_str());
}

float BoneAnimation::GetTransScale( void ) const
{
	return m_boneAvatar->GetTransScale();
}

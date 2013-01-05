//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Animation
//	created:	2013-1-5
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef BoneAnimation_h__
#define BoneAnimation_h__

#include "SkeletonCocos2D.h"
#include "Base/GlobalDef.h"

namespace Tools
{
	class BoneAvatarData;
}

class BoneAnimation
	:public SkeletonCocos2D
{
public:
	BoneAnimation(void);
	virtual ~BoneAnimation(void);

	void LoadAvatarFromFile(const char *fileName);
	void PlayAnimation(ENAnimation::Decl type, ENDirection::Decl direction, bool isLoop = true);

	float GetTransScale(void) const;
protected:
	void LoadBoneAvatar(unsigned char *data, unsigned int size);
private:
	Tools::BoneAvatarData *m_boneAvatar;
	ENDirection::Decl m_currentDirection;
	ENAnimation::Decl m_currentAnimation;
};

#endif // BoneAnimation_h__

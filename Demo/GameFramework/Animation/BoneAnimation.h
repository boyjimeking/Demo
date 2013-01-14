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

using namespace Tools;

class BoneAnimation
	:public SkeletonCocos2D
{
public:
	BoneAnimation(void);
	virtual ~BoneAnimation(void);

	void LoadAvatarFromFile(const char *fileName);
	void LoadBoneAvatar(unsigned char *data, unsigned int size);
	void PlayAnimation(const char *type, ENDirection::Decl direction, bool isLoop);

	float GetTransScale(void) const;
protected:
private:
	Tools::BoneAvatarData *m_boneAvatar;
	ENDirection::Decl m_currentDirection;
	const char *m_currentAnimation;
};

#endif // BoneAnimation_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Animation
//	created:	2013-1-5
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef FrameAnimation_h__
#define FrameAnimation_h__

#include "sprite_nodes/CCSprite.h"
#include "Base/GlobalDef.h"

namespace Tools
{
	class AvatarData;
	class AnimationData;
}
using namespace Tools;

class FrameAnimation
	:public cocos2d::CCSprite
{
public:
	FrameAnimation(void);
	virtual ~FrameAnimation(void);

	void LoadAvatarFromFile(const char *fileName);
	void LoadAvatar(unsigned char *data, unsigned int size);
	void PlayAnimation(const char *type, ENDirection::Decl direction, bool isLoop = true);

	void ChangeEquip(ENEquipType::Decl type, const char *equipFile);

	float GetTransScale(void) const;

	virtual void update( float fDelta );
protected:
	Tools::AvatarData * GetAvatar(void) const { return m_avatar; }
	Tools::AvatarData *m_avatar;

	cocos2d::CCSpriteBatchNode* CreateSprite(AnimationData *animData);
private:
	enum ENCocos2dActionTag
	{
		enNone,
		enActorAction_PlayAnimation,
		enActorAction_MoveTo,
	};
	ENDirection::Decl m_currentDirection;
	const char *m_currentAnimation;
private:
	bool m_isLoop;

	int m_animationIndex;
	float m_frameTime;
	float m_soundTime;
	bool m_isPlaySound;
	bool m_isPlayOver;
};

#endif // FrameAnimation_h__

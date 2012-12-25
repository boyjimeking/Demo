//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Actors
//	created:	2012-12-25
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EquipObject_h__
#define EquipObject_h__

#include "sprite_nodes/CCSprite.h"
#include "Base/GlobalDef.h"

namespace Tools
{
	class AvatarData;
}

namespace Game
{
	class EquipObject
		:public cocos2d::CCSprite
	{
	public:
		ENEquipType::Decl GetType(void) const { return m_type; }
		static EquipObject* Create(void);

		EquipObject(void);
		virtual ~EquipObject(void);

		void PlayAnimation(ENAnimation::Decl type, ENDirection::Decl direction);

		void LoadAvatarFromFile(const char *file);
		void LoadAvatar(unsigned char *data, unsigned int size);
		void SetAvatar(Tools::AvatarData *avatar);
		Tools::AvatarData* GetAvatar(void) const { return m_avatar; }

		void SetType(ENEquipType::Decl val) { m_type = val; }
	protected:

	private:
		Tools::AvatarData *m_avatar;
		ENEquipType::Decl m_type;
	};
}

#endif // EquipObject_h__

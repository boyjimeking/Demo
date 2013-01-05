//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Actors
//	created:	2012-12-25
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EquipObject_h__
#define EquipObject_h__

#include "Animation/FrameAnimation.h"

namespace Game
{
	class EquipObject
		:public FrameAnimation
	{
	public:
		ENEquipType::Decl GetType(void) const { return m_type; }
		static EquipObject* Create(void);

		EquipObject(void);
		virtual ~EquipObject(void);

		void SetAvatar(Tools::AvatarData *avatar);

		void SetType(ENEquipType::Decl val) { m_type = val; }
	protected:

	private:
		ENEquipType::Decl m_type;
	};
}

#endif // EquipObject_h__

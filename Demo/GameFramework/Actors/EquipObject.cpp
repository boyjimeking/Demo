#include "EquipObject.h"
#include "../Tools/AvatarData.h"

namespace Game
{
	EquipObject::EquipObject(void)
		:m_type(ENEquipType::enError)
	{

	}

	EquipObject::~EquipObject(void)
	{

	}

	void EquipObject::SetAvatar( AvatarData *avatar )
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
#include "EquipObject.h"
#include "Tools\AvatarData.h"
#include "..\CCFileUtils.h"

namespace Game
{
	EquipObject::EquipObject(void)
	{

	}

	EquipObject::~EquipObject(void)
	{

	}

	void EquipObject::PlayAnimation( ENAnimation::Decl type, ENDirection::Decl direction )
	{

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
}
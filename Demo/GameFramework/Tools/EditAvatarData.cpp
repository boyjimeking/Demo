#include "EditAvatarData.h"
#include "AnimationData.h"

namespace Tools
{
	EditAvatarData::EditAvatarData(void)
		:m_animationCount(0)
	{

	}

	EditAvatarData::~EditAvatarData(void)
	{

	}

	void EditAvatarData::Load( unsigned char *data, int dataLength )
	{
		Read(data, dataLength);
		for (int index = 0; index < m_animationTable.size(); ++index)
		{
			m_animationCount = std::max(m_animationTable[index]->GetID(), m_animationCount);
		}
	}

	int EditAvatarData::Save( unsigned char *data, int dataLength )
	{
		return Write(data, dataLength);
	}

	void EditAvatarData::Create( const char *plistFile )
	{
		Clear();
		m_plist = plistFile;
		m_animationTable.resize(ENDirection::Count);
	}

	AnimationData* EditAvatarData::GetAnimation( ENDirection::Decl direction )
	{
		m_animationTable[direction] = new AnimationData;
		return m_animationTable[direction];
	}

}
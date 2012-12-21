#include "EditAvatarData.h"

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
			m_animationCount = max(m_animationTable[index], m_animationCount);
		}
	}

	int EditAvatarData::Save( unsigned char *data, int dataLength )
	{
		return Write(data, dataLength);
	}

}
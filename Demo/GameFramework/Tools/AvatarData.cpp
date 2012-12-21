#include "AvatarData.h"
#include "StreamHelper.h"
#include "AnimationData.h"

namespace Tools
{
	AvatarData::AvatarData(void)
	{

	}

	AvatarData::~AvatarData(void)
	{
		Clear();
	}

	void AvatarData::Clear( void )
	{
		m_plist.clear();
		for (AnimationTable::iterator it = m_animationTable.begin(); m_animationTable.end() != it; ++it)
		{
			delete *it;
		}
		m_animationTable.clear();
	}

	void AvatarData::Read( unsigned char *buff, unsigned int size )
	{
		StreamHelper stream(buff, size);
		stream.Read(m_plist);
		unsigned int tableSize = 0;
		stream.Read(tableSize);
		m_animationTable.resize(tableSize);
		for (int index = 0; index < tableSize ; ++index)
		{
			AnimationData *data = new AnimationData;
			stream.Read(data);
			m_animationTable[index] = data;
		}
	}

	unsigned int AvatarData::Write( unsigned char *buff, unsigned int size )
	{
		StreamHelper stream(buff, size);
		stream.Write(m_plist);
		unsigned int tableSize = m_animationTable.size();
		stream.Write(tableSize);
		for (AnimationTable::iterator it = m_animationTable.begin(); m_animationTable.end() != it; ++it)
		{
			stream.WriteClass(*it);
		}
		return stream.Size();
	}

	AnimationData* AvatarData::LookupAnimation( int id )
	{
		for (int index = 0; index < m_animationTable.size(); ++index)
		{
			if (m_animationTable[index]->GetID() == id)
			{
				return m_animationTable[index];
			}
		}
		return NULL;
	}

}
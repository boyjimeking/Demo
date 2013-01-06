#include "AvatarData.h"
#include "StreamHelper.h"
#include "AnimationGroup.h"

namespace Tools
{
	AvatarData::AvatarData(void)
		:m_transScale(1.0f)
	{

	}

	AvatarData::~AvatarData(void)
	{
		Clear();
	}

	void AvatarData::Clear( void )
	{
		m_transScale = 1.0f;
		m_plist.clear();
		for (AnimationTable::iterator it = m_animationTable.begin(); m_animationTable.end() != it; ++it)
		{
			delete it->second;
		}
		m_animationTable.clear();
	}

	void AvatarData::Read( unsigned char *buff, unsigned int size )
	{
		Clear();
		StreamHelper stream(buff, size);
		stream.Read(m_transScale);
		stream.Read(m_plist);
		unsigned int tableSize = 0;
		stream.Read(tableSize);
		for (unsigned int index = 0; index < tableSize ; ++index)
		{
			std::string type;
			stream.Read(type);
			AnimationGroup *data = new AnimationGroup;
			stream.ReadClass(data);
			m_animationTable.insert(std::make_pair(type, data));
		}
	}

	unsigned int AvatarData::Write( unsigned char *buff, unsigned int size )
	{
		StreamHelper stream(buff, size);
		stream.Write(m_transScale);
		stream.Write(m_plist);
		unsigned int tableSize = m_animationTable.size();
		stream.Write(tableSize);
		for (AnimationTable::iterator it = m_animationTable.begin(); m_animationTable.end() != it; ++it)
		{
			if (NULL == it->second)
			{
				continue;
			}
			stream.Write(it->first);
			stream.WriteClass(it->second);
		}
		return stream.Size();
	}

	AnimationGroup* AvatarData::Lookup(const char *type) const
	{
		AnimationTable::const_iterator it = m_animationTable.find(type);
		if (m_animationTable.end() == it)
		{
			return NULL;
		}
		else
		{
			return it->second;
		}
	}

}
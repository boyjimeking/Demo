#include "BoneAvatarData.h"
#include "StreamHelper.h"
#include "BoneAnimationGroup.h"

namespace Tools
{
	BoneAvatarData::BoneAvatarData(void)
		:m_transScale(1.0f)
	{

	}

	BoneAvatarData::~BoneAvatarData(void)
	{
		Clear();
	}

	void BoneAvatarData::Read( unsigned char *buff, unsigned int size )
	{
		Clear();
		StreamHelper stream(buff, size);
		stream.Read(m_transScale);

		stream.Read(m_skelFilename);
		stream.Read(m_texFilenameDesc);
		stream.Read(m_texFilename);
		stream.Read(m_useSkeletonName);

		unsigned int tableSize = 0;
		stream.Read(tableSize);
		for (unsigned int index = 0; index < tableSize ; ++index)
		{
			std::string type;
			stream.Read(type);
			BoneAnimationGroup *data = new BoneAnimationGroup;
			stream.ReadClass(data);
			m_animationTable.insert(std::make_pair(type, data));
		}
	}

	unsigned int BoneAvatarData::Write( unsigned char *buff, unsigned int size )
	{
		StreamHelper stream(buff, size);
		stream.Write(m_transScale);

		stream.Write(m_skelFilename);
		stream.Write(m_texFilenameDesc);
		stream.Write(m_texFilename);
		stream.Write(m_useSkeletonName);

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

	void BoneAvatarData::Clear( void )
	{
		m_transScale = 1.0f;
		m_skelFilename.clear();
		m_texFilenameDesc.clear();
		m_texFilename.clear();
		m_useSkeletonName.clear();
		for (AnimationTable::iterator it = m_animationTable.begin(); m_animationTable.end() != it; ++it)
		{
			delete it->second;
		}
		m_animationTable.clear();
	}

	BoneAnimationGroup* BoneAvatarData::Lookup(const std::string &type) const
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
#include "EditBoneAvatarData.h"
#include "Tools/BoneAnimationGroup.h"

namespace Tools
{
	EditBoneAvatarData::EditBoneAvatarData(void)
	{

	}

	EditBoneAvatarData::~EditBoneAvatarData(void)
	{

	}

	void EditBoneAvatarData::Create( const char* skelFilename, const char* texFilenameDesc, const char* texFilename, const char* useSkeletonName )
	{
		Clear();
		SetSkelFilename(skelFilename);
		SetTexFilenameDesc(texFilenameDesc);
		SetTexFilename(texFilename);
		SetUseSkeletonName(useSkeletonName);
	}

	void EditBoneAvatarData::Load( unsigned char *data, int dataLength )
	{
		Read(data, dataLength);
	}

	int EditBoneAvatarData::Save( unsigned char *data, int dataLength )
	{
		return Write(data, dataLength);
	}

	void EditBoneAvatarData::Apply( void )
	{

	}

	BoneAnimationGroup* EditBoneAvatarData::AddAnimationGroup(const std::string &type)
	{
		BoneAnimationGroup *animGroup = Lookup(type);
		if (NULL != animGroup)
		{
			return animGroup;
		}
		else
		{
			animGroup = new BoneAnimationGroup;
			m_animationTable.insert(std::make_pair(type, animGroup));
			return animGroup;
		}
	}

	void EditBoneAvatarData::RemoveAnimationGroup(const std::string &type)
	{
		AnimationTable::const_iterator it = m_animationTable.find(type);
		if (m_animationTable.end() == it)
		{
			return;
		}
		else
		{
			delete it->second;
			m_animationTable.erase(it);
		}
	}

}
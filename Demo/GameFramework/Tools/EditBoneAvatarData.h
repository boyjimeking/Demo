//////////////////////////////////////////////////////////////////////////
//
//	file path:	D:\Documents\Visual Studio 2012\Projects\CreateAvatar\CreateAvatar
//	created:	2013-1-4
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EditBoneAvatarData_h__
#define EditBoneAvatarData_h__

#include "Tools/BoneAvatarData.h"

namespace Tools
{
	class EditBoneAvatarData
		:public BoneAvatarData
	{
	public:
		EditBoneAvatarData(void);
		virtual ~EditBoneAvatarData(void);

		void Create(const char* skelFilename, const char* texFilenameDesc, const char* texFilename, const char* useSkeletonName);
		void Load(unsigned char *data, int dataLength);
		int Save(unsigned char *data, int dataLength);

		void Apply(void);

		BoneAnimationGroup* AddAnimationGroup(const std::string &type);
		void RemoveAnimationGroup(const std::string &type);
	protected:

	private:

	};
}

#endif // EditBoneAvatarData_h__

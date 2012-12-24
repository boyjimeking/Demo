//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Tools
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EditAvatarData_h__
#define EditAvatarData_h__

#include "Tools/AvatarData.h"

namespace Tools
{
	class EditAvatarData
		:public AvatarData
	{
	public:
		EditAvatarData(void);
		virtual ~EditAvatarData(void);

		void Create(const char *plistFile);
		void Load(unsigned char *data, int dataLength);
		int Save(unsigned char *data, int dataLength);

		void Apply(void);

		AnimationGroup* AddAnimationGroup(int type);
		void RemoveAnimationGroup(int type);
	protected:

	private:
	};
}

#endif // EditAvatarData_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Tools
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EditAvatarData_h__
#define EditAvatarData_h__

#include "../Tools/AvatarData.h"

namespace Tools
{
	class EditAvatarData
		:public AvatarData
	{
	public:
		EditAvatarData(void);
		virtual ~EditAvatarData(void);

		void Create(const char *plistFile);
		void SetFrameList(const char *frameList);
		void Load(unsigned char *data, int dataLength);
		int Save(unsigned char *data, int dataLength);

		void Apply(void);

		AnimationGroup* AddAnimationGroup(const char* type);
		void RemoveAnimationGroup(const char* type);
	protected:

	private:
	};
}

#endif // EditAvatarData_h__

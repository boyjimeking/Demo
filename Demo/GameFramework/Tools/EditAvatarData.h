//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Tools
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EditAvatarData_h__
#define EditAvatarData_h__

#include "AvatarData.h"

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
	protected:

	private:
		int m_animationCount;
	};
}

#endif // EditAvatarData_h__

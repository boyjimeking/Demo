//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Tools
//	created:	2013-1-17
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AvatarManager_h__
#define AvatarManager_h__

#include "../Tools/Singleton.h"
#include <map>
#include <string>
#include <vector>

namespace Tools
{
	class AvatarData;
	class AvatarManager
		:public Singleton<AvatarManager>
	{
	public:
		AvatarData* AddAvatarData(const char *path);

		void Tick(void);
	protected:
		void RemoveAvatarData(const std::string &path);

	private:
		typedef std::map<std::string, AvatarData*> AvatarMap;
		AvatarMap m_avaList;

		typedef std::vector<AvatarData*> AvatarList;
		AvatarList m_deleteList;

		typedef std::vector<std::string> ImageLoadedRecord;
		ImageLoadedRecord m_recordList;

		friend struct ManagedAvatarData;
	};
}

#endif // AvatarManager_h__

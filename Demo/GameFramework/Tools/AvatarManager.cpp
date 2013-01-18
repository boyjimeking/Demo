#include "AvatarManager.h"
#include "Tools/AvatarData.h"
#include "../CCFileUtils.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "FrameTools.h"

using namespace cocos2d;

namespace Tools
{
	struct ManagedAvatarData
		:public AvatarData
	{
		std::string m_path;

		virtual void Release(void)
		{
			--m_ref;
			if (m_ref <= 0)
			{
				AvatarManager::getSingleton()->RemoveAvatarData(m_path);
			}
		}
	};
	AvatarData* AvatarManager::AddAvatarData( const char *path )
	{
		AvatarMap::iterator it = m_avaList.find(path);
		if (m_avaList.end() != it)
		{
			it->second->Retain();
			return it->second;
		}
		else
		{
			const char *fullPath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(path);
			unsigned long size = 0;
			unsigned char *buff = CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
			ManagedAvatarData *avaData = new ManagedAvatarData;
			avaData->Read(buff, size);
			delete[] buff;
			avaData->m_path = path;
			m_avaList.insert(std::make_pair(path, avaData));
			avaData->Retain();

			cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(avaData->GetPList());
			FrameInfoCache::getSingleton()->AddFrameInfoByFile(avaData->GetFrameList());

			return avaData;
		}
	}

	void AvatarManager::RemoveAvatarData(const std::string &path)
	{
		AvatarMap::iterator it = m_avaList.find(path);
		if (m_avaList.end() != it)
		{
			AvatarData *avaData = it->second;

			cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->removeSpriteFramesFromFile(avaData->GetPList());
			FrameInfoCache::getSingleton()->RemoveFrameInfoByFile(avaData->GetFrameList());

			m_deleteList.push_back(it->second);
			m_avaList.erase(it);
		}
	}

	void AvatarManager::Tick( void )
	{
		for (unsigned int index = 0; index < m_deleteList.size() ; ++index)
		{
			delete m_deleteList[index];
		}
		m_deleteList.clear();
	}

}
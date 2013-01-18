#include "AvatarManager.h"
#include "../Tools/AvatarData.h"
#include "../CCFileUtils.h"
#include "sprite_nodes/CCSpriteFrameCache.h"
#include "FrameTools.h"
#include "textures/CCTextureCache.h"

using namespace cocos2d;

namespace Tools
{
	class LoadImage
		:public CCObject
	{
	public:
		LoadImage(const char *path)
			:m_path(path)
		{

		}
		~LoadImage()
		{
			CCLog("~LoadImage");
		}
		void Init(void)
		{
			this->autorelease();
			this->retain();
			std::string temp = m_path.substr(0, m_path.find_last_of(".")) + ".png";
			cocos2d::CCTextureCache::sharedTextureCache()->addImageAsync(temp.c_str(), this, callfuncO_selector(LoadImage::CallBack));
		}
		void CallBack(CCObject *obj)
		{
			if (NULL != obj)
			{
				CCTexture2D *texture = reinterpret_cast<CCTexture2D*>(obj);
				cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(m_path.c_str(), texture);
			}
			this->release();
		}
	private:
		const std::string m_path;
	};

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

			FrameInfoCache::getSingleton()->AddFrameInfoByFile(avaData->GetFrameList());
			//cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(avaData->GetPList());
			if (std::find(m_recordList.begin(), m_recordList.end(), avaData->GetFrameList()) == m_recordList.end())
			{
				m_recordList.push_back(avaData->GetFrameList());
				LoadImage *loadImage = new LoadImage(avaData->GetPList());
				loadImage->Init();
			}

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
			ImageLoadedRecord::iterator innerIt = std::find(m_recordList.begin(), m_recordList.end(), avaData->GetFrameList());
			if (m_recordList.end() != innerIt)
			{
				m_recordList.erase(innerIt);
			}

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
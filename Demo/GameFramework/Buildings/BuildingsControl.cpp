#include "BuildingsControl.h"
#include "platform/CCFileUtils.h"
#include "Tools/Scene.h"
#include "platform/CCCommon.h"

namespace Game
{
	BuildingsControl::BuildingsControl(void)
	:m_scene(NULL)
	{

	}
	BuildingsControl::~BuildingsControl(void)
	{
		if (NULL != m_scene)
		{
			delete m_scene;
			m_scene = NULL;
		}
	}

	void BuildingsControl::Load(const char *fileName)
	{
		std::string fullPath;
		fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(fileName);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "rb", &size);
		m_scene = new Tools::Scene();
		m_scene->Read(buff, size);
		delete[] buff;
        
        cocos2d::CCLog("%s", m_scene->GetSceneName());
	}
}
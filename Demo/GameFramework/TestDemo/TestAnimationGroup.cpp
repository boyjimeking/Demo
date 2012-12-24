//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\TestDemo
//	created:	2012-12-24
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#define __TestAnimationGroup_Test__
#ifdef __TestAnimationGroup_Test__

#include "gtest.h"
#include "Tools\AnimationGroup.h"

#pragma comment(lib, "Tools.lib")
#pragma comment(lib, "GameFramework.lib")

class TestAnimationGroup
	:public testing::Test
{
public:
	virtual void SetUp()
	{
		m_writeGroup = new Tools::AnimationGroup;
		m_group = new Tools::AnimationGroup;
	}
	virtual void TearDown()
	{
		delete m_group;
		delete m_writeGroup;
	}

public:
	Tools::AnimationGroup *m_group;
	Tools::AnimationGroup *m_writeGroup;
};
TEST_F(TestAnimationGroup, AnimationGroup)
{
	
}

#endif // __TestAnimationGroup_Test__

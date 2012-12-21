//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\TestDemo
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#define __TestEditAvatarData_Test__
#ifdef __TestEditAvatarData_Test__

#include "gtest.h"
#include "Tools\EditAvatarData.h"

class TestEditAvatarData
	:public testing::Test
{
public:
	virtual void SetUp()
	{
		m_writeData = new Tools::EditAvatarData;
		m_readData = new Tools::AvatarData;
	}
	virtual void TearDown()
	{
		delete m_readData;
		delete m_writeData;
	}

public:
	Tools::EditAvatarData *m_writeData;
	Tools::AvatarData *m_readData;
};

TEST_F(TestEditAvatarData, )
{
	
}

#endif // __TestEditAvatarData_Test__

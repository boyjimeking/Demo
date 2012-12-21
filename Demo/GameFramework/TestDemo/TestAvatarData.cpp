//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\TestDemo
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#define __TestAvatarData_Test__
#ifdef __TestAvatarData_Test__

#include "gtest.h"
#include "Tools\AvatarData.h"
#include "Tools\StreamHelper.h"

class TestAvatarData
	:public testing::Test
{
public:
	virtual void SetUp()
	{
		m_writeData = new Tools::AvatarData;
		m_readData = new Tools::AvatarData;

	}
	virtual void TearDown()
	{
		delete m_readData;
		delete m_writeData;
	}

public:
	Tools::AvatarData *m_writeData;
	Tools::AvatarData *m_readData;
};

TEST_F(TestAvatarData, Data)
{
	unsigned char buff[16384] = {0};
	unsigned int length = m_writeData->Write(buff, 16384);

	m_readData->Read(buff, length);
}

#endif // __TestAvatarData_Test__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\TestDemo
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#define __TestAnimationData_Test__
#ifdef __TestAnimationData_Test__

#include "gtest.h"
#include "Tools\AnimationData.h"
#include "Tools\StreamHelper.h"

#pragma comment(lib, "Tools.lib")

class TestAnimationData
	:public testing::Test
{
public:
	virtual void SetUp()
	{
		m_data = new Tools::AnimationData;
		m_readData = new Tools::AnimationData;
	}
	virtual void TearDown()
	{
		delete m_readData;
		delete m_data;
	}

	Tools::AnimationData *m_data;
	Tools::AnimationData *m_readData;
};

TEST_F(TestAnimationData, Data)
{
	unsigned char buff[4096] = {0};
	Tools::StreamHelper stream(buff, 4096);
	Tools::StreamHelper readStream(buff, 4096);

	m_data->SetDelay(0.2f);
	m_data->AddFrame(0, "frame1");
	m_data->AddFrame(1, "frame2");
	m_data->AddFrame(2, "frame3");
	m_data->Write(&stream);

	m_readData->Read(&readStream);
	EXPECT_EQ(m_data->GetDelay(), m_readData->GetDelay());
	//EXPECT_EQ(m_data->GetFrames(), m_readData->GetFrames());
}

#endif // __TestAnimationData_Test__

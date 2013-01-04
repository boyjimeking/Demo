#include "BoneAnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	BoneAnimationData::BoneAnimationData(void)
		:m_speed(1.0f)
		,m_isLoop(true)
	{

	}

	BoneAnimationData::~BoneAnimationData(void)
	{

	}

	void BoneAnimationData::Clear( void )
	{
		m_animationName.clear();
		m_isLoop = true;
		m_speed = 1.0f;
	}

	void BoneAnimationData::Read( StreamHelper *stream )
	{
		stream->Read(m_animationName);
		stream->Read(m_speed);
		stream->Read(m_isLoop);
	}

	void BoneAnimationData::Write( StreamHelper *stream )
	{
		stream->Write(m_animationName);
		stream->Write(m_speed);
		stream->Write(m_isLoop);
	}

}
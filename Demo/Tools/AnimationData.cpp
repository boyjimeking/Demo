#include "AnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	AnimationData::AnimationData(void)
		:m_delay(0.0f)
		,m_soundDelay(0.0f)
	{

	}

	AnimationData::~AnimationData(void)
	{
		Clear();
	}

	void AnimationData::AddFrame( const char *frame )
	{
		m_frame.push_back(frame);
	}

	void AnimationData::Read(StreamHelper *stream)
	{
		Clear();
		stream->Read(m_delay);
		unsigned int frameSize = 0;
		stream->Read(frameSize);
		m_frame.resize(frameSize);
		for (int index = 0; index < frameSize ; ++index)
		{
			stream->Read(m_frame[index]);
		}
		stream->Read(m_soundEffect);
		stream->Read(m_soundDelay);
	}

	void AnimationData::Write(StreamHelper *stream)
	{
		stream->Write(m_delay);
		unsigned int frameSize = m_frame.size();
		stream->Write(frameSize);
		for (int index = 0; index < frameSize ; ++index)
		{
			stream->Write(m_frame[index]);
		}
		stream->Write(m_soundEffect);
		stream->Write(m_soundDelay);
	}

	void AnimationData::Clear( void )
	{
		m_delay = 0.0f;
		m_frame.clear();
		m_soundEffect.clear();
		m_soundDelay = 0.0f;
	}

}
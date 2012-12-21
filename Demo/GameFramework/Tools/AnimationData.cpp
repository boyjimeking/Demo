#include "AnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	AnimationData::AnimationData(void)
		:m_id(0)
		,m_delay(0.0f)
		,m_direction(ENDirection::enError)
	{

	}

	AnimationData::~AnimationData(void)
	{

	}

	void AnimationData::AddFrame( const char *frame )
	{
		m_frame.push_back(frame);
	}

	void AnimationData::Read(StreamHelper *stream)
	{
		stream->Read(m_id);
		stream->Read(m_delay);
		stream->Read(m_direction);
		unsigned int frameSize = 0;
		stream->Read(frameSize);
		m_frame.resize(frameSize);
		for (int index = 0; index < frameSize ; ++index)
		{
			stream->Read(m_frame[index]);
		}
	}

	void AnimationData::Write(StreamHelper *stream)
	{
		stream->Write(m_id);
		stream->Write(m_delay);
		stream->Write(m_direction);
		unsigned int frameSize = m_frame.size();
		stream->Write(frameSize);
		for (int index = 0; index < frameSize ; ++index)
		{
			stream->Write(m_frame[index]);
		}
	}
}
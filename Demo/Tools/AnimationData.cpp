#include "AnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	AnimationData::AnimationData(void)
		:m_delay(0.0f)
		,m_version(enBase)
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
		unsigned int version = 0;
		stream->Read(version);

		stream->Read(m_delay);
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
		stream->Write(m_version);
		stream->Write(m_delay);
		unsigned int frameSize = m_frame.size();
		stream->Write(frameSize);
		for (int index = 0; index < frameSize ; ++index)
		{
			stream->Write(m_frame[index]);
		}
	}

	void AnimationData::Clear( void )
	{
		m_delay = 0.0f;
		m_frame.clear();
	}

}
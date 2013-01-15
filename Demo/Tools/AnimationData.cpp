#include "AnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	AnimationData::AnimationData(void)
		:m_delay(0.0f)
	{

	}

	AnimationData::~AnimationData(void)
	{
		Clear();
	}

	void AnimationData::AddFrame(int index, const char *frame)
	{
		if (index < m_frame.size())
		{
		}
		else
		{
			m_frame.resize(index + 1);
		}
		m_frame[index].push_back(frame);
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
			unsigned int innerSize = 0;
			stream->Read(innerSize);
			m_frame[index].resize(innerSize);
			for (int innerIndex = 0; innerIndex < innerSize ; ++innerIndex)
			{
				stream->Read(m_frame[index][innerIndex]);
			}
		}
	}

	void AnimationData::Write(StreamHelper *stream)
	{
		stream->Write(m_delay);
		unsigned int frameSize = m_frame.size();
		stream->Write(frameSize);
		for (int index = 0; index < frameSize ; ++index)
		{
			unsigned int innerSize = m_frame[index].size();
			stream->Write(innerSize);
			for (int innerIndex = 0; innerIndex < innerSize ; ++innerIndex)
			{
				stream->Write(m_frame[index][innerIndex]);
			}
		}
	}

	void AnimationData::Clear( void )
	{
		m_delay = 0.0f;
		m_frame.clear();
	}

}
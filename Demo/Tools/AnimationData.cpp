#include "AnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	AnimationData::AnimationData(void)
		:m_delay(0.0f)
		,m_version(enLookupByString)
	{

	}

	AnimationData::~AnimationData(void)
	{
		Clear();
	}

	void AnimationData::AddFrame(unsigned int index, const char *frame)
	{
		if (index < m_frame.size())
		{
		}
		else
		{
			m_frame.resize(index + 1);
		}
		m_frame[index] = frame;
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
		for (unsigned int index = 0; index < frameSize ; ++index)
		{
			if (version == enSeprateFrame)
			{
				FrameInfo info;
				stream->ReadClass(&info);
				m_frame[index] = info.m_frame.back();
			}
			else
			{
				stream->Read(m_frame[index]);
			}
		}
	}

	void AnimationData::Write(StreamHelper *stream)
	{
		stream->Write(m_version);
		stream->Write(m_delay);
		unsigned int frameSize = m_frame.size();
		stream->Write(frameSize);
		for (unsigned int index = 0; index < frameSize ; ++index)
		{
			stream->Write(m_frame[index]);
		}
	}

	void AnimationData::Clear( void )
	{
		m_delay = 0.0f;
		m_frame.clear();
	}

	void AnimationData::RemoveFrame( unsigned int index )
	{
		if (index < m_frame.size())
		{
			m_frame.erase(m_frame.begin() + index);
		}
	}

}
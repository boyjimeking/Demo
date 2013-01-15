#include "AnimationData.h"
#include "StreamHelper.h"

namespace Tools
{
	AnimationData::AnimationData(void)
		:m_delay(0.0f)
		,m_version(enSeprateFrame)
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
		m_frame[index].m_frame.push_back(frame);
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
			if (version >= enSeprateFrame)
			{
				stream->ReadClass(&m_frame[index]);
			}
			else
			{
				std::string temp;
				stream->Read(temp);
				m_frame[index].width = 225.0f;
				m_frame[index].height = 225.0f;
				m_frame[index].m_frame.push_back(temp);
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
			stream->WriteClass(&m_frame[index]);
		}
	}

	void AnimationData::Clear( void )
	{
		m_delay = 0.0f;
		m_frame.clear();
	}

}
#include "FrameInfo.h"
#include "StreamHelper.h"

namespace Tools
{
	FrameInfo::FrameInfo( void )
		:width(0.0f)
		,height(0.0f)
		,m_version(enBase)
	{

	}

	void FrameInfo::Clear( void )
	{
		width = 0.0f;
		height = 0.0f;
		m_frame.clear();
	}

	void FrameInfo::Read( StreamHelper *stream )
	{
		unsigned int version = 0;
		stream->Read(version);
		stream->Read(width);
		stream->Read(height);
		unsigned int size = 0;
		stream->Read(size);
		m_frame.resize(size);
		for (unsigned int index = 0; index < size; ++index)
		{
			stream->Read(m_frame[index]);
		}
	}

	void FrameInfo::Write( StreamHelper *stream )
	{
		stream->Write(m_version);
		stream->Write(width);
		stream->Write(height);
		unsigned int size = m_frame.size();
		stream->Write(size);
		for (unsigned int index = 0; index < size; ++index)
		{
			stream->Write(m_frame[index]);
		}
	}
}
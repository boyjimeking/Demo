#include "FrameInfo.h"
#include "StreamHelper.h"

namespace Tools
{
	FrameInfo::FrameInfo( void )
		:width(0.0f)
		,height(0.0f)
		,m_version(enLayerName)
		,anchorPointX(0.0f)
		,anchorPointY(0.0f)
	{

	}

	void FrameInfo::Clear( void )
	{
		anchorPointX = 0.0f;
		anchorPointY = 0.0f;
		width = 0.0f;
		height = 0.0f;
		m_frame.clear();
	}

	unsigned int FrameInfo::Read( StreamHelper *stream )
	{
		unsigned int version = 0;
		stream->Read(version);
		stream->Read(width);
		stream->Read(height);
		if (version >= enAnchorPoint)
		{
			stream->Read(anchorPointX);
			stream->Read(anchorPointY);
		}
		unsigned int size = 0;
		stream->Read(size);
		m_frame.resize(size);
		for (unsigned int index = 0; index < size; ++index)
		{
			stream->Read(m_frame[index]);
		}
		return version;
	}

	void FrameInfo::Write( StreamHelper *stream )
	{
		stream->Write(m_version);
		stream->Write(width);
		stream->Write(height);
		stream->Write(anchorPointX);
		stream->Write(anchorPointY);
		unsigned int size = m_frame.size();
		stream->Write(size);
		for (unsigned int index = 0; index < size; ++index)
		{
			stream->Write(m_frame[index]);
		}
	}



	FramePList::FramePList( void )
		:m_version(enBase)
	{

	}

	FramePList::~FramePList( void )
	{

	}

	void FramePList::Read( unsigned char *buff, unsigned long size )
	{
		StreamHelper stream(buff, size);
		stream.Read(m_version);
		unsigned int mapSize = 0;
		stream.Read(mapSize);
		for (unsigned int index = 0; index < mapSize ; ++index)
		{
			std::string temp;
			FrameInfo info;
			stream.Read(temp);
			stream.ReadClass(&info);
			m_frameMap.insert(std::make_pair(temp, info));
		}
	}

	unsigned int FramePList::Write( unsigned char *buff, unsigned long size )
	{
		StreamHelper stream(buff, size);
		stream.Write(m_version);
		unsigned int mapSize = m_frameMap.size();
		stream.Write(mapSize);
		for (FrameMap::iterator it = m_frameMap.begin(); m_frameMap.end() != it; ++it)
		{
			stream.Write(it->first);
			stream.WriteClass(&it->second);
		}
		return stream.Size();
	}

	void FramePList::AddFrameInfo( const std::string &key, const FrameInfo &frameInfo )
	{
		FrameMap::iterator it = m_frameMap.find(key);
		if (m_frameMap.end() != it)
		{
			it->second = frameInfo;
		}
		else
		{
			m_frameMap.insert(std::make_pair(key, frameInfo));
		}
	}

	void FramePList::RemoveFrameInfo( const std::string &key )
	{
		FrameMap::iterator it = m_frameMap.find(key);
		if (m_frameMap.end() != it)
		{
			m_frameMap.erase(it);
		}
	}

	FrameInfo* FramePList::Lookup( const std::string &key )
	{
		FrameMap::iterator it = m_frameMap.find(key);
		if (m_frameMap.end() != it)
		{
			return &(it->second);
		}
		else
		{
			return NULL;
		}
	}

	void FramePList::Clear( void )
	{
		m_frameMap.clear();
	}

}
#include "StreamHelper.h"
#include <stddef.h>

namespace Tools
{
	StreamHelper::StreamHelper(unsigned char *buff, unsigned int size)
		:m_buff(buff)
		,m_size(size)
		,m_index(0)
		,m_isNeedDelete(false)
	{

	}
	StreamHelper::StreamHelper(unsigned int size)
		:m_buff(NULL)
		,m_size(size)
		,m_index(0)
		,m_isNeedDelete(true)
	{
		m_buff = new unsigned char[m_size];
	}
	StreamHelper::~StreamHelper(void)
	{
		if (m_isNeedDelete)
		{
			delete[] m_buff;
		}
	}

	void StreamHelper::Write( const std::string &value )
	{
		if (m_index + sizeof(unsigned int) > m_size)
		{
			return;
		}
		unsigned int size = value.size();
		Write(size);
		if (m_index + size > m_size)
		{
			return;
		}
		memcpy(&m_buff[m_index], &value[0], size);
		m_index += size;
	}

	void StreamHelper::Write( std::string &value )
	{
		if (m_index + sizeof(unsigned int) > m_size)
		{
			return;
		}
		unsigned int size = value.size();
		Write(size);
		if (0 == size)
		{
			return;
		}
		if (m_index + size > m_size)
		{
			return;
		}
		memcpy(&m_buff[m_index], &value[0], size);
		m_index += size;
	}

	void StreamHelper::Read( std::string &value )
	{
		if (m_index + sizeof(unsigned int) > m_size)
		{
			return;
		}
		unsigned int size = 0;
		Read(size);
		if (0 == size)
		{
			return;
		}
		if (m_index + size > m_size)
		{
			return;
		}
		value.resize(size);
		memcpy(&value[0], &m_buff[m_index], size);
		m_index += size;
	}

}
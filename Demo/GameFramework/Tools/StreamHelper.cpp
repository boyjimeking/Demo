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
}
//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	e:/Code/SceneStream/SceneStream/StreamHelper.h
//	创建日期:	2012年12月10日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef StreamHelper_h__
#define StreamHelper_h__

#include <string>

namespace Tools
{
	class StreamHelper
	{
	public:
		StreamHelper(unsigned char *buff, unsigned int size);
		StreamHelper(unsigned int size);
		~StreamHelper(void);

		void Read(std::string &value);
		template<typename T>
		void Read(T &value)
		{
			if (m_index + sizeof(T) > m_size)
			{
				return;
			}
			memcpy(&value, &m_buff[m_index], sizeof(T));
			m_index += sizeof(T);
		}
		template<typename T>
		void Read(T *value)
		{
			if (m_index + sizeof(T) > m_size)
			{
				return;
			}
			memcpy(value, &m_buff[m_index], sizeof(T));
			m_index += sizeof(T);
		}
		template<typename T>
		void Read(T *value, unsigned int size)
		{
			if (m_index + sizeof(T) * size > m_size)
			{
				return;
			}
			memcpy(value, &m_buff[m_index], sizeof(T) * size);
			m_index += sizeof(T) * size;
		}
		template<typename T>
		void ReadClass(T *value)
		{
			value->Read(this);
		}

		void Write(const std::string &value);
		void Write(std::string &value);
		template<typename T>
		void Write(T &value)
		{
			if (m_index + sizeof(T) > m_size)
			{
				return;
			}
			memcpy(&m_buff[m_index], &value, sizeof(T));
			m_index += sizeof(T);
		}
		template<typename T>
		void Write(T *value)
		{
			if (m_index + sizeof(T) > m_size)
			{
				return;
			}
			memcpy(&m_buff[m_index], value, sizeof(T));
			m_index += sizeof(T);
		}
		template<typename T>
		void Write(T *value, unsigned int size)
		{
			if (m_index + sizeof(T) * size > m_size)
			{
				return;
			}
			memcpy(&m_buff[m_index], value, sizeof(T) * size);
			m_index += sizeof(T) * size;
		}
		template<typename T>
		void WriteClass(T *value)
		{
			value->Write(this);
		}

		unsigned int Size(void) const { return m_index; }
		unsigned int Capcity(void) const { return m_size; }
	protected:
	private:
		unsigned char *m_buff;
		bool m_isNeedDelete;
		unsigned int m_size;
		unsigned int m_index;
	};
}

#endif // StreamHelper_h__

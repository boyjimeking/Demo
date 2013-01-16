//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2013-1-15
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef FrameInfo_h__
#define FrameInfo_h__

#include <vector>
#include <string>
#include <map>

namespace Tools
{
	class StreamHelper;
	struct FrameInfo
	{
		float width;
		float height;
		std::vector<std::string> m_frame;

		FrameInfo(void);

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		void Clear(void);
	private:
		enum ENVersion
		{
			enBase,
		};
		unsigned int m_version;
	};

	class FramePList
	{
	public:
		FramePList(void);
		~FramePList(void);

		void Read(unsigned char *buff, unsigned long size);
		void Write(unsigned char *buff, unsigned long size);

		void AddFrameInfo(const std::string &key, const FrameInfo &frameInfo);
		void RemoveFrameInfo(const std::string &key);
		FrameInfo* Lookup(const std::string &key);

		void Clear(void);
	protected:
		typedef std::map<std::string, FrameInfo> FrameMap;
		FrameMap m_frameMap;
	private:
		enum ENVersion
		{
			enBase,
		};
		unsigned int m_version;
	};
}

#endif // FrameInfo_h__

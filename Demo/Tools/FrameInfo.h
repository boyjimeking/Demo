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
}

#endif // FrameInfo_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Tools
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AnimationData_h__
#define AnimationData_h__

#include <vector>
#include <string>

namespace Tools
{
	class StreamHelper;
	class AnimationData
	{
	public:
		typedef std::vector<std::string> FrameList;

		AnimationData(void);
		virtual ~AnimationData(void);

		//每帧时间
		float GetDelay(void) const { return m_delay; }
		void SetDelay(float delay) { m_delay = delay; }

		//添加帧
		void AddFrame(const char *frame);
		//获取帧数
		unsigned int GetFrameCount(void) const { return m_frame.size(); }
		//获取全部帧
		const FrameList& GetFrames(void) const { return m_frame; }
		const char* GetFrame(int index) const { return m_frame[index].c_str(); }

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		void Clear(void);

	protected:
		float m_delay;
		FrameList m_frame;

		enum ENVersion
		{
			enBase,
		};
		unsigned int m_version;
	};
}

#endif // AnimationData_h__

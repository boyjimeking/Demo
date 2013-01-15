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
		typedef std::vector<std::string> FrameInfo;
		typedef std::vector<FrameInfo> FrameList;

		AnimationData(void);
		virtual ~AnimationData(void);

		//每帧时间
		float GetDelay(void) const { return m_delay; }
		void SetDelay(float delay) { m_delay = delay; }

		//添加帧
		void AddFrame(int index, const char *frame);
		//获取帧数
		unsigned int GetFrameCount(void) const { return m_frame.size(); }
		//获取全部帧
		const FrameList& GetFrames(void) const { return m_frame; }
		const FrameInfo& GetFrame(int index) const { return m_frame[index]; }

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		void Clear(void);

	protected:

		float m_delay;
		FrameList m_frame;
	};
}

#endif // AnimationData_h__

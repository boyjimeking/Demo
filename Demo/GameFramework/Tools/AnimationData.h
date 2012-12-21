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
#include "Base/GlobalDef.h"

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

		//动作方向
		ENDirection::Decl GetDirection(void) const { return m_direction; }
		void SetDirection(ENDirection::Decl val) { m_direction = val; }

		//添加帧
		void AddFrame(const char *frame);
		//获取帧数
		unsigned int GetFrameCount(void) const { return m_frame.size(); }
		//获取全部帧
		const FrameList& GetFrames(void) const { return m_frame; }

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
	protected:

		float m_delay;
		ENDirection::Decl m_direction;
		FrameList m_frame;
	};
}

#endif // AnimationData_h__

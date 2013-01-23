//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2013-1-4
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef BoneAnimationData_h__
#define BoneAnimationData_h__

#include <string>

namespace Tools
{
	class StreamHelper;
	class BoneAnimationData
	{
	public:
		BoneAnimationData(void);
		virtual ~BoneAnimationData(void);

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		void Clear(void);

		const std::string& GetAnimationName(void) const { return m_animationName; }
		void SetAnimationName(const std::string& val) { m_animationName = val; }

		float GetSpeed(void) const { return m_speed; }
		void SetSpeed(float val) { m_speed = val; }

		bool IsLoop(void) const { return m_isLoop; }
		void SetLoop(bool val) { m_isLoop = val; }
	protected:
		std::string m_animationName;
		float m_speed;
		bool m_isLoop;
	private:

	};
}

#endif // BoneAnimationData_h__

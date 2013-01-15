//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2012-12-24
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AnimationGroup_h__
#define AnimationGroup_h__

#include "ENDirection.h"
#include <string>

namespace Tools
{
	class StreamHelper;
	class AnimationData;
	class AnimationGroup
	{
	public:
		AnimationGroup(void);
		virtual ~AnimationGroup(void);

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		void Clear(void);

		AnimationData* LookupAnimation(ENDirection::Decl direction) const;
		AnimationData* CreateAnimation(ENDirection::Decl direction);
		AnimationData* ResetAnimation(ENDirection::Decl direction);
		void RemoveAnimation(ENDirection::Decl direction);

		void SetSoundEffect(const std::string &soundEffect) { m_soundEffect = soundEffect; }
		const std::string& GetSoundEffect(void) const { return m_soundEffect; }
		void SetSoundDelay(float delay) { m_soundDelay = delay; }
		float GetSoundDelay(void) const { return m_soundDelay; }
	protected:
		AnimationData* m_animationGroup[ENDirection::Count];
		std::string m_soundEffect;
		float m_soundDelay;
	private:
		enum ENVersion
		{
			enBaseVersion,
			enSoundVersion,
		};
		unsigned int m_version;
	};
}

#endif // AnimationGroup_h__

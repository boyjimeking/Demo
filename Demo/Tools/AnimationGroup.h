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
	protected:
		AnimationData* m_animationGroup[ENDirection::Count];
	private:
	};
}

#endif // AnimationGroup_h__

//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2013-1-4
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef BoneAnimationGroup_h__
#define BoneAnimationGroup_h__

#include "ENDirection.h"

namespace Tools
{
	class StreamHelper;
	class BoneAnimationData;
	class BoneAnimationGroup
	{
	public:
		BoneAnimationGroup(void);
		virtual ~BoneAnimationGroup(void);

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		void Clear(void);

		BoneAnimationData* LookupAnimation(ENDirection::Decl direction) const;
		BoneAnimationData* CreateAnimation(ENDirection::Decl direction);
		BoneAnimationData* ResetAnimation(ENDirection::Decl direction);
		void RemoveAnimation(ENDirection::Decl direction);
	protected:
		BoneAnimationData* m_animationGroup[ENDirection::Count];
	private:
	};
}

#endif // BoneAnimationGroup_h__

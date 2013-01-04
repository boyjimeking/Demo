#include "BoneAnimationGroup.h"
#include <string>
#include "StreamHelper.h"
#include "BoneAnimationData.h"

namespace Tools
{
	BoneAnimationGroup::BoneAnimationGroup(void)
	{
		memset(m_animationGroup, 0, sizeof(m_animationGroup));
	}

	BoneAnimationGroup::~BoneAnimationGroup(void)
	{
		Clear();
	}

	void BoneAnimationGroup::Read( StreamHelper *stream )
	{
		Clear();
		unsigned int mark = 0;
		stream->Read(mark);
		for (int index = 0; index < ENDirection::Count ; ++index)
		{
			if (0 == ((1 << index) & mark))
			{
				continue;
			}
			else
			{
				m_animationGroup[index] = new BoneAnimationData;
				m_animationGroup[index]->Read(stream);
			}
		}
	}

	void BoneAnimationGroup::Write( StreamHelper *stream )
	{
		unsigned int mark = 0;
		for (int index = 0; index < ENDirection::Count ; ++index)
		{
			if (NULL != m_animationGroup[index])
			{
				mark |= (1 << index);
			}
		}
		stream->Write(mark);
		for (int index = 0; index < ENDirection::Count ; ++index)
		{
			if (NULL != m_animationGroup[index])
			{
				m_animationGroup[index]->Write(stream);
			}
		}
	}

	void BoneAnimationGroup::Clear( void )
	{
		for (int index = 0; index < ENDirection::Count ; ++index)
		{
			if (NULL != m_animationGroup[index])
			{
				delete m_animationGroup[index];
				m_animationGroup[index] = NULL;
			}
		}
	}

	BoneAnimationData* BoneAnimationGroup::LookupAnimation( ENDirection::Decl direction ) const
	{
		return m_animationGroup[direction];
	}

	BoneAnimationData* BoneAnimationGroup::CreateAnimation( ENDirection::Decl direction )
	{
		if (NULL == m_animationGroup[direction])
		{
			m_animationGroup[direction] = new BoneAnimationData;
		}
		return m_animationGroup[direction];
	}

	BoneAnimationData* BoneAnimationGroup::ResetAnimation( ENDirection::Decl direction )
	{
		BoneAnimationData *anim = LookupAnimation(direction);
		if (NULL == anim)
		{
			return CreateAnimation(direction);
		}
		else
		{
			anim->Clear();
			return anim;
		}
	}

	void BoneAnimationGroup::RemoveAnimation( ENDirection::Decl direction )
	{
		delete m_animationGroup[direction];
		m_animationGroup[direction] = NULL;
	}

}
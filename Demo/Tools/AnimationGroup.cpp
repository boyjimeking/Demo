#include "AnimationGroup.h"
#include <string>
#include "StreamHelper.h"
#include "AnimationData.h"

namespace Tools
{
	AnimationGroup::AnimationGroup(void)
	{
		memset(m_animationGroup, 0, sizeof(m_animationGroup));
	}

	AnimationGroup::~AnimationGroup(void)
	{
		Clear();
	}

	void AnimationGroup::Read( StreamHelper *stream )
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
				m_animationGroup[index] = new AnimationData;
				m_animationGroup[index]->Read(stream);
			}
		}
	}

	void AnimationGroup::Write( StreamHelper *stream )
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

	void AnimationGroup::Clear( void )
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

	AnimationData* AnimationGroup::LookupAnimation( ENDirection::Decl direction ) const
	{
		return m_animationGroup[direction];
	}

	AnimationData* AnimationGroup::CreateAnimation( ENDirection::Decl direction )
	{
		if (NULL == m_animationGroup[direction])
		{
			m_animationGroup[direction] = new AnimationData;
		}
		return m_animationGroup[direction];
	}

	AnimationData* AnimationGroup::ResetAnimation( ENDirection::Decl direction )
	{
		AnimationData *anim = LookupAnimation(direction);
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

	void AnimationGroup::RemoveAnimation( ENDirection::Decl direction )
	{
		delete m_animationGroup[direction];
		m_animationGroup[direction] = NULL;
	}

}
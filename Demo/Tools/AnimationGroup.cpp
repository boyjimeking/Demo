#include "AnimationGroup.h"
#include <string>
#include "StreamHelper.h"
#include "AnimationData.h"

namespace Tools
{
	AnimationGroup::AnimationGroup(void)
		:m_soundDelay(0.0f)
		,m_version(enSoundVersion)
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
		//版本号
		unsigned int version = 0;
		stream->Read(version);

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
		if (version >= enSoundVersion)
		{
			stream->Read(m_soundEffect);
			stream->Read(m_soundDelay);
		}
	}

	void AnimationGroup::Write( StreamHelper *stream )
	{
		stream->Write(m_version);
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
		stream->Write(m_soundEffect);
		stream->Write(m_soundDelay);
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
		m_soundEffect.clear();
		m_soundDelay = 0.0f;
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
#include "EditAvatarData.h"
#include "../Tools/AnimationData.h"
#include "WorldManager.h"
#include "Actors/ActorsControl.h"
#include "Actors/ActorProp.h"
#include "../Tools/AnimationGroup.h"
#include <map>

namespace Tools
{
	EditAvatarData::EditAvatarData(void)
	{

	}

	EditAvatarData::~EditAvatarData(void)
	{

	}

	void EditAvatarData::Load( unsigned char *data, int dataLength )
	{
		Read(data, dataLength);
	}

	int EditAvatarData::Save( unsigned char *data, int dataLength )
	{
		return Write(data, dataLength);
	}

	void EditAvatarData::Create( const char *plistFile )
	{
		Clear();
		m_plist = plistFile;
	}

	void EditAvatarData::Apply( void )
	{
		Game::WorldManager::Instance()->GetActorsControl()->GetMainActor()->ChangeAvatar(this);
	}

	AnimationGroup* EditAvatarData::AddAnimationGroup(const char* type)
	{
		AnimationGroup *animGroup = Lookup(type);
		if (NULL != animGroup)
		{
			return animGroup;
		}
		else
		{
			animGroup = new AnimationGroup;
			m_animationTable.insert(std::make_pair(type, animGroup));
			return animGroup;
		}
	}

	void EditAvatarData::RemoveAnimationGroup(const char* type)
	{
		AnimationTable::iterator it = m_animationTable.find(type);
		if (m_animationTable.end() == it)
		{
			return;
		}
		else
		{
			delete it->second;
			m_animationTable.erase(it);
		}
	}
	void EditAvatarData::SetFrameList( const char *frameList )
	{
		m_frameList = frameList;
	}

}
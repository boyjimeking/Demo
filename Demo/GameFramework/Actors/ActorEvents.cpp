//
//  ActorEvents.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "ActorEvents.h"

namespace Game
{

	ActorEventCreate::ActorEventCreate( ENActorType::Decl type )
		: m_type(type)
	{

	}


	ActorEventChangePos::ActorEventChangePos( const cocos2d::CCPoint &worldPos )
		: m_targetPos(worldPos)
	{

	}



	ActorEventChangeAvatar::ActorEventChangeAvatar( Tools::AvatarData *avatar )
		: m_avatar(avatar)
	{

	}

}
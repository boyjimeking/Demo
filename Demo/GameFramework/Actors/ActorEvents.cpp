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


	ActorEventChangePos::ActorEventChangePos( const CCPoint &worldPos )
		: m_targetPos(worldPos)
	{

	}



	ActorEventChangeAvatar::ActorEventChangeAvatar( AvatarData *avatar )
		: m_avatar(avatar)
	{

	}

}
//
//  ActorsControlEvents.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "ActorsControlEvents.h"

namespace Game
{
	ActorsControlEventCreateActor::ActorsControlEventCreateActor(ActorEntity *entity, const char *layerName)
		:m_entity(entity)
		,m_layerName(layerName)
	{

	}
}
//
//  ActorTouch.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-6.
//
//

#include "ActorTouch.h"
#include "WorldManager.h"
#include "ActorsControl.h"
#include "ActorProp.h"
#include "ActorAction.h"
#include "Client/Client.h"

namespace Game
{
	TouchMonster::TouchMonster(ActorProp *prop)
	:m_prop(prop)
	{

	}
	bool TouchMonster::OnTouch(const cocos2d::CCPoint &pos)
	{
		WorldManager::Instance()->GetActorsControl()->GetMainActor()->StartAttack(m_prop);
		return true;
	}
}
//
//  ActorActions.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#include "ActorActions.h"
#include "WorldManager.h"
#include "Camera/Camera.h"

namespace Game
{
	MainActor_Move* MainActor_Move::create(float duration, const cocos2d::CCPoint &position)
	{
		MainActor_Move *action = new MainActor_Move;
		action->initWithDuration(duration, position);
		action->autorelease();
		return action;
	}

	void MainActor_Move::update(float time)
	{
		cocos2d::CCMoveTo::update(time);
		if (NULL != m_pTarget)
		{
			WorldManager::Instance()->GetCamera()->SetPosition(m_pTarget->getPosition());
		}
	}
}
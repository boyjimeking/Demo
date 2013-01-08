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
#include "UI/UIControl.h"
#include "UI/UITargetProp.h"
#include "UI/UITargetWindow.h"

namespace Game
{
	TouchMonster::TouchMonster(ActorProp *prop)
	:m_prop(prop)
	{

	}
	bool TouchMonster::OnTouch(const CCPoint &pos)
	{
		WorldManager::Instance()->GetActorsControl()->GetMainActor()->StartAttack(m_prop);
		GUI::UIProperty *uiProp = WorldManager::Instance()->GetUIControl()->GetWindow("Target");
		if (NULL == uiProp)
		{
			uiProp = WorldManager::Instance()->GetUIControl()->CreateUI<GUI::UITargetProp, GUI::UITargetWindow>("Target");
		}
		m_prop->AttachUI(uiProp);
		return true;
	}
}
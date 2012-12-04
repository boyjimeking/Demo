//
//  PhysicalControl.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-4.
//
//

#include "PhysicalControl.h"
#include "Box2D/Box2D.h"
#include "PhysicalObj.h"
#include "support/CCPointExtension.h"

namespace Game
{
	PhysicalControl::PhysicalControl(void)
	:m_box2dWorld(new b2World(b2Vec2(0.0f, 0.0f)))
	,m_ground(NULL)
	{
		m_box2dWorld->SetAllowSleeping(true);
	}
	PhysicalControl::~PhysicalControl(void)
	{

	}
	void PhysicalControl::Update(float dt)
	{
		if (NULL == m_box2dWorld)
    	{
    		return;
    	}
    	m_box2dWorld->Step(dt, 8, 8);
    	for (b2Body *body = m_box2dWorld->GetBodyList(); NULL != body; body = body->GetNext())
    	{
    		if (NULL != body->GetUserData())
    		{
    			PhysicalObj *obj = (PhysicalObj*)(body->GetUserData());
    			obj->SetPosition(ccp(body->GetPosition().x * PTM_RATIO, body->GetPosition().y * PTM_RATIO));
    		}
    	}
	}
}
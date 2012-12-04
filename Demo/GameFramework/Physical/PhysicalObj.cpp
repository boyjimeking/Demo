//
//  PhysicalObj.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-4.
//
//

#include "PhysicalObj.h"
#include "Box2D/Box2D.h"
#include "WorldManager.h"
#include "PhysicalControl.h"
namespace Game
{
	PhysicalObj::PhysicalObj(void)
	:m_body(NULL)
	{
		b2BodyDef bodyDef;
		bodyDef.position.Set(0.0f, 0.0f);
		m_body = WorldManager::Instance()->GetPhysicalControl()->GetBox2DWorld()->CreateBody(&bodyDef);
	}
	PhysicalObj::~PhysicalObj(void)
	{
		m_body = NULL;
	}

	void PhysicalObj::SetPosition(const cocos2d::CCPoint &pos)
	{
		if (m_setPosition)
		{
			m_setPosition(pos);
		}
	}
}
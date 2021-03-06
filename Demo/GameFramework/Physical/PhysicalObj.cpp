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
#include "support/CCPointExtension.h"
#include "platform/CCCommon.h"
namespace Game
{
	PhysicalObj::PhysicalObj(void)
	:m_body(NULL)
	,m_targetPosition(cocos2d::CCPointZero)
	{
		b2BodyDef bodyDef;
		bodyDef.position.Set(0.0f, 0.0f);
		bodyDef.type = b2_dynamicBody;
		m_body = WorldManager::Instance()->GetPhysicalControl()->GetBox2DWorld()->CreateBody(&bodyDef);

		b2PolygonShape dynamicBox;
		dynamicBox.SetAsBox(1.0f, 2.0f);

		b2FixtureDef fixtureDef;
		fixtureDef.shape = &dynamicBox;
		fixtureDef.density = 1.0f;//质量
		fixtureDef.friction = 0.3f;//摩擦系数

		m_body->CreateFixture(&fixtureDef);

		m_body->SetUserData(this);

		m_body->SetAwake(false);
	}
	PhysicalObj::~PhysicalObj(void)
	{
		m_body = NULL;
	}

	void PhysicalObj::SetBodyPos(const cocos2d::CCPoint &pos)
	{
		m_body->SetTransform(b2Vec2(pos.x / PTM_RATIO, pos.y / PTM_RATIO), m_body->GetAngle());
	}
	void PhysicalObj::SetPosition(const cocos2d::CCPoint &pos)
	{
		if (!m_body->IsAwake())
		{
			return;
		}
		if (cocos2d::ccpDistanceSQ(m_targetPosition, m_prePosition) <= cocos2d::ccpDistanceSQ(pos, m_prePosition))
		{
			if (m_stopFunc)
			{
				m_stopFunc(m_targetPosition);
			}
			else if (m_setPosition)
			{
				m_setPosition(m_targetPosition);
			}
			m_body->SetAwake(false);
		}
		else
		{
			if (m_setPosition)
			{
				m_setPosition(pos);
			}
		}
	}
	void PhysicalObj::Move(const cocos2d::CCPoint &from, const cocos2d::CCPoint &to)
	{
		if (cocos2d::ccpDistanceSQ(from, to) < 0.1f)
		{
			return;
		}
		m_body->SetAwake(false);
		b2Vec2 impulse = b2Vec2(to.x - from.x, to.y - from.y);//求方向，所以不对坐标进行缩放
		impulse.Normalize();
		impulse *= 100.0f;
		m_body->ApplyLinearImpulse(impulse, m_body->GetWorldCenter());
		m_targetPosition = to;
		m_prePosition = from;
	}
}

namespace boost
{
	void throw_exception(std::exception const&) {}
}
//
//  GridProp.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#include "GridProp.h"
#include "platform/CCCommon.h"
#include "GridEvents.h"

namespace Game
{
	GridProp::GridProp(void)
		:m_id(0)
	{

	}
	GridProp::~GridProp(void)
	{

	}

	void GridProp::Init( int id, const char *imageName, float x, float y, float width, float height )
	{
		m_id = id;
		m_imageName = imageName;
		m_position = cocos2d::CCPointMake(x, y);
		m_size = cocos2d::CCSizeMake(width, height);

		GridEventInit event(m_imageName, m_position, m_size);
		NotifyChange(&event);
	}

	void GridProp::Remove( void )
	{
		GridEventRemove event;
		NotifyChange(&event);
	}


}
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
		:m_x(0)
		,m_y(0)
	{

	}
	GridProp::~GridProp(void)
	{

	}
	void GridProp::Load(const char *gridName, float posX, float posY)
	{
		m_x = posX;
		m_y = posY;
		GridEvent_Load event(gridName, posX, posY);
		NotifyChange(&event);
	}

	void GridProp::Release( void )
	{
		GridEvent_Release event;
		NotifyChange(&event);
	}

}
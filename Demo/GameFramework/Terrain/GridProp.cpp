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
	:m_width(690)
	,m_height(770)
	{

	}
	GridProp::~GridProp(void)
	{

	}
	void GridProp::Load(const char *gridName, int posX, int posY)
	{
		cocos2d::CCLog("GridProp::Load %s", gridName);

		GridEvent_Load event(gridName, m_width, m_height, posX, posY);
		NotifyChange(&event);
	}
}
//
//  GridEvents.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#include "GridEvents.h"

namespace Game
{


	GridEventInit::GridEventInit(int id, const std::string &imageName, const cocos2d::CCPoint &position, const cocos2d::CCSize &size)
		:m_imageName(imageName)
		,m_position(position)
		,m_size(size)
		,m_id(id)
	{

	}

}
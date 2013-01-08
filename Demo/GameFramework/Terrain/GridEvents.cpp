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


	GridEventInit::GridEventInit( const std::string &imageName, const CCPoint &position, const CCSize &size )
		:m_imageName(imageName)
		,m_position(position)
		,m_size(size)
	{

	}

}
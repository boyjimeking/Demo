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
	GridEvent_Load::GridEvent_Load(const char *imageName, int width, int height, int posX, int posY)
	:m_imageName(imageName)
	,m_width(width)
	,m_height(height)
	,m_posX(posX)
	,m_posY(posY)
	{

	}
}
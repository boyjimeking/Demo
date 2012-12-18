//
//  SceneObjectEvents.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-11.
//
//

#include "SceneObjectEvents.h"

Game::SceneObjectEventInit::SceneObjectEventInit( const std::string &imageName, const cocos2d::CCPoint &position, const cocos2d::CCSize &size )
	:m_imageName(imageName)
	,m_position(position)
	,m_size(size)
{

}

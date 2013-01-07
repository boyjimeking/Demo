//
//  CameraNotifyEvents.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//
//

#include "CameraNotifyEvents.h"
namespace Game
{
	CameraPosChanged::CameraPosChanged( const cocos2d::CCPoint &pos )
		:m_pos(pos)
	{

	}

	CameraScaleChanged::CameraScaleChanged( float scale )
		:m_scale(scale)
	{

	}


	CameraReset::CameraReset( const cocos2d::CCPoint &pos )
		:m_pos(pos)
	{

	}

}

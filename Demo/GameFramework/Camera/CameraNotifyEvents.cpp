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
	CameraPosChanged::CameraPosChanged( const CCPoint &pos )
		:m_pos(pos)
	{

	}

	CameraScaleChanged::CameraScaleChanged( float scale )
		:m_scale(scale)
	{

	}


	CameraReset::CameraReset( const CCPoint &pos )
		:m_pos(pos)
	{

	}

}

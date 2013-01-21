//
//  GridEvents.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__GridEvents__
#define __Demo__GridEvents__

#include "../Base/INotifyEvent.h"
#include <string>
#include "cocoa/CCGeometry.h"

namespace Game
{
	struct ENGridEventType
	{
		enum
		{
			enError,
			enInitGrid,
			enRemoveGrid,
		};
	};

	struct GridEventInit
		:public INotifyEvent
	{
		virtual int GetNotifyEventType( void ) const { return ENGridEventType::enInitGrid; }
		GridEventInit(int id, const std::string &imageName, const cocos2d::CCPoint &position, const cocos2d::CCSize &size);

		const int m_id;
		const std::string &m_imageName;
		const cocos2d::CCPoint &m_position;
		const cocos2d::CCSize &m_size;
	};

	struct GridEventRemove
		:public INotifyEvent
	{
		virtual int GetNotifyEventType( void ) const { return ENGridEventType::enRemoveGrid; }
	};
}

#endif /* defined(__Demo__GridEvents__) */

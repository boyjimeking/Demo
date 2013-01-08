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

USING_NS_CC;

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
		GridEventInit(const std::string &imageName, const CCPoint &position, const CCSize &size);

		const std::string &m_imageName;
		const CCPoint &m_position;
		const CCSize &m_size;
	};

	struct GridEventRemove
		:public INotifyEvent
	{
		virtual int GetNotifyEventType( void ) const { return ENGridEventType::enRemoveGrid; }
	};
}

#endif /* defined(__Demo__GridEvents__) */

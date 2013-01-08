//
//  GridEntity.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__GridEntity__
#define __Demo__GridEntity__

#include "../Base/IObserver.h"
#include "sprite_nodes/CCSprite.h"

USING_NS_CC;

namespace Game
{
	class GridEntity
		:public CCSprite
		,public IObserver
	{
	public:
		GridEntity(void);
		virtual ~GridEntity(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
	
	protected:
	};
}

#endif /* defined(__Demo__GridEntity__) */

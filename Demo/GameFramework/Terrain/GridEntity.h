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

namespace Game
{
	class GridEntity
		:public cocos2d::CCSprite
		,public IObserver
	{
	public:
		GridEntity(void);
		virtual ~GridEntity(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
	
	protected:
		void OnImageLoaded(cocos2d::CCObject *obj);
	};
}

#endif /* defined(__Demo__GridEntity__) */

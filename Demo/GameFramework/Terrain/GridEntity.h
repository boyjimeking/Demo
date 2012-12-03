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

		virtual void OnNotifyChange( const INotifier *notify, const INotifyEvent *event );
	
	protected:
		void Load(const char *imageName, int width, int height, int posX, int posY);
	};
}

#endif /* defined(__Demo__GridEntity__) */

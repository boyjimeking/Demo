//
//  ActorActions.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__ActorActions__
#define __Demo__ActorActions__

#include "actions/CCActionInterval.h"

namespace Game
{
	class MainActor_Move
		:public cocos2d::CCMoveTo
	{
	public:
		static MainActor_Move* create(float duration, const cocos2d::CCPoint &position);
	
		virtual void update(float time);
	private:

	};
}

#endif /* defined(__Demo__ActorActions__) */

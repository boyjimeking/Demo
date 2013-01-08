//
//  ActorTouch.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-6.
//
//

#ifndef __Demo__ActorTouch__
#define __Demo__ActorTouch__

#include "cocoa/CCGeometry.h"
using namespace cocos2d;
namespace Game
{
	class ITouch
	{
	public:
		virtual bool OnTouch(const CCPoint &pos) = 0;
		virtual ~ITouch(){}
	
	private:
	};

	class ActorProp;
	class TouchMonster
		:public ITouch
	{
	public:
		TouchMonster(ActorProp *prop);
		virtual bool OnTouch(const CCPoint &pos);
	private:
		ActorProp *m_prop;
	};
}

#endif /* defined(__Demo__ActorTouch__) */

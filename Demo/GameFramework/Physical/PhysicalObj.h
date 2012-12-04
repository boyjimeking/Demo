//
//  PhysicalObj.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-4.
//
//

#ifndef __Demo__PhysicalObj__
#define __Demo__PhysicalObj__

#include <boost/function.hpp>
#include "boost/bind.hpp"
#include "cocoa/CCGeometry.h"

#ifndef PTM_RATIO
#define PTM_RATIO 32
#endif

class b2Body;

namespace Game
{
	typedef boost::function<void(const cocos2d::CCPoint &)> PositionFunc;
	//物理引擎与逻辑部分的适配器，用于box2d中b2body->GetUserDate()使用
	class PhysicalObj
	{
	public:
		PhysicalObj(void);
		~PhysicalObj(void);

		void SetPosition(const cocos2d::CCPoint &pos);
	
		void SetPositionFunc(const PositionFunc &func) { m_setPosition = func; }
	private:
		PositionFunc m_setPosition;
		b2Body *m_body;
	};

}

#endif /* defined(__Demo__PhysicalObj__) */

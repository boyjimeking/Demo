//
//  MainScene.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#ifndef __Demo__MainScene__
#define __Demo__MainScene__

#include "layers_scenes_transitions_nodes/CCScene.h"
using namespace cocos2d;
namespace Game
{
	class MainScene
		:public CCScene
	{
	public:
		static MainScene* create();
	
		virtual void update(float dt);
	private:
	};
}

#endif /* defined(__Demo__MainScene__) */

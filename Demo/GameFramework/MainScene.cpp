//
//  MainScene.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-3.
//
//

#include "MainScene.h"
#include "WorldManager.h"
#include "ClNetMng.h"

namespace Game
{
	MainScene* MainScene::create(void)
	{
		MainScene *pRet = new MainScene();
	    if (pRet && pRet->init())
	    {
	    	pRet->scheduleUpdate();
	        pRet->autorelease();
	        return pRet;
	    }
	    else
	    {
	        CC_SAFE_DELETE(pRet);
	        return NULL;
	    }
	}

	void MainScene::update(float dt)
	{
		WorldManager::Instance()->update(dt);
		//handle messages
        CClNetMng::Instance()->HandleMsgs();
 
	}
}
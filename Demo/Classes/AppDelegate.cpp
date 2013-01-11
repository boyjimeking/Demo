//
//  DemoAppDelegate.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-11-29.
//  Copyright __MyCompanyName__ 2012年. All rights reserved.
//

#include "AppDelegate.h"
#include "AppMacros.h"
#include "cocos2d.h"
#include "WorldManager.h"
#include "../GameFramework/Client/CClient.h"
#include "../GameFramework/Client/ClNetMng.h"

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    //pDirector->enableRetinaDisplay(true);
    designResolutionSize.width=960;
    designResolutionSize.height=640;
    pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
    
	CCSize frameSize = pEGLView->getFrameSize();
    
    // In this demo, we select resource according to the frame's height.
    // If the resource size is different from design resolution size, you need to set contentScaleFactor.
    // We use the ratio of resource's height to the height of design resolution,
    // this can make sure that the resource's height could fit for the height of design resolution.
    
    // if the frame's height is larger than the height of medium resource size, select large resource.
	if (frameSize.height > mediumResource.size.height)
	{
		CCFileUtils::sharedFileUtils()->setResourceDirectory(largeResource.directory);
        pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
    // if the frame's height is larger than the height of small resource size, select medium resource.
    else if (frameSize.height > smallResource.size.height)
    {
        CCFileUtils::sharedFileUtils()->setResourceDirectory(mediumResource.directory);
        pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
    // if the frame's height is smaller than the height of medium resource size, select small resource.
	else
    {
		CCFileUtils::sharedFileUtils()->setResourceDirectory(smallResource.directory);
        pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }
    pDirector->setContentScaleFactor(1.0f);
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = Game::WorldManager::Instance()->Init();

    // run
    pDirector->runWithScene(pScene);

    //网络端的初始化
    CClNetMng::Instance()->Init();
    Game::WorldManager::Instance()->GetClient()->Login("111", "111");
    
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be paused
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

#include "UILayer.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "CCDirector.h"

namespace GUI
{
	UILayer* UILayer::create( void )
	{
		UILayer *pRet = new UILayer();
		if (pRet && pRet->init())
		{
			pRet->setTouchEnabled(true);
			pRet->autorelease();
			return pRet;
		}
		else
		{
			CC_SAFE_DELETE(pRet);
			return NULL;
		}
	}

	UILayer::UILayer(void)
	{

	}
	UILayer::~UILayer(void)
	{

	}

	void UILayer::OnNotifyChange( const INotifier *notify, const INotifyEvent *event )
	{
	}

	void UILayer::ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent)
	{
		cocos2d::CCLayer::ccTouchesBegan(pTouches, pEvent);
		cocos2d::CCTouch *touch = reinterpret_cast<cocos2d::CCTouch*>(*pTouches->begin());
		cocos2d::CCPoint pos = touch->getLocation();
	}
	void UILayer::registerWithTouchDispatcher()
	{
		cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, -1);
	}
}
#include "UILayer.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "CCDirector.h"
#include "UIControlEvents.h"
#include "platform/CCFileUtils.h"

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

	void UILayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
		switch (event->GetNotifyEventType())
		{
			case ENUIControlEvent::enInit:
				{
					const char* filePath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Icon.png");
					cocos2d::CCSprite *sprite = cocos2d::CCSprite::create(filePath);
					this->addChild(sprite);
					sprite->setPosition(cocos2d::CCPointMake(getContentSize().width - 32.0f, 32.0f));
				}
				break;
			default:
				break;
		}
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
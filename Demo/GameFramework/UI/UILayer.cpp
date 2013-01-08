#include "UILayer.h"
#include "touch_dispatcher/CCTouchDispatcher.h"
#include "CCDirector.h"
#include "UIControlEvents.h"
#include "platform/CCFileUtils.h"
#include "UIWindow.h"

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
					const char* filePath = CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("Icon.png");
					CCSprite *sprite = CCSprite::create(filePath);
					this->addChild(sprite);
					sprite->setPosition(CCPointMake(getContentSize().width - 32.0f, 32.0f));
				}
				break;
			case ENUIControlEvent::enCreateWindow:
				{
					CCNode *node = reinterpret_cast<const UIControlEventCreateWindow*>(event)->m_window->GetWindow();
					this->addChild(node);
				}
				break;
			default:
				break;
		}
	}

	void UILayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
	{
		CCLayer::ccTouchesBegan(pTouches, pEvent);
		CCTouch *touch = reinterpret_cast<CCTouch*>(*pTouches->begin());
		CCPoint pos = touch->getLocation();
	}
	void UILayer::registerWithTouchDispatcher()
	{
		CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, -1);
	}
}
//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/UI/UILayer.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UILayer_h__
#define UILayer_h__

#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "../Base/IObserver.h"

namespace GUI
{
	class UILayer
		:public cocos2d::CCLayer
		,public IObserver
	{
	public:
		static UILayer* create(void);
		UILayer(void);
		virtual ~UILayer(void);

		virtual void OnNotifyChange( const INotifier *notify, const INotifyEvent *event );

		virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);

    	virtual void registerWithTouchDispatcher(void);
	protected:
	private:
	};
}

#endif // UILayer_h__

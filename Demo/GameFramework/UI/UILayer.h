//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/UI/UILayer.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UILayer_h__
#define UILayer_h__

#include "layers_scenes_transitions_nodes/CCLayer.h"
#include "../Base/IObserver.h"
USING_NS_CC;
namespace GUI
{
	class UILayer
		:public CCLayer
		,public IObserver
	{
	public:
		static UILayer* create(void);
		UILayer(void);
		virtual ~UILayer(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

		virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);

    	virtual void registerWithTouchDispatcher(void);
	protected:
	private:
	};
}

#endif // UILayer_h__

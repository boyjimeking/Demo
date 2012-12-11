//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/BuildingManager/BuildingsLayer.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef BuildingsLayer_h__
#define BuildingsLayer_h__

#include "../Base/IObserver.h"

namespace cocos2d
{
	class CCLayer;
}

namespace Game
{
	/*
	 *	建筑层，用于在场景中组织及显示建筑
	 */
	class BuildingsLayer
		:public IObserver
	{
	public:
		BuildingsLayer(cocos2d::CCLayer *entityLayer);
		~BuildingsLayer(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

	protected:
	private:
		cocos2d::CCLayer *m_entityLayer;
	};
}

#endif // BuildingsLayer_h__

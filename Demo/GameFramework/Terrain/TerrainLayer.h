//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/Terrain/TerrainLayer.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef TerrainLayer_h__
#define TerrainLayer_h__

#include "../Base/IObserver.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"

namespace Game
{
	/*
	 *	地形层，用于在场景中显示地形及接受场景消息反馈
	 */
	class TerrainLayer
		:public cocos2d::CCLayer
		,public IObserver
	{
	public:
		static TerrainLayer* create(void);
		TerrainLayer(void);
		virtual ~TerrainLayer(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

    	virtual void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
	protected:
		void ProcessMainActorMove(const cocos2d::CCPoint &screenPos);
	private:
	};
}

#endif // TerrainLayer_h__

//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/Terrain/TerrainLayer.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef TerrainLayer_h__
#define TerrainLayer_h__

#include "../Base/IObserver.h"
#include "base_nodes/CCNode.h"

USING_NS_CC;

namespace Game
{
	/*
	 *	地形层，用于在场景中显示地形及接受场景消息反馈
	 */
	class TerrainLayer
		:public CCNode
		,public IObserver
	{
	public:
		static TerrainLayer* create(void);
		TerrainLayer(void);
		virtual ~TerrainLayer(void);

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );
	protected:
	private:
	};
}

#endif // TerrainLayer_h__

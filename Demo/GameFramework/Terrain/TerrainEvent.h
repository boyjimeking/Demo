//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/Terrain/TerrainEvent.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef TerrainEvent_h__
#define TerrainEvent_h__

#include "../Base/INotifyEvent.h"

namespace Game
{
	struct ENTerrainEventType
	{
		enum
		{
			enError,
			enAddTerrain,
		};
	};

	class GridEntity;
	struct TerrainEvent_AddTerrain
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENTerrainEventType::enAddTerrain; }
		TerrainEvent_AddTerrain(GridEntity *entity, const char *layerName) : m_eneity(entity), m_layerName(layerName) {}
		GridEntity *m_eneity;
		const char *m_layerName;
	};
}

#endif // TerrainEvent_h__

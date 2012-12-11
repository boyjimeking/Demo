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
			enTerrainEvent_LoadTerrain,
		};
	};

	class GridEntity;
	struct TerrainEvent_LoadTerrain
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENTerrainEventType::enTerrainEvent_LoadTerrain; }

		TerrainEvent_LoadTerrain(GridEntity **entityArray, int length) : m_entityArray(entityArray), m_length(length) {}

		GridEntity* GetEntity(int index) const { return m_entityArray[index]; }
		int GetLength(void) const { return m_length; }
	private:
		GridEntity **m_entityArray;
		int m_length;
	};
}

#endif // TerrainEvent_h__

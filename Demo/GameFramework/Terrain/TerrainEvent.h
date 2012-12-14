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
			enLoadTerrain,
			enAddTerrain,
		};
	};

	class GridEntity;
	struct TerrainEvent_LoadTerrain
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENTerrainEventType::enLoadTerrain; }

		TerrainEvent_LoadTerrain(int length) : m_entityArray(new GridEntity*[length]), m_length(length) {}
		~TerrainEvent_LoadTerrain(void) { delete[] m_entityArray; }

		GridEntity* GetEntity(int index) const { return m_entityArray[index]; }
		int GetLength(void) const { return m_length; }

		GridEntity **m_entityArray;
		int m_length;
	};
	struct TerrainEvent_AddTerrain
		:public INotifyEvent
	{
		virtual int GetNotifyEventType(void) const { return ENTerrainEventType::enAddTerrain; }
		TerrainEvent_AddTerrain(GridEntity *entity) : m_eneity(entity){}
		GridEntity *m_eneity;
	};
}

#endif // TerrainEvent_h__

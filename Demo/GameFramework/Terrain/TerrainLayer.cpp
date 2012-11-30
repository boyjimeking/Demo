#include "TerrainLayer.h"
#include "../Base/INotifier.h"
#include "support/CCPointExtension.h"
#include "sprite_nodes/CCSprite.h"
#include "CCDirector.h"
#include "TerrainEvent.h"

namespace Game
{
	TerrainLayer* TerrainLayer::create( void )
	{
		TerrainLayer *pRet = new TerrainLayer();
		if (pRet && pRet->init())
		{
			pRet->autorelease();
			return pRet;
		}
		else
		{
			CC_SAFE_DELETE(pRet);
			return NULL;
		}
	}

	TerrainLayer::TerrainLayer(void)
	{
		
	}
	TerrainLayer::~TerrainLayer(void)
	{

	}

	void TerrainLayer::Init( void )
	{

	}

	void TerrainLayer::OnNotifyChange( const INotifier *notify, const INotifyEvent *event )
	{
		if (NULL == event)
		{
			return;
		}
		switch (event->GetNotifyEventType())
		{
		default:
			break;
		}
	}

}
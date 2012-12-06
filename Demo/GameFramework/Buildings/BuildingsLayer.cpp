#include "BuildingsLayer.h"
#include "layers_scenes_transitions_nodes/CCLayer.h"

namespace Game
{
	BuildingsLayer::BuildingsLayer(cocos2d::CCLayer *entityLayer)
		:m_entityLayer(entityLayer)
	{

	}
	BuildingsLayer::~BuildingsLayer(void)
	{

	}

	void BuildingsLayer::OnNotifyChange( INotifier *notify, const INotifyEvent *event )
	{
	}

}
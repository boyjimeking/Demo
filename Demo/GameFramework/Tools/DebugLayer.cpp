#include "DebugLayer.h"
#include "Buildings/SceneControl.h"
#include "CCDrawingPrimitives.h"
#include "ccTypes.h"
#include "WorldManager.h"

namespace Tools
{
	DebugLayer::DebugLayer(void)
	{

	}

	DebugLayer::~DebugLayer(void)
	{

	}

	void DebugLayer::draw( void )
	{
		Game::SceneControl *scene = Game::WorldManager::Instance()->GetSceneControl();
		for (int index = 0; index < scene->GetRow() ; ++index)
		{
			for (int innerIndex = 0; innerIndex < scene->GetColumn(); ++innerIndex)
			{
				if (scene->GetGrid(innerIndex, index))
				{
					cocos2d::ccDrawSolidRect(cocos2d::CCPointMake(innerIndex * scene->GetGridSize(), index * scene->GetGridSize())
						, cocos2d::CCPointMake((innerIndex + 1) * scene->GetGridSize() - 1, (index + 1) * scene->GetGridSize() - 1), cocos2d::ccc4f(0.0f, 0.0f, 1.0f, 0.05f));
				}
				else
				{
					cocos2d::ccDrawSolidRect(cocos2d::CCPointMake(innerIndex * scene->GetGridSize(), index * scene->GetGridSize())
						, cocos2d::CCPointMake((innerIndex + 1) * scene->GetGridSize() - 1, (index + 1) * scene->GetGridSize() - 1), cocos2d::ccc4f(1.0f, 0.0f, 0.0f, 0.05f));
				}
			}
		}
	}

}
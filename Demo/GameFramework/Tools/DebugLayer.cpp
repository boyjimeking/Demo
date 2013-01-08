#include "DebugLayer.h"
#include "SceneObjects/SceneObjectsControl.h"
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
		//Game::SceneObjectsControl *scene = Game::WorldManager::Instance()->GetSceneObjectsControl();
		//for (int index = 0; index < scene->GetRow() ; ++index)
		//{
		//	for (int innerIndex = 0; innerIndex < scene->GetColumn(); ++innerIndex)
		//	{
		//		if (scene->GetGrid(innerIndex, index))
		//		{
		//			ccDrawSolidRect(CCPointMake(innerIndex * scene->GetGridSize(), index * scene->GetGridSize())
		//				, CCPointMake((innerIndex + 1) * scene->GetGridSize() - 1, (index + 1) * scene->GetGridSize() - 1), ccc4f(0.0f, 0.0f, 1.0f, 0.05f));
		//		}
		//		else
		//		{
		//			ccDrawSolidRect(CCPointMake(innerIndex * scene->GetGridSize(), index * scene->GetGridSize())
		//				, CCPointMake((innerIndex + 1) * scene->GetGridSize() - 1, (index + 1) * scene->GetGridSize() - 1), ccc4f(1.0f, 0.0f, 0.0f, 0.05f));
		//		}
		//	}
		//}
	}

}
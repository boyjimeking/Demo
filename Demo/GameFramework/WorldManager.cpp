#include "WorldManager.h"
#include "MainScene.h"
#include "Terrain/TerrainLayer.h"
#include "Terrain/TerrainProp.h"
#include "Actors/ActorsLayer.h"
#include "Actors/ActorsControl.h"
#include "Actors/ActorProp.h"
#include "Buildings/BuildingsLayer.h"
#include "Buildings/BuildingsControl.h"
#include "UI/UILayer.h"
#include "UI/UIControl.h"
#include "Camera/Camera.h"
#include "CCDirector.h"
#include "support/CCPointExtension.h"
#include "Physical/PhysicalObj.h"
#include "Physical/PhysicalControl.h"

namespace Game
{
	WorldManager* WorldManager::Instance()
	{
		static WorldManager *_ins = new WorldManager;
		return _ins;
	}


	WorldManager::WorldManager(void)
		:m_terrain(NULL)
		,m_ActorsControl(NULL)
		,m_buildingsControl(NULL)
		,m_uiControl(NULL)
        ,m_camera(NULL)
        ,m_physicalControl(NULL)
	{

	}
	WorldManager::~WorldManager(void)
	{
		delete m_physicalControl;
		delete m_camera;
		delete m_uiControl;
		delete m_buildingsControl;
		delete m_ActorsControl;
		delete m_terrain;
	}

	cocos2d::CCScene* WorldManager::CreateScene()
	{
		MainScene *scene = MainScene::create();
		//Box2D
		{
			m_physicalControl = new PhysicalControl;
		}
        //摄像机
        {
            m_camera = new Camera;
            m_camera->init(scene);
        }
		//地形
		{
			TerrainLayer *terrainLayer = TerrainLayer::create();
			m_terrain = new TerrainProp;
			m_terrain->AttachObserver(terrainLayer);
			scene->addChild(terrainLayer);
			//测试地表
			m_terrain->Load("TestTerrain", "terrain");
		}
		cocos2d::CCLayer *entityLayer = cocos2d::CCLayer::create();
		//建筑
		{
			BuildingsLayer *buildingsLayer = new BuildingsLayer(entityLayer);
			m_buildingsControl = new BuildingsControl;
			m_buildingsControl->AttachObserver(buildingsLayer);
		}
		//角色
		{
			ActorsLayer *actorsLayer = new ActorsLayer(entityLayer);
			m_ActorsControl = new ActorsControl;
			m_ActorsControl->AttachObserver(actorsLayer);
			//测试用角色
			m_ActorsControl->CreateActor(1, true);
		}
		scene->addChild(entityLayer);
		//UI
		{
			GUI::UILayer *uiLayer = GUI::UILayer::create();
			m_uiControl = new GUI::UIControl;
			m_uiControl->AttachObserver(uiLayer);
			scene->addChild(uiLayer);
		}
		return scene;
	}
	cocos2d::CCPoint WorldManager::WorldPosToScreen(const cocos2d::CCPoint &worldPos)
	{
		return Instance()->GetCamera()->ConvertWorldPosToScreen(worldPos);
	}
    cocos2d::CCPoint WorldManager::ScreenPosToWorld(const cocos2d::CCPoint &screenPos)
    {
    	return Instance()->GetCamera()->ConvertScreenPosToWorld(screenPos);
    }
    void WorldManager::update(float dt)
    {
    	GetPhysicalControl()->Update(dt);
    }
}
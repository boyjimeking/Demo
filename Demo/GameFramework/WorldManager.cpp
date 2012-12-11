#include "WorldManager.h"
#include "MainScene.h"
#include "Terrain/TerrainLayer.h"
#include "Terrain/TerrainProp.h"
#include "Actors/ActorsLayer.h"
#include "Actors/ActorsControl.h"
#include "Actors/ActorProp.h"
#include "Buildings/BuildingsLayer.h"
#include "Buildings/SceneControl.h"
#include "UI/UILayer.h"
#include "UI/UIControl.h"
#include "Camera/Camera.h"
#include "CCDirector.h"
#include "support/CCPointExtension.h"
#include "Physical/PhysicalObj.h"
#include "Physical/PhysicalControl.h"
#include "Client/Client.h"

namespace Game
{
	WorldManager* WorldManager::Instance()
	{
		static WorldManager *_ins = new WorldManager;
		return _ins;
	}


	WorldManager::WorldManager(void)
		:m_terrain(NULL)
		,m_actorsControl(NULL)
		,m_sceneControl(NULL)
		,m_uiControl(NULL)
        ,m_camera(NULL)
        ,m_physicalControl(NULL)
        ,m_client(new Net::Client)
	{

	}
	WorldManager::~WorldManager(void)
	{
		delete m_physicalControl;
		delete m_camera;
		delete m_uiControl;
		delete m_sceneControl;
		delete m_actorsControl;
		delete m_terrain;
		delete m_client;
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
		}
		cocos2d::CCLayer *entityLayer = cocos2d::CCLayer::create();
		//建筑
		{
			BuildingsLayer *buildingsLayer = new BuildingsLayer(entityLayer);
			m_sceneControl = new SceneControl;
			m_sceneControl->AttachObserver(buildingsLayer);
            m_sceneControl->Load("scene.bin");
		}
		//角色
		{
			ActorsLayer *actorsLayer = new ActorsLayer(entityLayer);
			m_actorsControl = new ActorsControl;
			m_actorsControl->AttachObserver(actorsLayer);
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
	cocos2d::CCPoint WorldManager::WorldPosToDesign(const cocos2d::CCPoint &worldPos)
	{
		return Instance()->GetCamera()->ConvertWorldPosToDesign(worldPos);
	}
    cocos2d::CCPoint WorldManager::DesignPosToWorld(const cocos2d::CCPoint &screenPos)
    {
    	return Instance()->GetCamera()->ConvertDesignPosToWorld(screenPos);
    }
    void WorldManager::update(float dt)
    {
    	GetActorsControl()->Tick(dt);
    	GetPhysicalControl()->Update(dt);
    }
}
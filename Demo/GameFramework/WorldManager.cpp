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
#include "Camera/CameraObserver.h"
#include "CCDirector.h"
#include "support/CCPointExtension.h"
#include "Physical/PhysicalObj.h"
#include "Physical/PhysicalControl.h"
#include "Client/Client.h"
#include "platform/CCFileUtils.h"
#include "Tools/Scene.h"
#if COCOS2D_DEBUG
#include "Tools/DebugLayer.h"
#endif // COCOS2D_DEBUG


namespace Game
{
	WorldManager * WorldManager::_ins;
	WorldManager* WorldManager::Instance()
	{
		if (NULL == _ins)
		{
			_ins = new WorldManager;
		}
		return _ins;
	}
	void WorldManager::ClearUp( void )
	{
		if (NULL != _ins)
		{
			delete _ins;
			_ins = NULL;
		}
	}

	WorldManager::WorldManager(void)
		:m_terrain(NULL)
		,m_actorsControl(NULL)
		,m_sceneControl(NULL)
		,m_uiControl(NULL)
        ,m_camera(NULL)
        ,m_physicalControl(NULL)
        ,m_client(new Net::Client)
		,m_root(NULL)
#if COCOS2D_DEBUG
		,m_debugLayer(new Tools::DebugLayer)
#endif // COCOS2D_DEBUG
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
#if COCOS2D_DEBUG
		delete m_debugLayer;
#endif
	}

	cocos2d::CCScene* WorldManager::CreateScene()
	{
		MainScene *scene = MainScene::create();
		//Box2D
		{
			m_physicalControl = new PhysicalControl;
		}
        //摄像机
		cocos2d::CCLayer *scaleLayer = cocos2d::CCLayer::create();
		scene->addChild(scaleLayer);
    	CameraObserver *cameraObj = CameraObserver::Create();
		m_root = cameraObj;
    	scaleLayer->addChild(cameraObj);
        m_camera = new Camera;
        m_camera->init(cameraObj);
        
		//地形
		{
			TerrainLayer *terrainLayer = TerrainLayer::create();
			terrainLayer->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
			m_terrain = new TerrainProp;
			m_terrain->AttachObserver(terrainLayer);
			cameraObj->addChild(terrainLayer);
		}
		cocos2d::CCLayer *entityLayer = cocos2d::CCLayer::create();
		entityLayer->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
		//建筑
		{
			BuildingsLayer *buildingsLayer = new BuildingsLayer(entityLayer);
			m_sceneControl = new SceneControl;
			m_sceneControl->AttachObserver(buildingsLayer);
		}
		//角色
		{
			ActorsLayer *actorsLayer = new ActorsLayer(entityLayer);
			m_actorsControl = new ActorsControl;
			m_actorsControl->AttachObserver(actorsLayer);
		}
		cameraObj->addChild(entityLayer);
		//UI
		{
			GUI::UILayer *uiLayer = GUI::UILayer::create();
			m_uiControl = new GUI::UIControl;
			m_uiControl->AttachObserver(uiLayer);
			scene->addChild(uiLayer);
			m_uiControl->Init();
		}
#if COCOS2D_DEBUG
		cameraObj->addChild(m_debugLayer);
#endif // COCOS2D_DEBUG

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
    void WorldManager::Init(const char *sceneName)
    {
		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(sceneName);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
		Tools::Scene scene;
		scene.Read(buff, size);
		delete[] buff;

		Init(&scene);
    }

	void WorldManager::Init( Tools::Scene *scene )
	{
		this->GetTerrain()->Init(scene);
		this->GetSceneControl()->Init(scene);
	}

	cocos2d::CCNode* WorldManager::GetRoot( void ) const
	{
		return m_root;
	}

}
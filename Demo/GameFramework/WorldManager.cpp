#include "WorldManager.h"
#include "MainScene.h"
#include "Terrain/TerrainLayer.h"
#include "Terrain/TerrainProp.h"
#include "Actors/ActorsLayer.h"
#include "Actors/ActorsControl.h"
#include "Actors/ActorProp.h"
#include "SceneObjects/SceneObjectsLayer.h"
#include "SceneObjects/SceneObjectsControl.h"
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
#include "../Tools/Scene.h"
#if COCOS2D_DEBUG
#include "Tools/DebugLayer.h"
#endif // COCOS2D_DEBUG
#include "SceneInfo.h"
#include "Animation/SkeletonCocos2D.h"
#include "SimpleAudioEngine.h"
#include "Tools/AvatarManager.h"

using namespace CocosDenshion;

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
		:m_sceneInfo(NULL)
		,m_terrain(NULL)
		,m_actorsControl(NULL)
		,m_sceneObjectsControl(NULL)
		,m_uiControl(NULL)
        ,m_camera(NULL)
        ,m_physicalControl(NULL)
        ,m_client(new Net::Client)
		,m_root(NULL)
		,m_sample(NULL)
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
		delete m_sceneObjectsControl;
		delete m_actorsControl;
		delete m_terrain;
		delete m_client;
		delete m_sceneInfo;
		delete m_sample;
#if COCOS2D_DEBUG
		delete m_debugLayer;
#endif
	}

	cocos2d::CCScene* WorldManager::Init()
	{
		MainScene *scene = MainScene::create();
		m_sceneInfo = new SceneInfo;
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
			cameraObj->addChild(terrainLayer, 1.0f);
		}
		cocos2d::CCLayer *entityLayer = cocos2d::CCLayer::create();
		entityLayer->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
		//建筑
		{
			SceneObjectsLayer *sceneObjectsLayer = new SceneObjectsLayer(entityLayer);
			m_sceneObjectsControl = new SceneObjectsControl;
			m_sceneObjectsControl->AttachObserver(sceneObjectsLayer);
		}
		//角色
		{
			ActorsLayer *actorsLayer = new ActorsLayer(entityLayer);
			m_actorsControl = new ActorsControl;
			m_actorsControl->AttachObserver(actorsLayer);
		}
		cameraObj->addChild(entityLayer, 1.0f);
		//UI
		{
			GUI::UILayer *uiLayer = GUI::UILayer::create();
			m_uiControl = new GUI::UIControl;
			m_uiControl->AttachObserver(uiLayer);
			scene->addChild(uiLayer);
			m_uiControl->Init();
		}
		m_camera->Reset();
		//bone
		//{
		//	m_sample = new SkeletonCocos2D;
		//	m_sample->Load("skeletonbone.xml","texture.xml","texture.png","RobotBiped");
		//	scene->addChild(m_sample);
		//	m_sample->m_skeleton->PlayAnimation("run",1.0f,-1,2);
		//	CCSize size = CCDirector::sharedDirector()->getWinSize();
		//	m_sample->setPosition(cocos2d::CCPointMake(size.width/2, 150));
		//}
#if COCOS2D_DEBUG
		cameraObj->addChild(m_debugLayer, 1.0f);
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
	float WorldManager::LogicToPoint( float size )
	{
		return Instance()->GetCamera()->LogicToPoint(size);
	}

	cocos2d::CCPoint WorldManager::LogicToPoint( const cocos2d::CCPoint &pos )
	{
		return Instance()->GetCamera()->LogicToPoint(pos);
	}

	cocos2d::CCSize WorldManager::LogicToPoint( const cocos2d::CCSize &pos )
	{
		return Instance()->GetCamera()->LogicToPoint(pos);
	}

	float WorldManager::PointToLogic( float size )
	{
		return Instance()->GetCamera()->PointToLogic(size);
	}

	cocos2d::CCPoint WorldManager::PointToLogic( const cocos2d::CCPoint &pos )
	{
		return Instance()->GetCamera()->PointToLogic(pos);
	}

	cocos2d::CCSize WorldManager::PointToLogic( const cocos2d::CCSize &pos )
	{
		return Instance()->GetCamera()->PointToLogic(pos);
	}

    void WorldManager::update(float dt)
    {
    	GetActorsControl()->Tick(dt);
    	GetPhysicalControl()->Update(dt);
		Tools::AvatarManager::getSingleton()->Tick();
    }
    void WorldManager::InitSceneByFile(const char *sceneName)
    {
		const char *fullPath = cocos2d::CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(sceneName);
		unsigned long size = 0;
		unsigned char *buff = cocos2d::CCFileUtils::sharedFileUtils()->getFileData(fullPath, "rb", &size);
		Tools::Scene scene;
		scene.Read(buff, size);
		delete[] buff;

		InitScene(&scene);
    }

	void WorldManager::InitScene( const Tools::Scene *scene )
	{
		if (NULL != scene->GetBackgroundMusic())
		{
			SimpleAudioEngine::sharedEngine()->playBackgroundMusic(scene->GetBackgroundMusic(), true);
		}
		GetSceneInfo()->Init(scene);
		GetCamera()->SetTransScale(scene->GetTransScale());
		GetTerrainProp()->Init(scene);
		GetSceneObjectsControl()->Init(scene);
	}

	void WorldManager::SetCollidable( bool isCollide )
	{
		GetSceneInfo()->SetCollidable(isCollide);
	}


}
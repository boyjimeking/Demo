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
        //,m_physicalControl(NULL)
        ,m_client(new Net::Client)
		,m_root(NULL)
	{

	}
	WorldManager::~WorldManager(void)
	{
		//delete m_physicalControl;
		delete m_camera;
		delete m_uiControl;
		delete m_sceneObjectsControl;
		delete m_actorsControl;
		delete m_terrain;
		delete m_client;
		delete m_sceneInfo;
	}

	cocos2d::CCScene* WorldManager::Init()
	{
		MainScene *scene = MainScene::create();
		m_sceneInfo = new SceneInfo;
		////Box2D
		//{
		//	m_physicalControl = new PhysicalControl;
		//}
        //摄像机
		cocos2d::CCLayer *scaleLayer = cocos2d::CCLayer::create();
		scene->addChild(scaleLayer);
    	CameraObserver *cameraObj = CameraObserver::Create();
		m_root = cameraObj;
    	scaleLayer->addChild(cameraObj);
		m_camera = new Camera;
		m_camera->init(cameraObj);
		m_camera->Reset();
		//UI
		{
			GUI::UILayer *uiLayer = GUI::UILayer::create();
			m_uiControl = new GUI::UIControl;
			m_uiControl->AttachObserver(uiLayer);
			scene->addChild(uiLayer);
			m_uiControl->Init();
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
    	//GetPhysicalControl()->Update(dt);
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

		typedef Tools::Scene::LayerInfoList LayerInfoList;
		const LayerInfoList &list = scene->GetLayerList();
		for (LayerInfoList::const_iterator it = list.begin(); list.end() != it; ++it)
		{
			CreateLayer(it->m_layerName.c_str(), it->m_zOrder, it->m_moveScale);
		}

		GetSceneInfo()->Init(scene);
		GetCamera()->SetTransScale(scene->GetTransScale());
		GetTerrainProp()->Init(scene);
		GetSceneObjectsControl()->Init(scene);
		GetCamera()->Reset(cocos2d::CCPointMake(GetSceneInfo()->GetWidth() / 2.0f, GetSceneInfo()->GetHeight() / 2.0f));
	}

	void WorldManager::SetCollidable( bool isCollide )
	{
		GetSceneInfo()->SetCollidable(isCollide);
	}

	cocos2d::CCLayer* WorldManager::CreateLayer(const char *layerName, int zOrder, float moveScale)
	{
		cocos2d::CCLayer *entityLayer = cocos2d::CCLayer::create();
		entityLayer->setZOrder(zOrder);
		entityLayer->setAnchorPoint(cocos2d::CCPointMake(0.0f, 0.0f));
		//地形
		{
			TerrainLayer *terrainLayer = new TerrainLayer();
			m_terrain = new TerrainProp;
			m_terrain->AttachObserver(terrainLayer);
		}
		//建筑
		{
			SceneObjectsLayer *sceneObjectsLayer = new SceneObjectsLayer();
			m_sceneObjectsControl = new SceneObjectsControl;
			m_sceneObjectsControl->AttachObserver(sceneObjectsLayer);
		}
		//角色
		{
			ActorsLayer *actorsLayer = new ActorsLayer();
			m_actorsControl = new ActorsControl;
			m_actorsControl->AttachObserver(actorsLayer);
		}
		m_root->addChild(entityLayer, moveScale);
		m_layerMap.insert(std::make_pair(layerName, entityLayer));
		return entityLayer;
	}

	cocos2d::CCNode* WorldManager::GetRoot( void ) const
	{
		return m_root;
	}

	cocos2d::CCLayer* WorldManager::LookupLayer( const char *layerName )
	{
		LayerMap::iterator it = m_layerMap.find(layerName);
		if (m_layerMap.end() != it)
		{
			return it->second;
		}
		else
		{
			return NULL;
		}
	}


}
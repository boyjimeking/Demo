//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/TestDemo
//	created:	2012-12-17
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#include "gtest.h"
#include "Tools/EditScene.h"
#include "Base/INotifier.h"
#include "WorldManager.h"
#include "SceneObjects/SceneObjectsControl.h"
#include "SceneObjects/SceneObjectProp.h"
#include "Terrain/GridProp.h"
#include "Terrain/TerrainProp.h"
#include "SceneInfo.h"

class TestEditScene
	:public testing::Test
{
public:
	virtual void SetUp()
	{
		INotifier::NotifyMode = false;
		Game::WorldManager::Instance()->Init();
		m_editScene = new Tools::EditScene;
	}
	virtual void TearDown()
	{
		delete m_editScene;
		m_editScene = NULL;
		Game::WorldManager::ClearUp();
		INotifier::NotifyMode = true;
	}

	Tools::EditScene *m_editScene;
};

TEST_F(TestEditScene, Create)
{
	m_editScene->Create(500, 400, 5, 32);
	EXPECT_EQ(500, m_editScene->GetWidth());
	EXPECT_EQ(400, m_editScene->GetHeight());
	EXPECT_EQ(5, m_editScene->GetGridSize());
	EXPECT_EQ(32, m_editScene->GetTransScale());
	EXPECT_EQ(100, m_editScene->GetColumn());
	EXPECT_EQ(80, m_editScene->GetRow());

	EXPECT_EQ(500, Game::WorldManager::Instance()->GetSceneInfo()->GetWidth());
	EXPECT_EQ(400, Game::WorldManager::Instance()->GetSceneInfo()->GetHeight());
	EXPECT_EQ(5, Game::WorldManager::Instance()->GetSceneInfo()->GetGridSize());
	EXPECT_EQ(32, Game::WorldManager::Instance()->GetSceneInfo()->GetTransScale());
	EXPECT_EQ(100, Game::WorldManager::Instance()->GetSceneInfo()->GetColumn());
	EXPECT_EQ(80, Game::WorldManager::Instance()->GetSceneInfo()->GetRow());
}

TEST_F(TestEditScene, ObjectImage)
{
	m_editScene->Create(500, 400, 5, 32);
	m_editScene->SetSceneName("TestScene");
	EXPECT_STREQ("TestScene", m_editScene->GetSceneName());
	EXPECT_STREQ("TestScene", Game::WorldManager::Instance()->GetSceneInfo()->GetSceneName().c_str());
	m_editScene->AddObjectImage("Image1.plist");
	EXPECT_STREQ("Image1.plist", m_editScene->GetImageNameList().back().c_str());
	EXPECT_STREQ("Image1.plist", Game::WorldManager::Instance()->GetSceneObjectsControl()->GetImageList().back().c_str());
	m_editScene->AddObjectImage("Image2.plist");
	EXPECT_STREQ("Image2.plist", m_editScene->GetImageNameList().back().c_str());
	EXPECT_STREQ("Image2.plist", Game::WorldManager::Instance()->GetSceneObjectsControl()->GetImageList().back().c_str());
	m_editScene->RemoveObjectImage("Image2.plist");
	EXPECT_STREQ("Image1.plist", m_editScene->GetImageNameList().back().c_str());
	EXPECT_STREQ("Image1.plist", Game::WorldManager::Instance()->GetSceneObjectsControl()->GetImageList().back().c_str());
}

TEST_F(TestEditScene, Object)
{
	int id1 = m_editScene->AddObject("image1.png", 10.0f, 11.5f, 5.0f, 5.2f);
	Tools::ObjectInfo *objInfo = m_editScene->GetObjectInfoList().back();
	EXPECT_EQ(id1, objInfo->m_id);
	EXPECT_STREQ("image1.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(10.0f, objInfo->m_x);
	EXPECT_FLOAT_EQ(11.5f, objInfo->m_y);
	EXPECT_FLOAT_EQ(5.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(5.2f, objInfo->m_height);

	Game::SceneObjectProp *prop = Game::WorldManager::Instance()->GetSceneObjectsControl()->LookupSceneObject(id1);
	EXPECT_EQ(id1, prop->GetID());
	EXPECT_STREQ("image1.png", prop->GetImageName().c_str());
	EXPECT_FLOAT_EQ(10.0f, prop->GetPosition().x);
	EXPECT_FLOAT_EQ(11.5f, prop->GetPosition().y);
	EXPECT_FLOAT_EQ(5.0f, prop->GetSize().width);
	EXPECT_FLOAT_EQ(5.2f, prop->GetSize().height);

	int id2 = m_editScene->AddObject("image2.png", 65.5f, 45.3f, 16.0f, 15.0f);
	objInfo = m_editScene->GetObjectInfoList().back();
	EXPECT_EQ(id2, objInfo->m_id);
	EXPECT_STREQ("image2.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(65.5f, objInfo->m_x);
	EXPECT_FLOAT_EQ(45.3f, objInfo->m_y);
	EXPECT_FLOAT_EQ(16.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(15.0f, objInfo->m_height);

	prop = Game::WorldManager::Instance()->GetSceneObjectsControl()->LookupSceneObject(id2);
	EXPECT_EQ(id2, prop->GetID());
	EXPECT_STREQ("image2.png", prop->GetImageName().c_str());
	EXPECT_FLOAT_EQ(65.5f, prop->GetPosition().x);
	EXPECT_FLOAT_EQ(45.3f, prop->GetPosition().y);
	EXPECT_FLOAT_EQ(16.0f, prop->GetSize().width);
	EXPECT_FLOAT_EQ(15.0f, prop->GetSize().height);

	m_editScene->ChangeObject(id2, "image3.png", 32.3f, 16.4f, 8.0f, 6.9f);
	objInfo = m_editScene->GetObjectInfoList().back();
	EXPECT_EQ(id2, objInfo->m_id);
	EXPECT_STREQ("image3.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(32.3f, objInfo->m_x);
	EXPECT_FLOAT_EQ(16.4f, objInfo->m_y);
	EXPECT_FLOAT_EQ(8.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(6.9f, objInfo->m_height);

	prop = Game::WorldManager::Instance()->GetSceneObjectsControl()->LookupSceneObject(id2);
	EXPECT_EQ(id2, prop->GetID());
	EXPECT_STREQ("image3.png", prop->GetImageName().c_str());
	EXPECT_FLOAT_EQ(32.3f, prop->GetPosition().x);
	EXPECT_FLOAT_EQ(16.4f, prop->GetPosition().y);
	EXPECT_FLOAT_EQ(8.0f, prop->GetSize().width);
	EXPECT_FLOAT_EQ(6.9f, prop->GetSize().height);

	m_editScene->RemoveObject(id2);
	objInfo = m_editScene->GetObjectInfoList().back();
	EXPECT_EQ(id1, objInfo->m_id);
	EXPECT_STREQ("image1.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(10.0f, objInfo->m_x);
	EXPECT_FLOAT_EQ(11.5f, objInfo->m_y);
	EXPECT_FLOAT_EQ(5.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(5.2f, objInfo->m_height);

	prop = Game::WorldManager::Instance()->GetSceneObjectsControl()->LookupSceneObject(id2);
	EXPECT_EQ(reinterpret_cast<Game::SceneObjectProp*>(NULL), prop);
}

TEST_F(TestEditScene, Terrain)
{
	int id1 = m_editScene->AddTerrain("image1.png", 10.0f, 11.5f, 5.0f, 5.2f);
	Tools::ObjectInfo *objInfo = m_editScene->GetTerrainList().back();
	EXPECT_EQ(id1, objInfo->m_id);
	EXPECT_STREQ("image1.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(10.0f, objInfo->m_x);
	EXPECT_FLOAT_EQ(11.5f, objInfo->m_y);
	EXPECT_FLOAT_EQ(5.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(5.2f, objInfo->m_height);

	Game::GridProp *prop = Game::WorldManager::Instance()->GetTerrainProp()->LookupGrid(id1);
	EXPECT_EQ(id1, prop->GetID());
	EXPECT_STREQ("image1.png", prop->GetImageName().c_str());
	EXPECT_FLOAT_EQ(10.0f, prop->GetPosition().x);
	EXPECT_FLOAT_EQ(11.5f, prop->GetPosition().y);
	EXPECT_FLOAT_EQ(5.0f, prop->GetSize().width);
	EXPECT_FLOAT_EQ(5.2f, prop->GetSize().height);

	int id2 = m_editScene->AddTerrain("image2.png", 65.5f, 45.3f, 16.0f, 15.0f);
	objInfo = m_editScene->GetTerrainList().back();
	EXPECT_EQ(id2, objInfo->m_id);
	EXPECT_STREQ("image2.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(65.5f, objInfo->m_x);
	EXPECT_FLOAT_EQ(45.3f, objInfo->m_y);
	EXPECT_FLOAT_EQ(16.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(15.0f, objInfo->m_height);

	prop = Game::WorldManager::Instance()->GetTerrainProp()->LookupGrid(id2);
	EXPECT_EQ(id2, prop->GetID());
	EXPECT_STREQ("image2.png", prop->GetImageName().c_str());
	EXPECT_FLOAT_EQ(65.5f, prop->GetPosition().x);
	EXPECT_FLOAT_EQ(45.3f, prop->GetPosition().y);
	EXPECT_FLOAT_EQ(16.0f, prop->GetSize().width);
	EXPECT_FLOAT_EQ(15.0f, prop->GetSize().height);

	m_editScene->ChangeTerrain(id2, "image3.png", 32.3f, 16.4f, 8.0f, 6.9f);
	objInfo = m_editScene->GetTerrainList().back();
	EXPECT_EQ(id2, objInfo->m_id);
	EXPECT_STREQ("image3.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(32.3f, objInfo->m_x);
	EXPECT_FLOAT_EQ(16.4f, objInfo->m_y);
	EXPECT_FLOAT_EQ(8.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(6.9f, objInfo->m_height);

	prop = Game::WorldManager::Instance()->GetTerrainProp()->LookupGrid(id2);
	EXPECT_EQ(id2, prop->GetID());
	EXPECT_STREQ("image3.png", prop->GetImageName().c_str());
	EXPECT_FLOAT_EQ(32.3f, prop->GetPosition().x);
	EXPECT_FLOAT_EQ(16.4f, prop->GetPosition().y);
	EXPECT_FLOAT_EQ(8.0f, prop->GetSize().width);
	EXPECT_FLOAT_EQ(6.9f, prop->GetSize().height);

	m_editScene->RemoveTerrain(id2);
	objInfo = m_editScene->GetTerrainList().back();
	EXPECT_EQ(id1, objInfo->m_id);
	EXPECT_STREQ("image1.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(10.0f, objInfo->m_x);
	EXPECT_FLOAT_EQ(11.5f, objInfo->m_y);
	EXPECT_FLOAT_EQ(5.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(5.2f, objInfo->m_height);

	prop = Game::WorldManager::Instance()->GetTerrainProp()->LookupGrid(id2);
	EXPECT_EQ(reinterpret_cast<Game::GridProp*>(NULL), prop);
}

TEST_F(TestEditScene, SaveLoad)
{
	m_editScene->Create(500, 400, 5, 32);
	m_editScene->SetSceneName("TestScene");
	m_editScene->AddObjectImage("Image1.plist");
	int id1 = m_editScene->AddObject("image1.png", 10.0f, 11.5f, 5.0f, 5.2f);
	int id2 = m_editScene->AddTerrain("image2.png", 65.5f, 45.3f, 16.0f, 15.0f);

	unsigned char buff[16384] = {0};
	int length = m_editScene->Save(buff, 16384);
	EXPECT_NE(0, length);

	Tools::Scene scene;
	scene.Read(buff, length);

	EXPECT_EQ(500, scene.GetWidth());
	EXPECT_EQ(400, scene.GetHeight());
	EXPECT_EQ(5, scene.GetGridSize());
	EXPECT_EQ(32, scene.GetTransScale());
	EXPECT_EQ(100, scene.GetColumn());
	EXPECT_EQ(80, scene.GetRow());
	EXPECT_STREQ("TestScene", scene.GetSceneName());
	EXPECT_STREQ("Image1.plist", scene.GetImageNameList().back().c_str());

	Tools::ObjectInfo *objInfo = scene.GetObjectInfoList().back();
	EXPECT_STREQ("image1.png", objInfo->m_imageName);
	EXPECT_FLOAT_EQ(10.0f, objInfo->m_x);
	EXPECT_FLOAT_EQ(11.5f, objInfo->m_y);
	EXPECT_FLOAT_EQ(5.0f, objInfo->m_width);
	EXPECT_FLOAT_EQ(5.2f, objInfo->m_height);


	Tools::TerrainInfo *terrainInfo = scene.GetTerrainList().back();
	EXPECT_STREQ("image2.png", terrainInfo->m_imageName);
	EXPECT_FLOAT_EQ(65.5f, terrainInfo->m_x);
	EXPECT_FLOAT_EQ(45.3f, terrainInfo->m_y);
	EXPECT_FLOAT_EQ(16.0f, terrainInfo->m_width);
	EXPECT_FLOAT_EQ(15.0f, terrainInfo->m_height);
}
//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/WorldManager.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef WorldManager_h__
#define WorldManager_h__

#include "cocoa/CCGeometry.h"

namespace cocos2d
{
	class CCScene;
}

namespace GUI
{
	class UIControl;
}

namespace Net
{
	class Client;
}

namespace Game
{
	class TerrainProp;
	class ActorsControl;
	class SceneControl;
    class Camera;
    class PhysicalControl;
	/*
	 *	世界主控
	 */
	class WorldManager
	{
	public:
		static WorldManager* Instance();

		cocos2d::CCScene* CreateScene();
		TerrainProp* GetTerrain(void) const { return m_terrain; }
		ActorsControl * GetActorsControl(void) const { return m_actorsControl; }
		SceneControl * GetSceneControl(void) const { return m_sceneControl; }
        Camera* GetCamera(void) const { return m_camera; }
        PhysicalControl* GetPhysicalControl(void) const { return m_physicalControl; }

        static cocos2d::CCPoint WorldPosToDesign(const cocos2d::CCPoint &worldPos);
        static cocos2d::CCPoint DesignPosToWorld(const cocos2d::CCPoint &screenPos);

        void update(float dt);
	protected:
		TerrainProp *m_terrain;
		ActorsControl *m_actorsControl;
		SceneControl *m_sceneControl;
		GUI::UIControl *m_uiControl;
        Camera *m_camera;
        PhysicalControl *m_physicalControl;
        Net::Client *m_client;
	private:
		WorldManager(void);
		~WorldManager(void);
	};
}

#endif // WorldManager_h__

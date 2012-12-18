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

namespace Tools
{
#if COCOS2D_DEBUG
	class DebugLayer;
#endif
	class Scene;
}

namespace Game
{
	class TerrainProp;
	class ActorsControl;
	class SceneObjectsControl;
    class Camera;
    class PhysicalControl;
	/*
	 *	世界主控
	 */
	class WorldManager
	{
	public:
		static WorldManager* Instance(void);
		static void ClearUp(void);

		cocos2d::CCScene* CreateScene();
		void Init(const char *sceneName);
		void Init(Tools::Scene *scene);
		TerrainProp* GetTerrain(void) const { return m_terrain; }
		ActorsControl * GetActorsControl(void) const { return m_actorsControl; }
		SceneObjectsControl * GetSceneObjectsControl(void) const { return m_sceneObjectsControl; }
        Camera* GetCamera(void) const { return m_camera; }
        PhysicalControl* GetPhysicalControl(void) const { return m_physicalControl; }
		cocos2d::CCNode* GetRoot(void) const;

        static cocos2d::CCPoint WorldPosToDesign(const cocos2d::CCPoint &worldPos);
        static cocos2d::CCPoint DesignPosToWorld(const cocos2d::CCPoint &screenPos);

        void update(float dt);

		void SetSceneScale(float scale);
	protected:
		TerrainProp *m_terrain;
		ActorsControl *m_actorsControl;
		SceneObjectsControl *m_sceneObjectsControl;
		GUI::UIControl *m_uiControl;
        Camera *m_camera;
        PhysicalControl *m_physicalControl;
        Net::Client *m_client;
		cocos2d::CCNode *m_root;

#if COCOS2D_DEBUG
		Tools::DebugLayer *m_debugLayer;
#endif
	private:
		WorldManager(void);
		~WorldManager(void);
		static WorldManager *_ins;
	};
}

#endif // WorldManager_h__

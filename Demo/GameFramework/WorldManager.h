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
	class SceneInfo;
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

		cocos2d::CCScene* Init();

		void InitSceneByFile(const char *sceneName);
		void InitScene(const Tools::Scene *scene);
		//获取当前场景信息
		SceneInfo* GetSceneInfo(void) const { return m_sceneInfo; }
		//获取角色控制器
		ActorsControl * GetActorsControl(void) const { return m_actorsControl; }
		//获取地表属性
		TerrainProp* GetTerrainProp(void) const { return m_terrain; }
		//获取场景物件控制
		SceneObjectsControl* GetSceneObjectsControl(void) const { return m_sceneObjectsControl; }
		//获取摄像机
        Camera* GetCamera(void) const { return m_camera; }
		//获取UI
		GUI::UIControl* GetUIControl(void) const { return m_uiControl; }
		//获取物理控制
        PhysicalControl* GetPhysicalControl(void) const { return m_physicalControl; }
		//获取逻辑根节点
		cocos2d::CCNode* GetRoot(void) const { return m_root; }

        static cocos2d::CCPoint WorldPosToDesign(const cocos2d::CCPoint &worldPos);
        static cocos2d::CCPoint DesignPosToWorld(const cocos2d::CCPoint &screenPos);
		static float LogicToPoint(float size);
		static float PointToLogic(float size);
		static cocos2d::CCPoint LogicToPoint(const cocos2d::CCPoint &pos);
		static cocos2d::CCPoint PointToLogic(const cocos2d::CCPoint &pos);
		static cocos2d::CCSize LogicToPoint(const cocos2d::CCSize &pos);
		static cocos2d::CCSize PointToLogic(const cocos2d::CCSize &pos);

        void update(float dt);

		//设置碰撞是否生效
		void SetCollidable(bool isCollide);

		Net::Client* GetClient() const { return m_client; }
	protected:
		SceneInfo *m_sceneInfo;
		ActorsControl *m_actorsControl;
		TerrainProp *m_terrain;
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

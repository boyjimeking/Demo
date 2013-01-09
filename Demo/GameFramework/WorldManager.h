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

class SkeletonCocos2D;

using namespace cocos2d;
using namespace Tools;
using namespace GUI;

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

		CCScene* Init();

		void InitSceneByFile(const char *sceneName);
		void InitScene(const Scene *scene);
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
		//UIControl* GetUIControl(void) const { 
		//	return m_uiControl;
		//}
		//获取物理控制
        PhysicalControl* GetPhysicalControl(void) const { return m_physicalControl; }
		//获取逻辑根节点
		CCNode* GetRoot(void) const { return m_root; }

        static CCPoint WorldPosToDesign(const CCPoint &worldPos);
        static CCPoint DesignPosToWorld(const CCPoint &screenPos);
		static float LogicToPoint(float size);
		static float PointToLogic(float size);
		static CCPoint LogicToPoint(const CCPoint &pos);
		static CCPoint PointToLogic(const CCPoint &pos);
		static CCSize LogicToPoint(const CCSize &pos);
		static CCSize PointToLogic(const CCSize &pos);

        void update(float dt);

		//设置碰撞是否生效
		void SetCollidable(bool isCollide);

		Net::Client* GetClient() const { return m_client; }
	protected:
		SceneInfo *m_sceneInfo;
		ActorsControl *m_actorsControl;
		TerrainProp *m_terrain;
		SceneObjectsControl *m_sceneObjectsControl;
		//GUI::UIControl *m_uiControl;
        Camera *m_camera;
        PhysicalControl *m_physicalControl;
        Net::Client *m_client;
		CCNode *m_root;

#if COCOS2D_DEBUG
		DebugLayer *m_debugLayer;
#endif
		SkeletonCocos2D *m_sample;
	private:
		WorldManager(void);
		~WorldManager(void);
		static WorldManager *_ins;
	};
}

#endif // WorldManager_h__

//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:\GitCode\SimpleGame\SourceCode\GameFramework\WorldManager.h
//	创建日期:	2012年11月22日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef WorldManager_h__
#define WorldManager_h__

namespace cocos2d
{
	class CCScene;
}

namespace GUI
{
	class UIControl;
}

namespace Game
{
	class TerrainProp;
	class ActorsControl;
	class BuildingsControl;
    class Camera;
	/*
	 *	世界主控
	 */
	class WorldManager
	{
	public:
		static WorldManager* Instance();

		cocos2d::CCScene* CreateScene();
		TerrainProp* GetTerrain(void) const { return m_terrain; }
		ActorsControl * GetActorsControl(void) const { return m_ActorsControl; }
		BuildingsControl * GetBuildingsControl(void) const { return m_buildingsControl; }
        Camera* GetCamera(void) const { return m_camera; }
	protected:
		TerrainProp *m_terrain;
		ActorsControl *m_ActorsControl;
		BuildingsControl *m_buildingsControl;
		GUI::UIControl *m_uiControl;
        Camera *m_camera;
	private:
		WorldManager(void);
		~WorldManager(void);
	};
}

#endif // WorldManager_h__

//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/SceneObjectManager/SceneObjectProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectProp_h__
#define SceneObjectProp_h__

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"
#include <string>

namespace Tools
{
	struct ObjectInfo;
}

namespace Game
{
	class SceneObjectEntity;
	/*
	 *	建筑属性，用于记录建筑的各项信息及控制建筑的改变
	 */
	class SceneObjectProp
		:public INotifier
	{
	public:
		static SceneObjectProp* Create(const Tools::ObjectInfo *sceneInfo);
		SceneObjectProp(void);
		virtual ~SceneObjectProp(void);
		
		void Init(const Tools::ObjectInfo *sceneInfo);
		SceneObjectEntity* CreateEntity(void);
	protected:
	private:
		cocos2d::CCPoint m_position;
		std::string m_imageName;
	};
}

#endif // SceneObjectProp_h__

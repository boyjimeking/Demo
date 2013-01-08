//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/SceneObjectManager/SceneObjectsControl.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectsControl_h__
#define SceneObjectsControl_h__

#include "../Base/INotifier.h"
#include <string>
#include <vector>
#include "cocoa/CCGeometry.h"
#include <list>

namespace Tools
{
	class Scene;
}
using namespace Tools;
namespace Game
{
	class SceneObjectProp;
	/*
	 *	建筑控制类，用于控制全部建筑的逻辑处理及控制场景建筑层的改变
	 */
	class SceneObjectsControl
		:public INotifier
	{
	public:
		_Decl_Notifier(SceneObjectsControl);
		SceneObjectsControl(void);
		virtual ~SceneObjectsControl(void);

		void Init(const Scene *sceneFile);

		void AddObjectImage(const char *imageName);
		void RemoveObjectImage(const char *imageName);
		typedef std::list<std::string> ImageList;
		const ImageList& GetImageList(void) const { return m_imageList; }

		void AddSceneObject(int id, const char *imageName, float x, float y, float width, float height);
		void ChangeSceneObject(int id, const char *imageName, float x, float y, float width, float height);
		void RemoveSceneObject(int id);
		SceneObjectProp* LookupSceneObject(int id);

		void Clear(void);
	protected:
	private:
		typedef std::vector<SceneObjectProp*> SceneObjectList;
		std::vector<SceneObjectProp*> m_sceneObjects;
		ImageList m_imageList;
	};
}

#endif // SceneObjectsControl_h__

#include "SceneObjectsControl.h"
#include "platform/CCFileUtils.h"
#include "../Tools/Scene.h"
#include "platform/CCCommon.h"
#include "SceneObjectProp.h"
#include "SceneObjectEntity.h"
#include "SceneObjectControlEvent.h"

namespace Game
{
	SceneObjectsControl::SceneObjectsControl(void)
	{

	}
	SceneObjectsControl::~SceneObjectsControl(void)
	{
		Clear();
	}

	void SceneObjectsControl::Init(const Scene *sceneFile)
	{
		Clear();
		typedef Scene::ImageNameList ImageList;
		const ImageList &imageList = sceneFile->GetImageNameList();
		for (ImageList::const_iterator it = imageList.begin(); imageList.end() != it; ++it)
		{
			AddObjectImage(it->c_str());
		}
		typedef Scene::ObjectInfoList InfoList;
        const InfoList &list = sceneFile->GetObjectInfoList();
		for (InfoList::const_iterator it = list.begin(); list.end() != it; ++it)
		{
			ObjectInfo *info = *it;
			AddSceneObject(info->m_id, info->m_imageName, info->m_x, info->m_y, info->m_width, info->m_height);
		}
	}

	void SceneObjectsControl::AddSceneObject( int id, const char *imageName, float x, float y, float width, float height )
	{
		SceneObjectProp *prop = new SceneObjectProp;
		SceneObjectEntity *entity = SceneObjectEntity::Create();

		SceneObjectControlEventAddObject event(entity);
		NotifyChange(&event);

		prop->AttachObserver(entity);
		prop->Init(id, imageName, x, y, width, height);
		m_sceneObjects.push_back(prop);
	}
	void SceneObjectsControl::ChangeSceneObject( int id, const char *imageName, float x, float y, float width, float height )
	{
		SceneObjectProp *prop = LookupSceneObject(id);
		prop->Init(id, imageName, x, y, width, height);
	}
	void SceneObjectsControl::RemoveSceneObject( int id )
	{
		for (SceneObjectList::iterator it = m_sceneObjects.begin(); m_sceneObjects.end() != it; ++it)
		{
			if ((*it)->GetID() == id)
			{
				SceneObjectProp *prop = *it;
				m_sceneObjects.erase(it);
				prop->Remove();
				delete prop;
				break;
			}
		}
	}

	SceneObjectProp* SceneObjectsControl::LookupSceneObject( int id )
	{
		for (SceneObjectList::iterator it = m_sceneObjects.begin(); m_sceneObjects.end() != it; ++it)
		{
			if ((*it)->GetID() == id)
			{
				return *it;
			}
		}
		return NULL;
	}

	void SceneObjectsControl::AddObjectImage( const char *imageName )
	{
		for (ImageList::iterator it = m_imageList.begin(); m_imageList.end() != it; ++it)
		{
			if (0 == it->compare(imageName))
			{
				return;
			}
		}
		m_imageList.push_back(imageName);
		SceneObjectEventAddObjectImage event(m_imageList.back());
		NotifyChange(&event);
	}

	void SceneObjectsControl::RemoveObjectImage( const char *imageName )
	{
		std::string strName;
		for (ImageList::iterator it = m_imageList.begin(); m_imageList.end() != it; ++it)
		{
			if (0 == it->compare(imageName))
			{
				strName = *it;
				m_imageList.erase(it);
				break;
			}
		}
		SceneObjectEventRemoveObjectImage event(strName);
		NotifyChange(&event);
	}

	void SceneObjectsControl::Clear( void )
	{
		for (SceneObjectList::iterator it = m_sceneObjects.begin(); m_sceneObjects.end() != it; ++it)
		{
			SceneObjectProp *prop = *it;
			prop->Remove();
			delete prop;
		}
		m_sceneObjects.clear();

		for (ImageList::iterator it = m_imageList.begin(); m_imageList.end() != it; ++it)
		{
			SceneObjectEventRemoveObjectImage event(*it);
			NotifyChange(&event);
		}
		m_imageList.clear();
	}

}
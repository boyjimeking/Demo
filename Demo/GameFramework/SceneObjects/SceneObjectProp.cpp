#include "SceneObjectProp.h"
#include "SceneObjectEntity.h"
#include "../Tools/Scene.h"
#include "SceneObjectEvents.h"

namespace Game
{
	SceneObjectProp::SceneObjectProp(void)
	{

	}
	SceneObjectProp::~SceneObjectProp(void)
	{

	}

	void SceneObjectProp::Init( int id, const char *imageName, float x, float y, float width, float height )
	{
		m_id = id;
		m_imageName = imageName;
		m_position = CCPointMake(x, y);
		m_size = CCSizeMake(width, height);
		SceneObjectEventInit event(m_imageName, m_position, m_size);
		NotifyChange(&event);
	}

	void SceneObjectProp::Remove( void )
	{
		SceneObjectEventRemove event;
		NotifyChange(&event);
	}

}
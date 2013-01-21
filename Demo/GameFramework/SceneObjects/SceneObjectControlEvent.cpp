#include "SceneObjectControlEvent.h"

namespace Game
{

	SceneObjectControlEventAddObject::SceneObjectControlEventAddObject(SceneObjectEntity *entity, const char *layerName)
		:m_entity(entity)
		,m_layerName(layerName)
	{

	}


	SceneObjectEventAddObjectImage::SceneObjectEventAddObjectImage( const std::string &imageName )
		:m_imageName(imageName)
	{

	}


	SceneObjectEventRemoveObjectImage::SceneObjectEventRemoveObjectImage( const std::string &imageName )
		:m_imageName(imageName)
	{

	}

}
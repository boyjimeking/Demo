#include "SceneObjectControlEvent.h"

namespace Game
{

	SceneObjectControlEventAddObject::SceneObjectControlEventAddObject( SceneObjectEntity *entity )
		:m_entity(entity)
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
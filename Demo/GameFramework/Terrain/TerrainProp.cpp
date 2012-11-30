#include "TerrainProp.h"
#include "TerrainEvent.h"

namespace Game
{
	TerrainProp::TerrainProp(void)
	{

	}
	TerrainProp::~TerrainProp(void)
	{

	}

	void TerrainProp::Load(const char *mapName, const char *imageName)
	{
		NotifyChange(NULL);
	}

}
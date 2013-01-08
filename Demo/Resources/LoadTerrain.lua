function LoadTerrain()
	local TranScale = 100.0
	local terrainManager = WorldManager:Instance():GetTerrainProp()
	local imageName = "terrain_1.png"
	local x = 0 / TranScale
	local y = 1280 / TranScale
	local index = 1;
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_5.png"
	x = 0 / TranScale
	y = 640 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_9.png"
	x = 0 / TranScale
	y = 0 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_2.png"
	x = 960 / TranScale
	y = 1280 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_6.png"
	x = 960 / TranScale
	y = 640 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_10.png"
	x = 960 / TranScale
	y = 0 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_3.png"
	x = 1920 / TranScale
	y = 1280 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_7.png"
	x = 1920 / TranScale
	y = 640 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_11.png"
	x = 1920 / TranScale
	y = 0 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_4.png"
	x = 2880 / TranScale
	y = 1280 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_8.png"
	x = 2880 / TranScale
	y = 640 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
	index = index + 1
	imageName = "terrain_12.png"
	x = 2880 / TranScale
	y = 0 / TranScale
	terrainManager:AddTerrainGrid(index, imageName, x, y, 960 / TranScale, 640 / TranScale)
end
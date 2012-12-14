//
//  Scene.h
//  Buildings
//
//  Created by Mingzhen.Zhang on 12-12-7.
//  Copyright (c) 2012年 Mingzhen.Zhang. All rights reserved.
//

#ifndef __Buildings__Scene__
#define __Buildings__Scene__

#include <list>

namespace Tools
{
	class StreamHelper;
	struct SceneInfo
	{
		int m_id;
		float m_x;
		float m_y;
		char m_imageName[128];

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);

		SceneInfo(void);
	};
    
    typedef SceneInfo TerrainInfo;

	class Scene
	{
	public:
		typedef std::list<SceneInfo*> InfoList;
		typedef std::list<TerrainInfo*> TerrainInfoList;

		Scene(void);
		~Scene(void);

		void Read(unsigned char *buff, unsigned int size);
		unsigned int Write(unsigned char *buff);

		const char* GetSceneName(void) const { return m_sceneName; }
		const char* GetImageName(void) const { return m_imageName; }

		int GetWidth(void) const { return m_width; }
		int GetHeight(void) const { return m_height; }
		int GetColumn(void) const { return m_gridColumn; }
		int GetRow(void) const { return m_gridRow; }
		int GetGridSize(void) const { return m_gridSize; }

		bool GetGrid(int x, int y);

		const char* GetGrid(void) const { return m_grid; }
		int GetGridArrayLength(void) const { return m_gridArrayLength; }
		const InfoList& GetInfoList(void) const { return m_info; }
		const TerrainInfoList& GetTerrainList(void) const { return m_terrain; }
	protected:
		char m_sceneName[128];
        char m_imageName[128];
		int m_width;
		int m_height;
		int m_gridSize;
		int m_gridColumn;
		int m_gridRow;
		char *m_grid;
		int m_gridArrayLength;
		InfoList m_info;
        TerrainInfoList m_terrain;

		int m_readVersion;
		int m_currentVersion;
		enum
		{
			enBaseVersion,
			enCurrentVersion = enBaseVersion,
		};

	};

}
#endif /* defined(__Buildings__Scene__) */

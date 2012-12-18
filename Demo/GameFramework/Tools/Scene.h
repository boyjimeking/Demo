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
	struct ObjectInfo
	{
		int m_id;
		float m_x;
		float m_y;
		float m_width;
		float m_height;
		char m_imageName[128];

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);

		ObjectInfo(void);
	};
    
    typedef ObjectInfo TerrainInfo;

	class Scene
	{
	public:
		typedef std::list<ObjectInfo*> ObjectInfoList;
		typedef std::list<TerrainInfo*> TerrainInfoList;
		typedef std::list<std::string> ImageNameList;

		Scene(void);
		~Scene(void);

		void Read(unsigned char *buff, unsigned int size);
		unsigned int Write(unsigned char *buff, unsigned int size);

		const char* GetSceneName(void) const { return m_sceneName; }
		const ImageNameList& GetImageNameList(void) const { return m_imageName; }


		float GetWidth(void) const { return m_width; }
		float GetHeight(void) const { return m_height; }
		int GetColumn(void) const { return m_gridColumn; }
		int GetRow(void) const { return m_gridRow; }
		float GetGridSize(void) const { return m_gridSize; }
		//逻辑坐标与像素坐标的转换，point per meter
		int GetTransScale(void) const { return m_transScale; }

		bool GetGridPass(int x, int y);

		const char* GetGrids(void) const { return m_grid; }
		int GetGridArrayLength(void) const { return m_gridArrayLength; }
		const ObjectInfoList& GetObjectInfoList(void) const { return m_objectInfoList; }
		const TerrainInfoList& GetTerrainList(void) const { return m_terrainInfoList; }
	protected:
		char m_sceneName[128];
		ImageNameList m_imageName;
		float m_width;
		float m_height;
		float m_gridSize;
		int m_gridColumn;
		int m_gridRow;
		int m_transScale;
		char *m_grid;
		int m_gridArrayLength;
		ObjectInfoList m_objectInfoList;
        TerrainInfoList m_terrainInfoList;

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

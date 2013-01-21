//
//  Scene.h
//  SceneObjects
//
//  Created by Mingzhen.Zhang on 12-12-7.
//  Copyright (c) 2012年 Mingzhen.Zhang. All rights reserved.
//

#ifndef __SceneObjects__Scene__
#define __SceneObjects__Scene__

#include <string>
#include <vector>
#include "FrameInfo.h"

namespace Tools
{
	class StreamHelper;
	struct ObjectInfo
		:public FrameInfo
	{
		int m_id;
		float m_x;
		float m_y;
		std::string m_layerName;

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);

		ObjectInfo(void);
	};

	struct LayerInfo 
	{
		std::string m_layerName;
		int m_zOrder;
		float m_moveScale;

		void Read(StreamHelper *stream);
		void Write(StreamHelper *stream);
		LayerInfo(void);
	protected:
		enum ENVersion
		{
			enBase,
			enCurrentVersion = enBase,
		};
		unsigned int m_version;
	};
    
    typedef ObjectInfo TerrainInfo;

	class Scene
	{
	public:
		typedef std::vector<ObjectInfo*> ObjectInfoList;
		typedef std::vector<TerrainInfo*> TerrainInfoList;
		typedef std::vector<std::string> ImageNameList;
		typedef std::vector<LayerInfo> LayerInfoList;

		Scene(void);
		virtual ~Scene(void);

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
		float GetTransScale(void) const { return m_transScale; }

		float GetCameraMinX(void) const { return m_cameraMinX; }
		float GetCameraMinY(void) const { return m_cameraMinY; }
		float GetCameraMaxX(void) const { return m_cameraMaxX; }
		float GetCameraMaxY(void) const { return m_cameraMaxY; }

		bool GetGridPass(int x, int y);

		const char* GetGrids(void) const { return m_grid; }
		int GetGridArrayLength(void) const { return m_gridArrayLength; }
		const ObjectInfoList& GetObjectInfoList(void) const { return m_objectInfoList; }
		const TerrainInfoList& GetTerrainList(void) const { return m_terrainInfoList; }
		const LayerInfoList& GetLayerList(void) const { return m_layerList; }

		ObjectInfo* LookupObject(int id) const;
		TerrainInfo* LookupTerrain(int id) const;

		const char* GetBackgroundMusic(void) const { return m_backgroundMusic.c_str(); }
	protected:
		char m_sceneName[128];
		ImageNameList m_imageName;
		float m_width;
		float m_height;
		float m_gridSize;
		int m_gridColumn;
		int m_gridRow;

		float m_cameraMinX;
		float m_cameraMinY;
		float m_cameraMaxX;
		float m_cameraMaxY;

		float m_transScale;
		char *m_grid;
		int m_gridArrayLength;
		ObjectInfoList m_objectInfoList;
        TerrainInfoList m_terrainInfoList;
		LayerInfoList m_layerList;
		std::string m_backgroundMusic;

		int m_currentVersion;
		enum
		{
			enBaseVersion,
			enBackgroundMusic,
			enCameraArea,	//添加摄像机限制范围数据
			enLayerInfo,
			enCurrentVersion = enLayerInfo,
		};

	};

}
#endif /* defined(__SceneObjects__Scene__) */

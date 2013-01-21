//
//  Scene.cpp
//  SceneObjects
//
//  Created by Mingzhen.Zhang on 12-12-7.
//  Copyright (c) 2012年 Mingzhen.Zhang. All rights reserved.
//

#include "Scene.h"
#include "StreamHelper.h"

namespace Tools
{
	void ObjectInfo::Read(StreamHelper *stream)
	{
		unsigned int version = FrameInfo::Read(stream);
		stream->Read(m_id);
		stream->Read(m_x);
		stream->Read(m_y);
		if (version >= enLayerName)
		{
			stream->Read(m_layerName);
		}
		else
		{
			m_layerName = "default";
		}
	}

	void ObjectInfo::Write(StreamHelper *stream)
	{
		FrameInfo::Write(stream);
		stream->Write(m_id);
		stream->Write(m_x);
		stream->Write(m_y);
		stream->Write(m_layerName);
	}

	ObjectInfo::ObjectInfo( void )
		:m_x(0)
		,m_y(0)
		,m_id(0)
	{
		
	}

	Scene::Scene(void)
	:m_width(0)
	,m_height(0)
	,m_gridSize(0)
	,m_gridColumn(0)
	,m_gridRow(0)
	,m_grid(NULL)
	,m_gridArrayLength(0)
	,m_currentVersion(enCurrentVersion)
	,m_transScale(0.0f)
	,m_cameraMinX(0.0f)
	,m_cameraMinY(0.0f)
	,m_cameraMaxX(0.0f)
	,m_cameraMaxY(0.0f)
	{
		memset(m_sceneName, 0, sizeof(m_sceneName));
	}
	Scene::~Scene(void)
	{
		if (NULL != m_grid)
		{
			delete[] m_grid;
			m_grid = NULL;
			m_gridArrayLength = 0;
		}
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			delete *it;
		}
		m_objectInfoList.clear();
		for (TerrainInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			delete *it;
		}
		m_terrainInfoList.clear();
	}

	bool Scene::GetGridPass(int x, int y)
	{
		int pos = y * m_gridColumn + x;
		int index = pos / 8;
		int charPos = pos % 8;
		return 0 != (m_grid[index] & (1 << charPos));
	}

	unsigned int Scene::Write(unsigned char *buff, unsigned int size)
	{
		if (NULL == buff)
		{
			return 0;
		}
		StreamHelper stream(buff, size);
		//写入版本号
		stream.Write(&m_currentVersion);
		//写入场景名
		int sceneNameLength = strlen(m_sceneName) + 1;
		stream.Write(&sceneNameLength);
		stream.Write(m_sceneName, sceneNameLength);
        //图片名称
		unsigned int imageNameSize = m_imageName.size();
		stream.Write(imageNameSize);
		for (ImageNameList::iterator it = m_imageName.begin(); m_imageName.end() != it; ++it)
		{
            std::string &str = *it;
			unsigned int length = str.size();
			stream.Write(&length);
			stream.Write(it->c_str(), length);
		}
		//写入场景基本信息
		stream.Write(&m_width);
		stream.Write(&m_height);
		stream.Write(&m_gridSize);
		stream.Write(&m_gridColumn);
		stream.Write(&m_gridRow);
		stream.Write(&m_transScale);
		stream.Write(m_cameraMinX);
		stream.Write(m_cameraMinY);
		stream.Write(m_cameraMaxX);
		stream.Write(m_cameraMaxY);
		//写入碰撞信息
		stream.Write(&m_gridArrayLength);
		stream.Write(m_grid, m_gridArrayLength);
		int listLength = m_objectInfoList.size();
		stream.Write(&listLength);
		for (ObjectInfoList::iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			stream.WriteClass(*it);
		}
        int terrainLength = m_terrainInfoList.size();
		stream.Write(&terrainLength);
		for (TerrainInfoList::iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			stream.WriteClass(*it);
		}
		stream.Write(m_backgroundMusic);
		{
			unsigned int size = m_layerList.size();
			stream.Write(size);
			for (int index = 0; index < m_layerList.size() ; ++index)
			{
				stream.WriteClass(&m_layerList[index]);
			}
		}
		return stream.Size();
	}

	void Scene::Read( unsigned char *buff, unsigned int size )
	{
		if (NULL == buff)
		{
			return;
		}
		StreamHelper stream(buff, size);

		int version = 0;
		stream.Read(&version);
		if (version >= enBaseVersion)
		{
			//读取场景名
			int sceneNameLength = 0;
			stream.Read(&sceneNameLength);
			stream.Read(m_sceneName, sceneNameLength);
            //图片名称
			unsigned int imageNameSize = 0;
			stream.Read(&imageNameSize);
			m_imageName.resize(imageNameSize);
			for (unsigned int index = 0; index < imageNameSize; ++index)
			{
				unsigned int length = 0;
				stream.Read(&length);
				m_imageName[index].resize(length);
				stream.Read(&m_imageName[index][0], length);
			}
			//读取场景基本信息
			stream.Read(&m_width);
			stream.Read(&m_height);
			stream.Read(&m_gridSize);
			stream.Read(&m_gridColumn);
			stream.Read(&m_gridRow);
			stream.Read(&m_transScale);
			if (version >= enCameraArea)
			{
				stream.Read(m_cameraMinX);
				stream.Read(m_cameraMinY);
				stream.Read(m_cameraMaxX);
				stream.Read(m_cameraMaxY);
			}
			else
			{
				m_cameraMinX = 0.0f;
				m_cameraMinY = 0.0f;
				m_cameraMaxX = m_width;
				m_cameraMaxY = m_height;
			}
			//读取碰撞信息
			stream.Read(&m_gridArrayLength);
			if (NULL != m_grid)
			{
				delete[] m_grid;
			}
            m_grid = new char[m_gridArrayLength];
			stream.Read(m_grid, m_gridArrayLength);
			int listLength = 0;
			stream.Read(&listLength);
			for (int index = 0; index < listLength; ++index)
			{
				ObjectInfo *info = new ObjectInfo;
				stream.ReadClass(info);
				m_objectInfoList.push_back(info);
			}
            int terrainLength = 0;
			stream.Read(&terrainLength);
			for (int index = 0; index < terrainLength; ++index)
			{
				TerrainInfo *info = new TerrainInfo;
				stream.ReadClass(info);
				m_terrainInfoList.push_back(info);
			}
			if (version >= enBackgroundMusic)
			{
				stream.Read(m_backgroundMusic);
			}
			if (version >= enLayerInfo)
			{
				unsigned int size = 0;
				stream.Read(size);
				m_layerList.resize(size);
				for (int index = 0; index < m_layerList.size() ; ++index)
				{
					stream.ReadClass(&m_layerList[index]);
				}
			}
			else
			{
				m_layerList.resize(1);
				m_layerList.back().m_layerName = "default";
			}
		}
	}

	ObjectInfo* Scene::LookupObject( int id ) const
	{
		for (ObjectInfoList::const_iterator it = m_objectInfoList.begin(); m_objectInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				return *it;
			}
		}
		return NULL;
	}

	TerrainInfo* Scene::LookupTerrain( int id ) const
	{
		for (TerrainInfoList::const_iterator it = m_terrainInfoList.begin(); m_terrainInfoList.end() != it; ++it)
		{
			if ((*it)->m_id == id)
			{
				return *it;
			}
		}
		return NULL;
	}


	LayerInfo::LayerInfo( void )
		:m_version(enCurrentVersion)
		,m_zOrder(0)
		,m_moveScale(1.0f)
	{

	}

	void LayerInfo::Read( StreamHelper *stream )
	{
		unsigned int version = 0;
		stream->Read(version);
		stream->Read(m_layerName);
		stream->Read(m_zOrder);
		stream->Read(m_moveScale);
	}

	void LayerInfo::Write( StreamHelper *stream )
	{
		stream->Write(m_version);
		stream->Write(m_layerName);
		stream->Write(m_zOrder);
		stream->Write(m_moveScale);
	}

}
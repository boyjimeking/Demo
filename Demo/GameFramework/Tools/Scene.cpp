//
//  Scene.cpp
//  Buildings
//
//  Created by Mingzhen.Zhang on 12-12-7.
//  Copyright (c) 2012年 Mingzhen.Zhang. All rights reserved.
//

#include "Scene.h"
#include "StreamHelper.h"

namespace Tools
{
	void SceneInfo::Read(StreamHelper *stream)
	{
		stream->Read(this->m_x);
		stream->Read(this->m_y);
        int length = 0;
        stream->Read(length);
		stream->Read(this->m_imageName, length);
	}

	void SceneInfo::Write(StreamHelper *stream)
	{
		stream->Write(this->m_x);
		stream->Write(this->m_y);
        int length = strlen(this->m_imageName) + 1;
        stream->Write(length);
		stream->Write(this->m_imageName, length);
	}

	Scene::Scene(void)
	:m_width(0)
	,m_height(0)
	,m_gridSize(0)
	,m_gridColumn(0)
	,m_gridRow(0)
	,m_grid(NULL)
	,m_gridArrayLength(0)
	,m_readVersion(0)
	,m_currentVersion(enCurrentVersion)
	{
		memset(m_sceneName, 0, sizeof(m_sceneName));
		memset(m_imageName, 0, sizeof(m_imageName));
	}
	Scene::~Scene(void)
	{
		if (NULL != m_grid)
		{
			delete[] m_grid;
		}
	}

	bool Scene::GetGrid(int x, int y)
	{
		int pos = y * m_gridColumn + x;
		int index = pos / sizeof(char);
		int charPos = pos % sizeof(char);
		return 0 != (m_grid[index] & (1 << charPos));
	}

	unsigned int Scene::Write( unsigned char *buff )
	{
		if (NULL == buff)
		{
			return 0;
		}
		StreamHelper stream(buff, 16384);
		//写入版本号
		stream.Write(&m_currentVersion);
		//写入场景名
		int sceneNameLength = strlen(m_sceneName) + 1;
		stream.Write(&sceneNameLength);
		stream.Write(m_sceneName, sceneNameLength);
        //图片名称
		int imageNameLength = strlen(m_imageName) + 1;
		stream.Write(&imageNameLength);
		stream.Write(m_imageName, imageNameLength);
		//写入场景基本信息
		stream.Write(&m_width);
		stream.Write(&m_height);
		stream.Write(&m_gridSize);
		stream.Write(&m_gridColumn);
		stream.Write(&m_gridRow);
		//写入碰撞信息
		stream.Write(&m_gridArrayLength);
		stream.Write(m_grid, m_gridArrayLength);
		int listLength = m_info.size();
		stream.Write(&listLength);
		for (InfoList::iterator it = m_info.begin(); m_info.end() != it; ++it)
		{
			stream.WriteClass(&(*it));
		}
        int terrainLength = m_terrain.size();
		stream.Write(&terrainLength);
		for (TerrainInfoList::iterator it = m_terrain.begin(); m_terrain.end() != it; ++it)
		{
			stream.WriteClass(&(*it));
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

		m_readVersion = 0;
		stream.Read(&m_readVersion);
		if (m_readVersion >= enBaseVersion)
		{
			//读取场景名
			int sceneNameLength = 0;
			stream.Read(&sceneNameLength);
			stream.Read(m_sceneName, sceneNameLength);
            //图片名称
			int imageNameLength = 0;
			stream.Read(&imageNameLength);
			stream.Read(m_imageName, imageNameLength);
			//读取场景基本信息
			stream.Read(&m_width);
			stream.Read(&m_height);
			stream.Read(&m_gridSize);
			stream.Read(&m_gridColumn);
			stream.Read(&m_gridRow);
			//读取碰撞信息
			stream.Read(&m_gridArrayLength);
            m_grid = new char[m_gridArrayLength];
			stream.Read(m_grid, m_gridArrayLength);
			int listLength = 0;
			stream.Read(&listLength);
			for (int index = 0; index < listLength; ++index)
			{
				SceneInfo info;
				stream.ReadClass(&info);
				m_info.push_back(info);
			}
            int terrainLength = 0;
			stream.Read(&terrainLength);
			for (int index = 0; index < terrainLength; ++index)
			{
				TerrainInfo info;
				stream.ReadClass(&info);
				m_terrain.push_back(info);
			}
		}
	}

}
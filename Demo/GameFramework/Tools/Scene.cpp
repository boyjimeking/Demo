//
//  Scene.cpp
//  Buildings
//
//  Created by Mingzhen.Zhang on 12-12-7.
//  Copyright (c) 2012年 Mingzhen.Zhang. All rights reserved.
//

#include "Scene.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

namespace Tools
{
	void SceneInfo::Read(FILE *file, SceneInfo *info)
	{
		FileHelper helper(file);
		helper.Read(&info->m_x);
		helper.Read(&info->m_y);
		int strLength = 0;
		helper.Read(&strLength);
		helper.Read(info->m_imageName, strLength);
	}
	void SceneInfo::Write(FILE *file, SceneInfo *info)
	{
		FileHelper helper(file);
		helper.Write(&info->m_x);
		helper.Write(&info->m_y);
		int strLength = strlen(info->m_imageName);
		helper.Write(&strLength);
		helper.Write(info->m_imageName, strLength);
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
	}
	Scene::~Scene(void)
	{
		if (NULL != m_grid)
		{
			delete[] m_grid;
		}
	}
	void Scene::Save(const char *fileName)
	{
		if (NULL == fileName)
		{
			return;
		}
		FileHelper file(fileName, "wb+");
	    //写入版本号
		file.Write(&m_currentVersion);
	    //写入场景名
	    int sceneNameLength = strlen(m_sceneName);
	    file.Write(&sceneNameLength);
	    file.Write(m_sceneName, sceneNameLength);
	    //写入场景基本信息
	    file.Write(&m_width);
	    file.Write(&m_height);
	    file.Write(&m_gridSize);
	    file.Write(&m_gridColumn);
	    file.Write(&m_gridRow);
	    //写入碰撞信息
	    file.Write(&m_gridArrayLength);
	    file.Write(m_grid, m_gridArrayLength);
	    int listLength = m_info.size();
	    file.Write(&listLength);
	    for (InfoList::iterator it = m_info.begin(); m_info.end() != it; ++it)
	    {
	    	file.WriteClass(&(*it));
	    }
	}
	void Scene::Load(const char *fileName)
	{
		if (NULL == fileName)
		{
			return;
		}
		FileHelper file(fileName, "rb");

	    m_readVersion = 0;
	    file.Read(&m_readVersion);
	    if (m_readVersion >= enBaseVersion)
	    {
	    	//读取场景名
		    int sceneNameLength = 0;
		    file.Read(&sceneNameLength);
		    file.Read(m_sceneName, sceneNameLength);
		    //读取场景基本信息
			file.Read(&m_width);
		    file.Read(&m_height);
		    file.Read(&m_gridSize);
		    file.Read(&m_gridColumn);
		    file.Read(&m_gridRow);
		    //读取碰撞信息
		    file.Read(&m_gridArrayLength);
		    file.Read(m_grid, m_gridArrayLength);
		    int listLength = 0;
		    file.Read(&listLength);
		    for (int index = 0; index < listLength; ++index)
		    {
		    	SceneInfo info;
		    	file.ReadClass(&info);
		    	m_info.push_back(info);
		    }
	    }
	    
	}
	void Scene::SetSceneName(const char *sceneName)
	{
		memset(m_sceneName, 0, sizeof(m_sceneName));
		strcpy(m_sceneName, sceneName);
	}
	void Scene::SetArea(int width, int height, int gridSize)
	{
		if (0 == gridSize)
		{
			return;
		}
		m_width = width;
		m_height = height;
		m_gridSize = gridSize;
		m_gridColumn = m_width / m_gridSize + 1;
		m_gridRow = m_height / m_gridSize + 1;
		if (NULL != m_grid)
		{
			delete[] m_grid;
		}
		m_gridArrayLength = m_gridColumn * m_gridRow / sizeof(char);
		m_grid = new char[m_gridArrayLength];
		memset(m_grid, 0, m_gridArrayLength);
	}
	bool Scene::GetGrid(int x, int y)
	{
		int pos = y * m_gridColumn + x;
		int index = pos / sizeof(char);
		int charPos = pos % sizeof(char);
		return m_grid[index] & (1 << charPos);
	}
	void Scene::SetGrid(int x, int y, bool isPass)
	{
		int pos = y * m_gridColumn + x;
		int index = pos / sizeof(char);
		int charPos = pos % sizeof(char);
		if (isPass)
		{
			m_grid[index] |= (1 << charPos);
		}
		else
		{
			m_grid[index] &= ~(1 << charPos);
		}
	}





	FileHelper::FileHelper(const char *fileName, const char *type)
	:m_needClose(true)
	{
		m_file = fopen(fileName, type);
	}
	FileHelper::~FileHelper(void)
	{
		if (m_needClose)
		{
			fclose(m_file);
		}
	}
}
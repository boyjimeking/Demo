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
	struct SceneInfo
	{
		float m_x;
		float m_y;
		char m_imageName[128];
		static void Read(FILE *file, SceneInfo *info);
		static void Write(FILE *file, SceneInfo *info);
	};

	class Scene
	{
	public:
		Scene(void);
		~Scene(void);

		void Save(const char *fileName);
		void Load(const char *fileName);

		void SetSceneName(const char *sceneName);
		void SetArea(int width, int height, int gridSize);

		int GetWidth(void) const { return m_width; }
		int GetHeight(void) const { return m_height; }
		int GetColumn(void) const { return m_gridColumn; }
		int GetRow(void) const { return m_gridRow; }
		int GetGridSize(void) const { return m_gridSize; }

		bool GetGrid(int x, int y);
		void SetGrid(int x, int y, bool isPass);
	private:
		char m_sceneName[128];
		int m_width;
		int m_height;
		int m_gridSize;
		int m_gridColumn;
		int m_gridRow;
		char *m_grid;
		int m_gridArrayLength;
		typedef std::list<SceneInfo> InfoList;
		InfoList m_info;

		int m_readVersion;
		int m_currentVersion;
		enum
		{
			enBaseVersion,
			enCurrentVersion = enBaseVersion,
		};

	};

	class FileHelper
	{
	public:
		FileHelper(const char *fileName, const char *type);
		FileHelper(FILE *file) : m_file(file), m_needClose(false) {}
		~FileHelper(void);

		template<typename T>
		void Read(T *mem)
		{
			fread(mem, sizeof(T), 1, m_file);
		}
		void Read(char *mem, int length)
		{
			fread(mem, length, 1, m_file);
		}
		template<typename T>
		void ReadClass(T *mem)
		{
			T::Read(m_file, mem);
		}

		template<typename T>
		void Write(T *mem)
		{
			fwrite(mem, sizeof(T), 1, m_file);
		}
		void Write(char *mem, int length)
		{
			fwrite(mem, length, 1, m_file);
		}
		template<typename T>
		void WriteClass(T *mem)
		{
			T::Write(m_file, mem);
		}
	private:
		FILE *m_file;
		bool m_needClose;
	};
}

#endif /* defined(__Buildings__Scene__) */

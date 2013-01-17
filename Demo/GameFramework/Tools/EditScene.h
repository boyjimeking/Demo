//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Tools
//	created:	2012-12-17
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EditScene_h__
#define EditScene_h__

#include "../../Tools/Scene.h"

namespace Tools
{
	class EditScene
		:public Scene
	{
	public:
		EditScene(void);
		virtual ~EditScene(void);

		void Load(unsigned char *data, int dataLength);
		void Create(float width, float height, float gridSize, float transScale/* point per meter */);
		int Save(unsigned char *data, int dataLength);

		void SetSceneName(const char *sceneName);
		void SetGridPassState(int x, int y, bool isPass);

		void AddObjectImage(const char *imageName);
		void RemoveObjectImage(const char *imageName);
		unsigned int GetImageCount(void) const { return m_imageName.size(); }
		const char* GetImage(int index) const { return m_imageName[index].c_str(); }

		int AddObject(const char *image, float x, float y, float width, float height);
		void ChangeObject(int id, const char *image, float x, float y, float width, float height);
		void RemoveObject(int id);
		unsigned int GetObjectCount(void) const { return m_objectInfoList.size(); }
		ObjectInfo* GetObject(int index) const { return m_objectInfoList[index]; }


		int AddTerrain(const char *image, float x, float y, float width, float height);
		void ChangeTerrain(int id, const char *image, float x, float y, float width, float height);
		void RemoveTerrain(int id);
		unsigned int GetTerrainCount(void) const { return m_terrainInfoList.size(); }
		TerrainInfo* GetTerrain(int index) const { return m_terrainInfoList[index]; }

		void SetBackgroundMusic(const char *fileName) { m_backgroundMusic = fileName; }

		void Clear(void);
	protected:

	private:
		int m_terrainCount;
		int m_objectCount;
	};
}

#endif // EditScene_h__

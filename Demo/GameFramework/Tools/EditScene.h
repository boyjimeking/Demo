//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Tools
//	created:	2012-12-17
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef EditScene_h__
#define EditScene_h__

#include "Scene.h"

namespace Tools
{
	class EditScene
		:public Scene
	{
	public:
		EditScene(void);
		virtual ~EditScene(void);

		void Load(unsigned char *data, int dataLength);
		void Create(float width, float height, float gridSize, int transScale/* point per meter */);
		int Save(unsigned char *data, int dataLength);

		void SetSceneName(const char *sceneName);
		void SetGridPassState(int x, int y, bool isPass);

		void AddObjectImage(const char *imageName);
		void RemoveObjectImage(const char *imageName);

		int AddObject(const char *image, float x, float y, float width, float height);
		void ChangeObject(int id, const char *image, float x, float y, float width, float height);
		void RemoveObject(int id);

		int AddTerrain(const char *image, float x, float y, float width, float height);
		void ChangeTerrain(int id, const char *image, float x, float y, float width, float height);
		void RemoveTerrain(int id);
	protected:

	private:
		int m_terrainCount;
		int m_objectCount;
	};
}

#endif // EditScene_h__

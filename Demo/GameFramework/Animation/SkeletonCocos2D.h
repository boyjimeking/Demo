//tgame Created
#ifndef _19112012_SkeletonCocos2D
#define _19112012_SkeletonCocos2D

#include "Skeleton2D.h"
#include "cocos2d.h"

using namespace cocos2d;

class Skeleton2D_BoneDisplay
	:public CCSprite
{
public:
	static Skeleton2D_BoneDisplay* createWithSpriteFrameName(const char *pszSpriteFrameName,float anchorX,float anchorY);
	virtual CCAffineTransform nodeToParentTransform(void);
	virtual void updateTransform(void);

	void SetMat(const Skel_Matrix2D& mat,int boneID){
		m_mat=mat;
		m_boneID=boneID;
		m_bTransformDirty = m_bInverseDirty = true;
		setDirty(true);
	}
	int m_boneID;
	Skel_Matrix2D	m_mat;
};

class SkeletonCocos2D
	:public CCNode
{
public:
	SkeletonCocos2D(void);
	~SkeletonCocos2D(void);

	void Load(const char* skelFilename, const char* texFilenameDesc, const char* texFilename, const char* useSkeletonName);
	void UpdateBoneImages(void);
	virtual void update(float dt);

	Skeleton2D* GetSkeleton(void) const { return m_skeleton; }
private:
	Skeleton2D*	m_skeleton;
	class Skeleton2DResourceAvatar *m_resource;
	class Skeleton2DResourceTexture *m_textureDesc;
	//////////////////////////////////////////////////////////////////////////
	CCSpriteBatchNode*	m_batchSprite;
	struct BoneDisplayInfo 
	{
		int m_imgID;
		Skeleton2D_BoneDisplay*	m_sprite;
		BoneDisplayInfo(void):m_sprite(0),m_imgID(-1){}
	};
	std::vector<BoneDisplayInfo>	m_boneSprites;
};

#endif

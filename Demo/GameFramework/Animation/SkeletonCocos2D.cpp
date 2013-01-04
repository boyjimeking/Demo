#include "SkeletonCocos2D.h"

int SkeletonCocos2D::g_tm_type=1;
#if CC_SPRITEBATCHNODE_RENDER_SUBPIXEL
#define RENDER_IN_SUBPIXEL
#else
#define RENDER_IN_SUBPIXEL(__A__) ( (int)(__A__))
#endif

CCAffineTransform Skeleton2D_BoneDisplay::nodeToParentTransform(void){
	m_sTransform=CCAffineTransformMake(m_mat.a,m_mat.b,m_mat.c,m_mat.d,m_mat.tx,m_mat.ty);
	if (!m_obAnchorPointInPoints.equals(CCPointZero))
	{
		m_sTransform.tx -= m_sTransform.a * m_obAnchorPointInPoints.x + m_sTransform.c * m_obAnchorPointInPoints.y;
		m_sTransform.ty -= m_sTransform.b * m_obAnchorPointInPoints.x + m_sTransform.d * m_obAnchorPointInPoints.y;
	}
	return m_sTransform;
}
void Skeleton2D_BoneDisplay::updateTransform(void)
{
	CCAssert(m_pobBatchNode, "updateTransform is only valid when CCSprite is being rendered using an CCSpriteBatchNode");

	// recalculate matrix only if it is dirty
	if( isDirty() ) {

		// If it is not visible, or one of its ancestors is not visible, then do nothing:
		//if( !IsVisable() || ( m_pParent && m_pParent != m_pobBatchNode /*&& ((CCSprite*)m_pParent)->m_bShouldBeHidden*/) )
		if (false)
		{
			m_sQuad.br.vertices = m_sQuad.tl.vertices = m_sQuad.tr.vertices = m_sQuad.bl.vertices = vertex3(0,0,0);
			m_bShouldBeHidden = true;
		}
		else 
		{//
			CCAffineTransform tm;
			m_bShouldBeHidden = false;

			tm = nodeToParentTransform();
			//
			// calculate the Quad based on the Affine Matrix
			//

			CCSize size = m_obRect.size;

			float x1 = m_obOffsetPosition.x;
			float y1 = m_obOffsetPosition.y;

			float x2 = x1 + size.width;
			float y2 = y1 + size.height;
			float x = tm.tx;
			float y = tm.ty;

			float cr = tm.a;
			float sr = tm.b;
			float cr2 = tm.d;
			float sr2 = -tm.c;
			float ax = x1 * cr - y1 * sr2 + x;
			float ay = x1 * sr + y1 * cr2 + y;

			float bx = x2 * cr - y1 * sr2 + x;
			float by = x2 * sr + y1 * cr2 + y;

			float cx = x2 * cr - y2 * sr2 + x;
			float cy = x2 * sr + y2 * cr2 + y;

			float dx = x1 * cr - y2 * sr2 + x;
			float dy = x1 * sr + y2 * cr2 + y;

			ax*=-1.0f;ay*=-1.0f;bx*=-1.0f;by*=-1.0f;cx*=-1.0f;cy*=-1.0f;dx*=-1.0f;dy*=-1.0f;

			m_sQuad.bl.vertices = vertex3( RENDER_IN_SUBPIXEL(ax), RENDER_IN_SUBPIXEL(ay), m_fVertexZ );
			m_sQuad.br.vertices = vertex3( RENDER_IN_SUBPIXEL(bx), RENDER_IN_SUBPIXEL(by), m_fVertexZ );
			m_sQuad.tl.vertices = vertex3( RENDER_IN_SUBPIXEL(dx), RENDER_IN_SUBPIXEL(dy), m_fVertexZ );
			m_sQuad.tr.vertices = vertex3( RENDER_IN_SUBPIXEL(cx), RENDER_IN_SUBPIXEL(cy), m_fVertexZ );
		}

		m_pobTextureAtlas->updateQuad(&m_sQuad, m_uAtlasIndex);
		m_bRecursiveDirty = false;
		setDirty(false);
	}

	// recursively iterate over children
	if( m_bHasChildren ) 
	{
		arrayMakeObjectsPerformSelector(m_pChildren, updateTransform, CCSprite*);
	}
#if CC_SPRITE_DEBUG_DRAW
	// draw bounding box
	CCPoint vertices[4] = {
		ccp( m_sQuad.bl.vertices.x, m_sQuad.bl.vertices.y ),
		ccp( m_sQuad.br.vertices.x, m_sQuad.br.vertices.y ),
		ccp( m_sQuad.tr.vertices.x, m_sQuad.tr.vertices.y ),
		ccp( m_sQuad.tl.vertices.x, m_sQuad.tl.vertices.y ),
	};
	ccDrawPoly(vertices, 4, true);
#endif // CC_SPRITE_DEBUG_DRAW
}
Skeleton2D_BoneDisplay* Skeleton2D_BoneDisplay::createWithSpriteFrameName(const char *pszSpriteFrameName,float anchorX,float anchorY)
{
	CCSpriteFrame *pSpriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(pszSpriteFrameName);

#if COCOS2D_DEBUG > 0
	char msg[256] = {0};
	sprintf(msg, "Invalid spriteFrameName: %s", pszSpriteFrameName);
	CCAssert(pSpriteFrame != NULL, msg);
#endif

	Skeleton2D_BoneDisplay *pobSprite = new Skeleton2D_BoneDisplay();
	if (pSpriteFrame && pobSprite && pobSprite->initWithSpriteFrame(pSpriteFrame))
	{
		pobSprite->setFlipY(true);
		pobSprite->autorelease();
		CCPoint poffset(anchorX,anchorY);
		CCSize psize=pSpriteFrame->getOriginalSize();
		float _anchorPointX = poffset.x / psize.width;
		float _anchorPointY = (poffset.y) / psize.height;
		pobSprite->setAnchorPoint(ccp(_anchorPointX, _anchorPointY));
		return pobSprite;
	}
	CC_SAFE_DELETE(pobSprite);
	return NULL;
}


SkeletonCocos2D::SkeletonCocos2D(void)
	:m_skeleton(0)
{
	m_skeleton=new Skeleton2D;
}
SkeletonCocos2D::~SkeletonCocos2D(void)
{
	delete m_skeleton;
}


void SkeletonCocos2D::Load(const char* skelFilename,const char* texFilenameDesc
	,const char* texFilename,const char* useSkeletonName)
{
	//////////////////////////////////////////////////////////////////////////
	unsigned long	_size=0;
	char			*_pFileContent = (char*)CCFileUtils::sharedFileUtils()->getFileData(skelFilename , "r", &_size);
	TiXmlDocument	_document;
	_document.Parse(_pFileContent, 0, TIXML_ENCODING_UTF8);
	m_resource=new Skeleton2DResourceAvatar;
	m_resource->LoadAll(_document.RootElement());
	m_skeleton->AttachResource(m_resource->GetSkeleton(useSkeletonName));
	//////////////////////////////////////////////////////////////////////////
	char			*texDescContent = (char*)CCFileUtils::sharedFileUtils()->getFileData(texFilenameDesc , "r", &_size);
	TiXmlDocument	xmlTexDesc;
	xmlTexDesc.Parse(texDescContent, 0, TIXML_ENCODING_UTF8);
	m_textureDesc = m_resource->AddTextureResource(xmlTexDesc.RootElement());
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(texFilename);
	for (std::map<RString,Skeleton2DResourceSubTexture>::iterator it = m_textureDesc->m_subTexs.begin()
		;it != m_textureDesc->m_subTexs.end();++it)
	{
		const RString& subTexName=it->first;
		Skeleton2DResourceSubTexture& subData=it->second;
		CCSpriteFrame* spriteFrame = new CCSpriteFrame();
		spriteFrame->initWithTexture(texture, 
			CCRectMake(subData.x, subData.y, subData.width, subData.height), 
			false,
			//CCPointMake(subData.pivotX,subData.pivotY),
			CCPointMake(0,0),
			CCSizeMake((float)subData.width, (float)subData.height)
			);
		CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(spriteFrame,subTexName.c_str());
	}

	m_batchSprite = CCSpriteBatchNode::create(texFilename);
	addChild(m_batchSprite);

	UpdateBoneImages();
	this->scheduleUpdate();
}
void SkeletonCocos2D::update(float dt)
{
	dt*=1000.0f;
	m_skeleton->Update(dt);
	for (size_t i=0;i<m_skeleton->GetBoneMaxID();i++)
	{
		Skeleton2DBone* bone = m_skeleton->GetBone(i);
		if (!bone)
		{
			continue;
		}
		BoneDisplayInfo&	displayInfo = m_boneSprites[i];
		int imgID = bone->GetImageID();
		if (imgID != displayInfo.m_imgID)
		{
			if (displayInfo.m_sprite)
			{
				m_batchSprite->removeChild(displayInfo.m_sprite,false);
				//displayInfo.m_sprite->release();
				displayInfo.m_sprite=0;
			}
			displayInfo.m_imgID=imgID;
			const Skeleton2DResourceAvatar::Skeleton2DImage* imgData = m_resource->GetImageDataByID(imgID);
			displayInfo.m_sprite = Skeleton2D_BoneDisplay::createWithSpriteFrameName(imgData->m_name.c_str()
				,imgData->m_subTexture->pivotX,imgData->m_subTexture->pivotY);
			m_batchSprite->addChild(displayInfo.m_sprite);
		}

		displayInfo.m_sprite->SetMat(bone->GetFinalMatrix(),i);
	}
}
void SkeletonCocos2D::UpdateBoneImages(void)
{
	if (m_boneSprites.size() != m_skeleton->GetBoneMaxID())
	{
		m_boneSprites.resize(m_skeleton->GetBoneMaxID());
	}
	for (size_t i=0;i<m_skeleton->GetBoneMaxID();i++)
	{
		Skeleton2DBone* bone = m_skeleton->GetBone(i);
		if (!bone)
		{
			continue;
		}
		BoneDisplayInfo&	displayInfo = m_boneSprites[i];
		int imgID = bone->GetImageID();
		if (imgID != displayInfo.m_imgID)
		{
			if (displayInfo.m_sprite)
			{
				displayInfo.m_sprite->release();
				displayInfo.m_sprite=0;
			}
			displayInfo.m_imgID=imgID;
			const Skeleton2DResourceAvatar::Skeleton2DImage* imgData = m_resource->GetImageDataByID(imgID);
			displayInfo.m_sprite = Skeleton2D_BoneDisplay::createWithSpriteFrameName(imgData->m_name.c_str()
				,imgData->m_subTexture->pivotX,imgData->m_subTexture->pivotY);
			m_batchSprite->addChild(displayInfo.m_sprite);
		}
	}
}
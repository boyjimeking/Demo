//tgame Created
#ifndef _16112012_Skeleton2DResource
#define _16112012_Skeleton2DResource

#include "SkeletonDef.h"

struct Skeleton2DTransform
{
	//����
	float x;
	float y;
	//����
	float scaleX;
	float scaleY;
	//Ť��
	float skewX;
	float skewY;
	int z;
	Skeleton2DTransform(void)
		:x(0.0f),y(0.0f),scaleX(1.0f),scaleY(1.0f),skewX(0.0f),skewY(0.0f),z(0)
	{}
	void Reset(void){
		x=(0.0f);y=(0.0f);scaleX=(1.0f);scaleY=(1.0f);skewX=(0.0f);skewY=(0.0f);z=(0);
	}
	void ReadFromXml(TiXmlElement* node,bool readScale=false);
	void transfromPointWithParent(const Skeleton2DTransform& parent) 
	{
		Skel_Matrix2D helpMatrix1;
		Skel_Matrix2D helpMatrix2;
		this->nodeToMatrix(helpMatrix1);
		parent.nodeToMatrix(helpMatrix2);
		helpMatrix2.invert();
		helpMatrix1.concat(helpMatrix2);
		FromMatrix(helpMatrix1);
	}

	void nodeToMatrix(Skel_Matrix2D& _matrix)const
	{
		const Skeleton2DTransform& node=*this;
		_matrix.a = node.scaleX * _Skeleton2D_Cos_(node.skewY);
		_matrix.b = node.scaleX *  _Skeleton2D_Sin_(node.skewY);
		_matrix.c = -node.scaleY * _Skeleton2D_Sin_(node.skewX);
		_matrix.d = node.scaleY * _Skeleton2D_Cos_(node.skewX);

		_matrix.tx = node.x;
		_matrix.ty = node.y;
	}

	void FromMatrix(Skel_Matrix2D& mat){
		float x1 = 0.0f;
		float y1 = 1.0f;
		mat.deltaTransformPoint(x1,y1);
		//helpPoint1 = _matrix.deltaTransformPoint(helpPoint1);
		float x2 = 1.0f;
		float y2 = 0.0f;
		mat.deltaTransformPoint(x2,y2);
		//helpPoint2 = _matrix.deltaTransformPoint(helpPoint2);

		skewX = _Skeleton2D_Atan2_(y1,x1) - HALF_PI;
		skewY = _Skeleton2D_Atan2_(y2,x2);
		scaleX = _Skeleton2D_Sqrt_(mat.a * mat.a + mat.b * mat.b);
		scaleY = _Skeleton2D_Sqrt_(mat.c * mat.c + mat.d * mat.d);
		x = mat.tx;
		y = mat.ty;
	}
};
struct Skeleton2D_TweenData 
	:public Skeleton2DTransform
{
	int tweenRotate;
	Skeleton2D_TweenData(void):tweenRotate(0.0f){}
	inline void subtract(const Skeleton2DTransform& from,const Skeleton2D_TweenData& to);
};

//!λ��֡
struct Skeleton2DTrasform_Bone
	:public Skeleton2D_TweenData
{
	short m_imgID;
	//!��ʼDuration
	short m_startDuration;
	//!���ؼ�֡��������Duration����λʱ��;
	short m_duration;
	bool  m_visible;
	bool  m_active;
	float m_rotation;
	float m_alpha;
	float m_tweenEasing;
	Skeleton2DTrasform_Bone(void)
		:m_imgID(0),m_startDuration(0),m_duration(0)
		,m_visible(true),m_active(true),m_rotation(0.0f),m_alpha(1.0f),m_tweenEasing(1.0f)
	{

	}
};
//!һ�������Ķ���(MovementBoneData)
struct Skeleton2DBone_Animation 
{
	//CCBoneAniData
#ifdef _Skeleton2D_Debug_
	//!��������
	RString	m_boneName;
#endif
	//!����ID
	int	m_boneID;
	//!m_keyList��Skeleton2DAnimation�е���ʼλ��
	size_t m_startKeyIndex;
	//!�ؼ�֡����
	int m_keyCount;
	//!�ؼ�֡�б�
	Skeleton2DTrasform_Bone*	m_keyList;
	/*�������ڶ����еĲ����ٶȰٷֱ�,������*/
	float m_scale;
	/*�������ڶ����е��ӳ�ʱ��ٷֱ�,������*/
	float m_delay;
protected:
	//!����ʱ��=m_duration*����ÿ֡,��������,��ȡ������֡�������
	int	m_duration;
public:
	Skeleton2DBone_Animation(void)
		:m_boneID(0),m_startKeyIndex(0),m_keyCount(0),m_keyList(0),m_scale(1.0f),m_delay(0.0f),m_duration(0)
	{

	}
	//!����ʱ��=m_duration*����ÿ֡,��������,��ȡ������֡�������
	int GetDurationTotal(void){return m_duration;}
	//!�Ƿ��ӳ�
	bool HaveDelay(void){return abs(m_delay)>0.0001f;}
	Skeleton2DTrasform_Bone* GetBoneKey(int idx){
		if (idx<m_keyCount){
			return &m_keyList[idx];}
		return 0;
	}
	inline void UpdateDurationTotal(void);
};
//!�Ǽ�����Ķ���
struct Skeleton2DAnimation
{
	RVector<Skeleton2DBone_Animation>::T	m_boneList;
	//!���ݹ���id��ȡ������Ӧ�Ķ�������
	inline Skeleton2DBone_Animation* GetBoneAnimation(int boneID);
	//!��������
	RString	m_aniName;
	/**�ܼƶ��ٸ�Duration,Ӧ����Skeleton2DBone_Animation::m_duration���
	*��Ӧ����Flash�е�֡��
	*/
	int m_duration;
	/**�������������Ŵ˶���ʱ,�������Duration���˶���������
	*����ѭ������ʱ,�������
	*/
	int m_durationInsertWhenPlay;
	/**�������ŵ����ٸ�Duration
	*����:m_duration=30,m_durationScaleTo=90
	*��ʾ����3�����ٶȲ���
	*/
	int m_durationScaleTo;
	//!�����Ƿ�ѭ��
	bool m_isLoop;
	//!���仺��(��ʱ�䰴�����߱任)
	float m_tweenEasing;
};

//!�������
struct Skeleton2DBoneResource
	:public Skeleton2DTransform
{
public:
	int m_boneID;
	int	m_parentBoneID;
	RString m_name;

	int m_defaultImageID;
	//RString m_parentName;
	//ͼƬ����(δ֪Ϊ��Ҫ������)
	float m_pivotX;
	float m_pivotY;
	//ͼƬ��С(δ֪Ϊ��Ҫ������)
	float m_width;
	float m_height;
};

class Skeleton2DResourceAvatar;

//!�Ǽ���Դ����
class Skeleton2DResource
{
public:
	Skeleton2DResource(void);
	~Skeleton2DResource(void);
	void LoadSkeleton(TiXmlElement* skeletonXmlNode,TiXmlElement* aniListNode,Skeleton2DResourceAvatar* avatar);
	//////////////////////////////////////////////////////////////////////////
	inline RVector<Skeleton2DBoneResource>::T& GetBoneList(void);
	inline Skeleton2DAnimation*	LookupAnimation(const RString& name);
	inline Skeleton2DBoneResource* GetBone(int boneID);
	inline const RString& GetName(void);
	inline size_t AddBoneKey(const Skeleton2DTrasform_Bone& key);
	inline Skeleton2DTrasform_Bone*	GetKeyArray(size_t idx);
	inline size_t GetKeyBufferSize(void);
	//////////////////////////////////////////////////////////////////////////
	void AddRef(void){}
	void Release(void){}
protected:
	RString	m_name;
	//!�����б�,�����ǿ��Ժ͹Ǽ����ݷ����
	RVector<Skeleton2DAnimation*>::T	m_animationList;
	//!�ؼ�֡����buffer
	RVector<Skeleton2DTrasform_Bone>::T m_keyBuffer;
	//!�������ṹ.���ո��ӹ�ϵ����,Updateʱ,ֱ�ӱ�������
	RVector<Skeleton2DBoneResource>::T m_boneList;
};

struct Skeleton2DResourceSubTexture;
class Skeleton2DResourceTexture;
//!��������Ǽ���Ϣ
class Skeleton2DResourceAvatar
{
public:
	Skeleton2DResourceAvatar(void);
	~Skeleton2DResourceAvatar(void);
	void LoadAll(TiXmlElement* rootNode);
	Skeleton2DResourceTexture* AddTextureResource(TiXmlElement* textureNode);
	Skeleton2DResource* GetSkeleton(const RString& name);
	struct Skeleton2DImage 
	{
		int		m_id;
		RString	m_name;
		bool	m_isSkeleton;
		Skeleton2DResourceSubTexture*	m_subTexture;
		Skeleton2DImage(void):m_id(0),m_isSkeleton(false),m_subTexture(0){}
	};
	int AddImage(Skeleton2DImage& image);
	const RString& GetImageByID(int id);
	const Skeleton2DImage* GetImageDataByID(int id);
	void AttachTextureResource(Skeleton2DResourceTexture* tex);
protected:
	RVector<Skeleton2DResource*>::T	m_skeletonList;
	RString	m_name;
	float	m_frameRate;
	RVector<Skeleton2DImage>::T	m_images;
	RVector<Skeleton2DResourceTexture*>::T	m_texResources;
};

//!��ͼƬ
struct Skeleton2DResourceSubTexture
{
public:
	Skeleton2DResourceSubTexture(void);
	void Load(TiXmlElement* xml);

	int x;
	int y;
	int width;
	int height;
	int pivotX;
	int pivotY;
	RString	name;
};

//!ͼƬ
class Skeleton2DResourceTexture
{
public:
	Skeleton2DResourceTexture(void);
	void Load(TiXmlElement* xml);
	Skeleton2DResourceSubTexture* LookupSubTexture(const RString& name);
	typedef std::map<RString,Skeleton2DResourceSubTexture> Name2SubTexture;
	std::map<RString,Skeleton2DResourceSubTexture>	m_subTexs;
	RString	m_name;
	unsigned int m_width;
	unsigned int m_height;
};

const RString& Skeleton2DResource::GetName(void){
	return m_name;
}
RVector<Skeleton2DBoneResource>::T& Skeleton2DResource::GetBoneList(void){
	return m_boneList;
}
Skeleton2DAnimation*	Skeleton2DResource::LookupAnimation(const RString& name){
	for (size_t i=0;i<m_animationList.size();i++)
	{
		Skeleton2DAnimation* ani = m_animationList[i];
		if (ani->m_aniName==name)
		{
			return ani;
		}
	}
	return 0;
}
Skeleton2DBoneResource* Skeleton2DResource::GetBone(int boneID){
	if (boneID>=0&&boneID<m_boneList.size())
	{
		return &m_boneList[boneID];
	}
	return 0;
}
size_t Skeleton2DResource::AddBoneKey(const Skeleton2DTrasform_Bone& key){
	size_t i=m_keyBuffer.size();
	m_keyBuffer.push_back(key);
	return i;
}
Skeleton2DTrasform_Bone* Skeleton2DResource::GetKeyArray(size_t idx){
	if (idx<m_keyBuffer.size())
	{
		return &m_keyBuffer[idx];
	}
	return 0;
}
size_t Skeleton2DResource::GetKeyBufferSize(void){
	return m_keyBuffer.size();
}

//////////////////////////////////////////////////////////////////////////

Skeleton2DBone_Animation* Skeleton2DAnimation::GetBoneAnimation(int boneID){
	if (boneID>=0&&boneID<m_boneList.size())
	{
		return &m_boneList[boneID];
	}
	return 0;
}


//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
void Skeleton2D_TweenData::subtract(const Skeleton2DTransform& from,const Skeleton2D_TweenData& to)
{
	static const float _PI = 3.1415926f;
	static const float DOUBLE_PI = _PI * 2.0f;
	x = to.x - from.x;
	y = to.y - from.y;
	scaleX = to.scaleX - from.scaleX;
	scaleY = to.scaleY - from.scaleY;
	skewX = to.skewX - from.skewX;
	skewY = to.skewY - from.skewY;

	skewX = FLoatMod(skewX,DOUBLE_PI,65536);
	if (skewX > _PI) 
	{
		skewX -= DOUBLE_PI;
	}
	if (skewX < -_PI)
	{
		skewX += DOUBLE_PI;
	}
	skewY = FLoatMod(skewY,DOUBLE_PI,65536);
	if (skewY > _PI)
	{
		skewY -= DOUBLE_PI;
	}
	if (skewY < -_PI)
	{
		skewY += DOUBLE_PI;
	}
	if (to.tweenRotate)
	{
		skewX += to.tweenRotate * DOUBLE_PI;
		skewY += to.tweenRotate * DOUBLE_PI;
	}
}

void Skeleton2DBone_Animation::UpdateDurationTotal(void){
	m_duration=0;
	for (int i=0;i<this->m_keyCount;i++)
	{
		Skeleton2DTrasform_Bone& boneInfo = m_keyList[i];
		boneInfo.m_startDuration=m_duration;
		m_duration+=boneInfo.m_duration;
	}
}

#endif

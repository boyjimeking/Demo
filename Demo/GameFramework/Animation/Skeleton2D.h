//tgame Created
#ifndef _16112012_Skeleton2D
#define _16112012_Skeleton2D

#include "SkeletonDef.h"
#include "Skeleton2DResource.h"

class Skeleton2D;

/**单块骨骼
*动画时长(毫秒):
((Skeleton2DBone_Animation::GetDurationTotal()*Skeleton2DBone_Animation::m_scale
*Skeleton2DAnimation::m_durationScaleTo/Skeleton2DAnimation::m_duration)
+Skeleton2DAnimation::m_durationInsertWhenPlay)*T
检查当前at(相对动画时长的比例)使用哪个关键帧:
[drInsert=10][dr=3,dr=4,dr=2]
先找到是第几个dr
runtimeduration=Skeleton2DAnimation::m_durationScaleTo*at
*/
class Skeleton2DBone
{
public:
	Skeleton2DBone(void);
	void Init2DBone(Skeleton2D* skeleton,int boneID);
	/**播放动画
	*@param isbackward表示后退播放
	*/
	void SetAnimation(Skeleton2DAnimation* ani
		,int durationScaleTo,int insertDuration,bool isLoop,float tweenEasing
		,bool isbackward);
	void Update(float deltaDuration);
	void UpdateTo(float normalizeTime,bool isbackward);
	//!外部可控的变换,与本身动画会进行累加
	inline Skeleton2DTransform& GetControlTransform(void);
	//!是否显示
	inline bool IsVisable(void);
	//!获取显示图片ID
	inline int GetImageID(void);
	//!获取最终变换的数据
	inline const Skeleton2DTrasform_Bone& GetFinalTransform(void);
	inline const Skel_Matrix2D& GetFinalMatrix(void);
	inline const Skeleton2DTrasform_Bone& GetTweenTransform(void);
	inline Skeleton2DBone* GetParentBone(void);
protected:
	inline float ModNormalizeTime(float normaizeTime);
	//!构建最终的更新矩阵
	void UpdateFinalTransform(void);
	//!计算normalizeTime时间的插值结果
	void CalcTween(float normalizeTime,bool isbackward,Skeleton2DTrasform_Bone& result);
	//!计算动画归一化时间(相对于整个动画)的关键帧
	int GetDurationIndexByNormalizeTime(float normalizeTime,int searchStartIndex
		,bool isbackward,int& durationCount);
	//!关键帧变化了
	void OnBaseKeyChanged(Skeleton2DTrasform_Bone& key);
	//!缓动算法
	float getEaseValue(float value,float easing);
	//!设置补间数据
	void SetTween(const Skeleton2DTransform& from,const Skeleton2DTrasform_Bone& to);
	//!检查是否到了下一个Key
	void CheckIsNextKey(void);
	void TweenTransform(float s,const Skeleton2DTransform& from
		,const Skeleton2D_TweenData& tweenData
		,Skeleton2DTransform& result);
	//!当前骨架
	Skeleton2D*	m_skeleton;
	//!当前动画
	Skeleton2DBone_Animation*	m_animation;
	//!
	Skeleton2DAnimation*	m_skeletonAni;
	//!骨骼ID
	int	m_boneID;
	Skeleton2DBoneResource*	m_boneOrigin;
	//!父骨骼
	Skeleton2DBone*	m_parentBone;
	//!子骨骼数量
	int		m_childBoneCount;
	//!当前动画缓动
	float	m_tweenEasing;
	//!是否开启动画缓动
	bool	m_isTweenEasing;
	//////////////////////////////////////////////////////////////////////////
	//!当前补间插值基础索引
	int m_curBaseDurationIndex;
	//!补间插值起始值
	Skeleton2DTransform	m_from;
	//!补间插值数据(对于m_from而言,是个增量)
	Skeleton2D_TweenData	m_tweenData;
	//!当前插值变化数据
	Skeleton2DTrasform_Bone	m_tweenTransformResult;
	//!最终的骨骼变换数据
	Skeleton2DTrasform_Bone	m_finalTransformResult;
	//!最终的骨骼变换矩阵
	Skel_Matrix2D	m_finalMatrix;
	//!子骨骼使用这个矩阵进行变换
	Skel_Matrix2D	m_childMatrix;
	//!当前图片ID
	int		m_currentImageID;
	//////////////////////////////////////////////////////////////////////////
	//!是否循环
	bool m_isLoop;
	//!当前动画总Duration
	int m_duration;
	//!缩放当前动画到多少Duration
	int m_durationScaleTo;
	//!动作过渡插入的Duration数量
	int m_durationInsert;
	//!当前动画归一化时间
	float m_curNormalizeTime;
	//!动作过渡阶段当前归一化时间
	float m_insertCurNormalizeTime;
	//!是否处在动画过渡期间
	bool  m_isInInsertDuration;
	//!是否可见
	bool m_isVisable;
	//!提供给外部控制的控制点
	Skeleton2DTransform	m_controlPoint;
};
#ifndef FLT_MAX
#define FLT_MAX __FLT_MAX__
#endif
#define _Tween_NaN_ FLT_MAX

//!骨架
class Skeleton2D
{
public:
	Skeleton2D(void);
	~Skeleton2D(void);
	//!关联资源
	void AttachResource(Skeleton2DResource* res);
	/**播放动画
	@param spd 播放速度
	@param insertDuration 插入多少单位时间来做动作过渡
	@param isLoop 是否循环播放
	@param tweenEasing 缓动数值
	*/
	void PlayAnimation(const RString& aniName,float spd=1.0f,int insertDuration=-1,int isLoop=2,float tweenEasing=_Tween_NaN_);
	//!设置动画的播放速度,当前动画和之后播放的动画将收到此设置的影响
	void SetAnimationSpeed(float spd);
	//!根据递增时间更新
	void Update(float dt);
	//!更新到动画的相对时间(0~1.0之间)
	void UpdateTo(float normalizeTime);

	struct StateAnimation 
	{
		StateAnimation(void):m_currentAnimation(0),m_isLoop(false),m_duration(0),m_durationScaleTo(0),m_durationInsert(0),m_currentPercent(0.0f),m_speed(1.0f){}
		//!当前动画
		Skeleton2DAnimation*	m_currentAnimation;
		//!是否循环
		bool m_isLoop;
		//!当前动画总Duration
		int m_duration;
		//!缩放当前动画到多少Duration
		int m_durationScaleTo;
		//!动作过渡插入的Duration数量
		int m_durationInsert;
		//!当前动画相对时间(0~1.0)
		float m_currentPercent;
		//!播放速度
		float m_speed;
	};
	//!获取骨骼的当前变换
	//inline Skeleton2DTransform&	GetBoneTransform(int boneID);
	//!骨架资源
	inline Skeleton2DResource*	GetResource(void);
	//!单骨骼资源
	inline Skeleton2DBoneResource* GetBoneResource(int boneID);
	//!获取单骨骼
	inline Skeleton2DBone*	GetBone(int boneID);
	//!获取骨骼数量(最大ID)
	inline size_t GetBoneMaxID(void);

protected:
	void InitBoneList(void);
	//!骨架资源
	Skeleton2DResource*	m_resource;
	//!运行期骨骼列表
	RVector<Skeleton2DBone>::T	m_boneList;
	RVector<Skeleton2DTransform>::T	m_boneTransform;
	//!动画状态
	StateAnimation	m_animationState;
	float m_scaleAnimationSpeed;
};
/*
//!获取骨骼的当前变换
Skeleton2DTransform&	Skeleton2D::GetBoneTransform(int boneID){
	if (boneID>=0&&boneID<m_boneList.size())
	{
		return m_boneList[boneID];
	}
	static Skeleton2DTransform nullTransform;
	return nullTransform;
}
*/
Skeleton2DResource*	Skeleton2D::GetResource(void){
	return m_resource;
}
//!单骨骼资源
Skeleton2DBoneResource* Skeleton2D::GetBoneResource(int boneID){
	return m_resource->GetBone(boneID);
}
Skeleton2DBone*	Skeleton2D::GetBone(int boneID){
	if(boneID>=0&&boneID<m_boneList.size()){
		return &m_boneList[boneID];
	}
	return 0;
}
size_t Skeleton2D::GetBoneMaxID(void){
	return m_boneList.size();
}

float Skeleton2DBone::ModNormalizeTime(float normaizeTime)
{
	float n = FLoatMod(normaizeTime,1.0f,65536);
	return n;
}
//!外部可控的变换,与本身动画会进行累加
Skeleton2DTransform& Skeleton2DBone::GetControlTransform(void){
	return m_controlPoint;
}
//!是否显示
bool Skeleton2DBone::IsVisable(void){
	return m_isVisable;
}
//!获取显示图片ID
int Skeleton2DBone::GetImageID(void){
	return m_currentImageID;
}

const Skeleton2DTrasform_Bone& Skeleton2DBone::GetFinalTransform(void){
	return m_finalTransformResult;}
const Skeleton2DTrasform_Bone& Skeleton2DBone::GetTweenTransform(void){
	return m_tweenTransformResult;
}
const Skel_Matrix2D& Skeleton2DBone::GetFinalMatrix(void){
	return m_finalMatrix;
}
Skeleton2DBone* Skeleton2DBone::GetParentBone(void){
	return m_parentBone;
}

#endif

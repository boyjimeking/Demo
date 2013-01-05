#include "Skeleton2D.h"


Skeleton2D::Skeleton2D(void)
	:m_resource(0),m_scaleAnimationSpeed(1.0f)
{
}
Skeleton2D::~Skeleton2D(void)
{
	
}
//!关联资源
void Skeleton2D::AttachResource(Skeleton2DResource* res)
{
	m_boneList.clear();
	m_resource=res;
	m_animationState.m_currentAnimation=0;
	if (m_resource)
	{
		InitBoneList();
	}
}
void Skeleton2D::InitBoneList(void)
{
	RVector<Skeleton2DBoneResource>::T& boneList = m_resource->GetBoneList();
	m_boneList.resize(boneList.size());
	for (size_t i=0;i<m_boneList.size();i++)
	{
		Skeleton2DBoneResource& boneInfo = boneList[i];
		m_boneList[i].Init2DBone(this,boneInfo.m_boneID);
	}
}
//!播放动画
void Skeleton2D::PlayAnimation(const RString& aniName,float spd
							   ,int insertDuration,int isLoop,float tweenEasing)
{
	if (!m_resource)
	{
		return;
	}
	Skeleton2DAnimation* ani = m_resource->LookupAnimation(aniName);
	if (!ani)
	{
		return;
	}

	m_animationState.m_currentAnimation=ani;
	m_animationState.m_duration=ani->m_duration;
	m_animationState.m_durationInsert=insertDuration>0?insertDuration:ani->m_durationInsertWhenPlay;
	m_animationState.m_durationScaleTo=ani->m_durationScaleTo;
	m_animationState.m_speed=spd;
	if (isLoop>1)
	{//外部不指定是否循环
		m_animationState.m_isLoop=ani->m_isLoop;
	}
	else
	{
		m_animationState.m_isLoop=isLoop?true:false;
		if(ani->m_isLoop && !isLoop)
		{
			m_animationState.m_duration--;
		}
	}
	tweenEasing = tweenEasing==_Tween_NaN_?ani->m_tweenEasing:tweenEasing;
	for (size_t i=0;i<m_boneList.size();i++)
	{
		Skeleton2DBone& bone = m_boneList[i];
		bone.SetAnimation(ani,m_animationState.m_durationScaleTo
			,m_animationState.m_durationInsert,m_animationState.m_isLoop,tweenEasing,spd<0.0f);
	}
}
void Skeleton2D::SetAnimationSpeed(float spd)
{
	m_scaleAnimationSpeed = spd;
}
//!根据递增时间更新
void Skeleton2D::Update(float dt)
{
	float deltaDuration=dt/40.0f;
	deltaDuration*=m_animationState.m_speed*m_scaleAnimationSpeed;
	if (!m_animationState.m_currentAnimation)
	{
		return;
	}
	for (size_t i=0;i<m_boneList.size();i++)
	{
		Skeleton2DBone& bone = m_boneList[i];
		bone.Update(deltaDuration);
	}
}
//!更新到动画的相对时间(0~1.0之间)
void Skeleton2D::UpdateTo(float normalizeTime)
{
	for (size_t i=0;i<m_boneList.size();i++)
	{
		Skeleton2DBone& bone = m_boneList[i];
		bone.UpdateTo(normalizeTime,m_animationState.m_speed<0.0f);
	}	
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
Skeleton2DBone::Skeleton2DBone(void)
	:m_skeleton(0),m_animation(0),m_skeletonAni(0),m_boneID(0),m_boneOrigin(0),m_parentBone(0),m_childBoneCount(0)
	,m_tweenEasing(1.0f),m_isTweenEasing(false),m_curBaseDurationIndex(-1),m_currentImageID(-1)
	,m_isLoop(false),m_duration(0),m_durationScaleTo(0),m_durationInsert(0)
	,m_curNormalizeTime(0.0f),m_insertCurNormalizeTime(0.0f),m_isInInsertDuration(false)
	,m_isVisable(true)
{
	m_controlPoint.scaleX=0.0f;
	m_controlPoint.scaleX=0.0f;
}
void Skeleton2DBone::Init2DBone(Skeleton2D* skeleton,int boneID)
{
	m_skeleton = skeleton;
	m_boneID=boneID;
	m_boneOrigin=skeleton->GetBoneResource(m_boneID);
	m_childBoneCount=0;
	m_parentBone = skeleton->GetBone(m_boneOrigin->m_parentBoneID);
	if (m_parentBone)
	{
		m_parentBone->m_childBoneCount++;
	}
	m_currentImageID=m_boneOrigin->m_defaultImageID;
	memcpy(&m_tweenTransformResult,m_boneOrigin,sizeof(Skeleton2DTransform));
	this->UpdateFinalTransform();
}

void Skeleton2DBone::SetAnimation(Skeleton2DAnimation* ani
	,int durationScaleTo,int insertDuration,bool isLoop,float tweenEasing
	,bool isbackward)
{
	m_animation=ani->GetBoneAnimation(m_boneID);
	if(!m_animation)
	{
		return;
	}
	if (0==m_animation->m_keyCount)
	{
		m_animation=0;
		return;
	}
	m_skeletonAni=ani;
	m_isLoop=isLoop;
	m_durationScaleTo=durationScaleTo*m_animation->m_scale;
	m_durationInsert=insertDuration;
	m_duration=m_animation->GetDurationTotal();//-m_isLoop?0:1;
	m_tweenEasing=_Skeleton2D_IsNAN(tweenEasing)?ani->m_tweenEasing:tweenEasing;
	m_isTweenEasing=!_Skeleton2D_IsNAN(m_tweenEasing);
	m_curBaseDurationIndex=-1;
	if (m_duration<=0)
	{
		m_duration=1;
	}
	m_isInInsertDuration=false;
	if (m_durationInsert>0)
	{
		//动画过渡
		m_insertCurNormalizeTime=0.0f;
		m_isInInsertDuration=true;
		Skeleton2DTrasform_Bone dstKey;
		if (m_animation->HaveDelay()&&m_isLoop)
		//if(false)
		{//有延迟
			//从1.0 -m_animation->m_delay点上获取一个作为起始点
			//获取m_duration*p位置的插值
			m_curNormalizeTime=1.0f-m_animation->m_delay;
			CalcTween(m_curNormalizeTime,isbackward,dstKey);
		}
		else
		{
			m_curNormalizeTime=0.0f;
			dstKey=*(m_animation->GetBoneKey(0));
		}
		SetTween(m_tweenTransformResult,dstKey);
	}
	else
	{
		UpdateTo(0.0f,isbackward);
	}
}
void Skeleton2DBone::UpdateTo(float normalizeTime,bool isbackward)
{
	if (0==m_animation)
	{
		return;
	}
	bool isEnd=false;
	Skeleton2DTrasform_Bone* baseKey = 0;
	if (normalizeTime>1.0f)
	{
		if (m_isLoop)
		{
			normalizeTime=ModNormalizeTime(normalizeTime);
		}
		else
		{
			normalizeTime=1.0f;
			isEnd=true;
		}
	}
	m_curNormalizeTime=normalizeTime;
	float durationTime = normalizeTime*(float)m_duration;

	bool forceSearch=false;
	if (m_curBaseDurationIndex<0)
	{
		forceSearch=true;
		m_curBaseDurationIndex=0;
	}
	else
	{
		baseKey=m_animation->GetBoneKey(m_curBaseDurationIndex);
	}

	if (isEnd)
	{
		int newDurationIndex=m_animation->m_keyCount-1;
		if (newDurationIndex!=m_curBaseDurationIndex)
		{
			baseKey=m_animation->GetBoneKey(newDurationIndex);
			OnBaseKeyChanged(*baseKey);
			m_curBaseDurationIndex=newDurationIndex;
		}
		//SetTween(*baseKey,*baseKey);
	}
	else if (forceSearch||
		(durationTime<baseKey->m_startDuration)||//回退
		(durationTime>baseKey->m_startDuration+baseKey->m_duration)//正向
		)
	{
		int durationCount=0;
		int newDurationIndex = GetDurationIndexByNormalizeTime(normalizeTime,m_curBaseDurationIndex,isbackward,durationCount);
		Skeleton2DTrasform_Bone* nextKey = 0;
		Skeleton2DTrasform_Bone* newKey = m_animation->GetBoneKey(newDurationIndex);
		if (!m_isLoop&&
			((isbackward&&newDurationIndex==0)
			||(!isbackward&&newDurationIndex==m_animation->m_keyCount-1)))
		{//停留在最后一帧
			nextKey=newKey;
		}
		else
		{
			int nextDurationIndex=isbackward?newDurationIndex-1:newDurationIndex+1;
			nextDurationIndex%=m_animation->m_keyCount;
			nextKey = m_animation->GetBoneKey(nextDurationIndex);
		}
		OnBaseKeyChanged(*newKey);
		m_curBaseDurationIndex=newDurationIndex;
		baseKey=newKey;
		SetTween(*baseKey,*nextKey);
		int ubc=0;
		ubc++;
	}

	float lerpT=(durationTime-baseKey->m_startDuration)/(float)baseKey->m_duration;
	if (m_isTweenEasing&&m_tweenEasing)
	{
		lerpT=getEaseValue(lerpT,m_tweenEasing);
	}
	TweenTransform(lerpT,m_from,m_tweenData,m_tweenTransformResult);
	UpdateFinalTransform();
}
void Skeleton2DBone::Update(float deltaDuration)
{
	if (0==m_animation)
	{
		return;
	}
	if (m_isInInsertDuration)
	{
		m_insertCurNormalizeTime+=fabs(deltaDuration)/m_durationInsert;
		if (m_insertCurNormalizeTime>1.0f)
		{
			m_isInInsertDuration=false;
			//动作过渡结束,需要重新计算当前duration
			float normalizeTime = (m_insertCurNormalizeTime-1.0f)*m_durationInsert/m_durationScaleTo;
			normalizeTime+=m_curNormalizeTime;
			UpdateTo(normalizeTime,deltaDuration<0.0f);
		}
		else
		{
			//m_insertCurNormalizeTime = _Skeleton2D_Sin_(m_insertCurNormalizeTime * HALF_PI);
			TweenTransform(m_insertCurNormalizeTime,m_from,m_tweenData,m_tweenTransformResult);
			UpdateFinalTransform();
		}
		return;
	}
	m_curNormalizeTime+=deltaDuration/m_durationScaleTo;
	bool isbackward = deltaDuration<0.0f?1:-1;
	UpdateTo(m_curNormalizeTime,deltaDuration<0.0f);
}
void Skeleton2DBone::TweenTransform(float s,const Skeleton2DTransform& from
									,const Skeleton2D_TweenData& tweenData
									,Skeleton2DTransform& result)
{
	result.x = from.x + s * tweenData.x;
	result.y = from.y + s * tweenData.y;
	result.scaleX = from.scaleX + s * tweenData.scaleX;
	result.scaleY = from.scaleY + s * tweenData.scaleY;
	result.skewX = from.skewX + s * tweenData.skewX;
	result.skewY = from.skewY + s * tweenData.skewY;
}
int Skeleton2DBone::GetDurationIndexByNormalizeTime(float normalizeTime,int searchStartIndex
													,bool isbackward,int& durationCount)
{
	int inc=isbackward?-1:1;
	durationCount=0;
	int i=0;
	int targetDuration=normalizeTime*m_duration;
	if (searchStartIndex<0)
	{
		searchStartIndex=0;
	}
	do 
	{
		int idx=(searchStartIndex+i*inc)%m_animation->m_keyCount;
		Skeleton2DTrasform_Bone* keyCheck = m_animation->GetBoneKey(idx);
		durationCount+=keyCheck->m_duration;
		if (targetDuration>=keyCheck->m_startDuration
			&&targetDuration<keyCheck->m_duration+keyCheck->m_startDuration)
		{//
			return idx;
		}
		i++;
	} while (i<m_animation->m_keyCount);
	return 0;
}
//!计算normalizeTime时间的插值结果
void Skeleton2DBone::CalcTween(float normalizeTime,bool isbackward,Skeleton2DTrasform_Bone& result)
{
	if (normalizeTime>1.0f)
	{
		if (m_isLoop)
		{
			ModNormalizeTime(normalizeTime);
		}
		else
		{
			normalizeTime=1.0f;
		}
	}
	float durationTime = normalizeTime*(float)m_duration;

	int durationCount=0;
	int newDurationIndex = GetDurationIndexByNormalizeTime(normalizeTime,0,isbackward,durationCount);
	durationTime-=durationCount;
	Skeleton2DTrasform_Bone* baseKey = m_animation->GetBoneKey(newDurationIndex);
	int nextDurationIndex=isbackward?newDurationIndex-1:newDurationIndex+1;
	nextDurationIndex%=m_animation->m_keyCount;
	Skeleton2DTrasform_Bone* nextKey = m_animation->GetBoneKey(nextDurationIndex);

	Skeleton2D_TweenData tweenData;
	tweenData.subtract(*baseKey,*nextKey);

	float lerpT=(durationTime-baseKey->m_startDuration)/(float)baseKey->m_duration;
	if (m_isTweenEasing&&m_tweenEasing)
	{
		lerpT=getEaseValue(lerpT,m_tweenEasing);
	}
	result=*baseKey;
	TweenTransform(lerpT,*baseKey,tweenData,result);
}
void Skeleton2DBone::UpdateFinalTransform(void)
{
	m_finalTransformResult.x = m_boneOrigin->x + m_controlPoint.x + m_tweenTransformResult.x;
	m_finalTransformResult.y = m_boneOrigin->y + m_controlPoint.y + m_tweenTransformResult.y;
	m_finalTransformResult.skewX = m_boneOrigin->skewX + m_controlPoint.skewX + m_tweenTransformResult.skewX;
	m_finalTransformResult.skewY = m_boneOrigin->skewY + m_controlPoint.skewY + m_tweenTransformResult.skewY;
	m_finalTransformResult.scaleX = m_controlPoint.scaleX + m_tweenTransformResult.scaleX;
	m_finalTransformResult.scaleY = m_controlPoint.scaleX + m_tweenTransformResult.scaleY;

	//m_boneOrigin->scaleX + node.scaleX + tweenNode.scaleX;
	//m_boneOrigin->scaleY + node.scaleY + tweenNode.scaleY;
	Skeleton2DTrasform_Bone& parentTransform = m_parentBone->m_finalTransformResult;

	//Note: this formula of transform is defined by Flash pro
	float cosX = _Skeleton2D_Cos_(m_finalTransformResult.skewX);
	float sinX = _Skeleton2D_Sin_(m_finalTransformResult.skewX);
	float cosY = _Skeleton2D_Cos_(m_finalTransformResult.skewY);
	float sinY = _Skeleton2D_Sin_(m_finalTransformResult.skewY);

	if (m_childBoneCount > 0 || (IsVisable()))
	{
		m_finalMatrix.a = m_finalTransformResult.scaleX * cosY;
		m_finalMatrix.b = m_finalTransformResult.scaleX * sinY;
		m_finalMatrix.c = -m_finalTransformResult.scaleY * sinX;
		m_finalMatrix.d = m_finalTransformResult.scaleY * cosX;
		m_finalMatrix.tx = m_finalTransformResult.x;
		m_finalMatrix.ty = m_finalTransformResult.y;
		if(m_parentBone)
		{
			m_finalMatrix.concat(m_parentBone->m_childMatrix);
		}
	}

	if (m_childBoneCount)
	{
		//no scale transform for children
		m_childMatrix.a = cosY;
		m_childMatrix.b = sinY;
		m_childMatrix.c = -sinX;
		m_childMatrix.d = cosX;
		m_childMatrix.tx = m_finalTransformResult.x;
		m_childMatrix.ty = m_finalTransformResult.y;
		if (m_parentBone)
		{
			m_childMatrix.concat(m_parentBone->m_childMatrix);
		}
	}
	//m_finalTransformResult.FromMatrix(m_finalMatrix);
}

//!设置补间数据
void Skeleton2DBone::SetTween(const Skeleton2DTransform& from,const Skeleton2DTrasform_Bone& to)
{
	m_from=from;
	m_tweenData.subtract(from,to);
}
void Skeleton2DBone::OnBaseKeyChanged(Skeleton2DTrasform_Bone& key)
{
	if (m_currentImageID != key.m_imgID)
	{//图片改变
		m_currentImageID=key.m_imgID;
	}
	if (m_from.z != key.z)
	{//Z Order 改变

	}
}
float Skeleton2DBone::getEaseValue(float value,float easing)
{
	if (easing > 1) 
	{
		value = 0.5 * (1 - _Skeleton2D_Cos_(value * M_PI ));
		easing -= 1;
	}
	else if (easing > 0) 
	{
		value = _Skeleton2D_Sin_(value * HALF_PI);
	}
	else
	{
		value = 1 - _Skeleton2D_Cos_(value * HALF_PI);
		easing = -easing;
	}
	return value * easing + (1 - easing);
}
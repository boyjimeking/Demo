#include "Skeleton2DResource.h"
#include "Skeleton2DXmlDef.h"
#include <algorithm>
#include "boost/algorithm/string.hpp"

TiXmlElement* getElementByAttribute(TiXmlElement* node,const char* childNodeName,const char* attribName,const char* value)
{
	for(TiXmlElement* nodeChild = node->FirstChildElement(childNodeName);nodeChild
		;nodeChild = nodeChild->NextSiblingElement(childNodeName))
	{
		const char* cmpValue = nodeChild->Attribute(attribName);
		if (cmpValue && boost::algorithm::iequals(value, cmpValue)) 
		{
			return nodeChild;
		}
	}
	return 0;
}

Skeleton2DResourceAvatar::Skeleton2DResourceAvatar(void)
	:m_frameRate(24.0f)
{

}
Skeleton2DResourceAvatar::~Skeleton2DResourceAvatar(void)
{
	for (size_t i=0;i<m_texResources.size();i++)
	{
		Skeleton2DResourceTexture* tex = m_texResources[i];
		delete tex;
	}
	m_texResources.clear();
}
void Skeleton2DResourceAvatar::LoadAll(TiXmlElement* rootNode)
{
	m_name = rootNode->Attribute(Skel2D::A_NAME);
	double frameRate = 24.0;
	if(rootNode->Attribute(Skel2D::A_FRAME_RATE,&frameRate))
	{
		m_frameRate=frameRate;
	}
	RString temp_name;
	std::map<RString,TiXmlElement*> aniNameMap;
	for(TiXmlElement* aniListNode = rootNode->FirstChildElement(Skel2D::ANIMATIONS);aniListNode
		;aniListNode = aniListNode->NextSiblingElement(Skel2D::ANIMATIONS)) 
	{
		for(TiXmlElement* node = aniListNode->FirstChildElement(Skel2D::ANIMATION);node
			;node = node->NextSiblingElement(Skel2D::ANIMATION)) 
		{
			temp_name = node->Attribute(Skel2D::A_NAME);
			aniNameMap[temp_name]=node;
		}
	}
	for(TiXmlElement* skelsNode = rootNode->FirstChildElement(Skel2D::ARMATURES);skelsNode
		;skelsNode = skelsNode->NextSiblingElement(Skel2D::ARMATURES)) 
	{
		for(TiXmlElement* node = skelsNode->FirstChildElement(Skel2D::ARMATURE);node
			;node = node->NextSiblingElement(Skel2D::ARMATURE)) 
		{
			Skeleton2DResource* skeleton = new Skeleton2DResource;
			temp_name = node->Attribute(Skel2D::A_NAME);
			skeleton->LoadSkeleton(node,aniNameMap[temp_name],this);
			m_skeletonList.push_back(skeleton);
		}
	}
}
int Skeleton2DResourceAvatar::AddImage(Skeleton2DResourceAvatar::Skeleton2DImage& image)
{
	image.m_id=m_images.size();
	m_images.push_back(image);
	return image.m_id;
}
Skeleton2DResourceTexture* Skeleton2DResourceAvatar::AddTextureResource(TiXmlElement* textureNode)
{
	Skeleton2DResourceTexture* tex = new Skeleton2DResourceTexture;
	tex->Load(textureNode);
	AttachTextureResource(tex);
	return tex;
}
void Skeleton2DResourceAvatar::AttachTextureResource(Skeleton2DResourceTexture* tex)
{
	RVector<Skeleton2DResourceTexture*>::T::iterator it = std::find(
		m_texResources.begin(),m_texResources.end(),tex);
	if (it == m_texResources.end())
	{
		m_texResources.push_back(tex);
	}
	for (size_t i=0;i<m_images.size();i++)
	{
		Skeleton2DImage& img = m_images[i];
		Skeleton2DResourceSubTexture* subTex = tex->LookupSubTexture(img.m_name);
		if (subTex)
		{
			img.m_subTexture=subTex;
		}
	}
}
Skeleton2DResource* Skeleton2DResourceAvatar::GetSkeleton(const RString& name)
{
	for (size_t i=0;i<m_skeletonList.size();i++)
	{
		Skeleton2DResource* skel = m_skeletonList[i];
		if (skel->GetName()==name)
		{
			return skel;
		}
	}
	return 0;
}
const RString& Skeleton2DResourceAvatar::GetImageByID(int id)
{
	if (id>=0&&id<m_images.size())
	{
		return m_images[id].m_name;
	}
	static RString nullName;
	return nullName;
}
const Skeleton2DResourceAvatar::Skeleton2DImage* Skeleton2DResourceAvatar::GetImageDataByID(int id)
{
	if (id>=0&&id<m_images.size())
	{
		return &m_images[id];
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
Skeleton2DResource::Skeleton2DResource(void)
{

}
Skeleton2DResource::~Skeleton2DResource(void)
{

}

struct Sort_SkelBone 
{
	TiXmlElement* node;
	RString m_name;
	Sort_SkelBone* m_parent;
	int		m_id;
	RVector<Sort_SkelBone*>::T	m_children;
	RVector<int>::T	m_images;
	Sort_SkelBone(void):node(0),m_parent(0),m_id(0){

	}
	void SetID(int& id){
		m_id=id;
		id++;
		for (size_t i=0;i<m_children.size();i++)
		{
			m_children[i]->SetID(id);
		}
	}
};
#define _xml_read_(node,attrib,vTemp,vResult) if(node->Attribute(attrib,&vTemp)){vResult=vTemp;}

void parseMovementBoneData(TiXmlElement* movementBoneXML
						   ,TiXmlElement* parentXML
						   ,const Skeleton2DBoneResource& boneOrigin
						   ,Skeleton2DResource* skeleton
						   ,Skeleton2DBone_Animation& boneAni
						   ,Sort_SkelBone* boneSort)
{
	int vInt=0;
	double vDouble=0.0;
	_xml_read_(movementBoneXML,Skel2D::A_MOVEMENT_SCALE,vDouble,boneAni.m_scale);
	_xml_read_(movementBoneXML,Skel2D::A_MOVEMENT_DELAY,vDouble,boneAni.m_delay);
	boneAni.m_keyCount=0;
	boneAni.m_startKeyIndex=skeleton->GetKeyBufferSize();
	int parentTotalDuration = 0;
	int currentDuration = 0;
	int totalDuration = 0;
	int iParentFrameCount=0;
	TiXmlElement* parentFrameXML=0;
	//���Ҹ��������ݵı�������
	int i=0;
	bool isEndVisitParent=false;
	for(TiXmlElement* node = movementBoneXML->FirstChildElement(Skel2D::FRAME);node
		;node = node->NextSiblingElement(Skel2D::FRAME))
	{
		if(parentXML)
		{
			if (0==i)
			{
				parentFrameXML = parentXML->FirstChildElement(Skel2D::FRAME);
			}
			while(!isEndVisitParent && (parentFrameXML?(totalDuration < parentTotalDuration || totalDuration >= parentTotalDuration + currentDuration):true))
			{
				if (0!=i)
				{
					parentFrameXML = parentFrameXML->NextSiblingElement(Skel2D::FRAME);
				}
				parentTotalDuration += currentDuration;
				_xml_read_(parentFrameXML,Skel2D::A_DURATION,vInt,currentDuration);
				i++;
				isEndVisitParent=parentFrameXML->NextSiblingElement(Skel2D::FRAME)?false:true;
			}
		}

		Skeleton2DTrasform_Bone boneTransform;
		boneTransform.ReadFromXml(node);
		_xml_read_(node,Skel2D::A_DURATION,vInt,boneTransform.m_duration);
		_xml_read_(node,Skel2D::A_TWEEN_EASING,vDouble,boneTransform.m_tweenEasing);
		_xml_read_(node,Skel2D::A_TWEEN_ROTATE,vDouble,boneTransform.tweenRotate);
		_xml_read_(node,Skel2D::A_DISPLAY_INDEX,vInt,boneTransform.m_imgID);
		totalDuration += boneTransform.m_duration;
		if (boneSort&&boneTransform.m_imgID<boneSort->m_images.size())
		{
			boneTransform.m_imgID=boneSort->m_images[boneTransform.m_imgID];
		}
		else
		{
			_Skeleton2D_Assert_(false,"parseMovementBoneData missed image id:%d",boneTransform.m_imgID);
		}
		//���Ŷ������������¼�,����,��ʱ��֧��
		//_xml_read_int(node,Skel2D::A_MOVEMENT,vInt,boneTransform.m_duration);
		//boneTransform.event = String(node->Attribute(Skel2D::A_EVENT));
		//boneTransform.sound = String(node->Attribute(Skel2D::A_SOUND));
		//boneTransform.soundEffect = String(node->Attribute(Skel2D::A_SOUND_EFFECT));
		Skeleton2DTrasform_Bone helpNode;
		if(parentFrameXML){
			helpNode.ReadFromXml(parentFrameXML);
			boneTransform.transfromPointWithParent(helpNode);
		}

		boneTransform.x -=	boneOrigin.x;
		boneTransform.y -=	boneOrigin.y;
		boneTransform.skewX -=	boneOrigin.skewX;
		boneTransform.skewY -=boneOrigin.skewY;
		_xml_read_(node,Skel2D::A_SCALE_X,vDouble,boneTransform.scaleX);
		_xml_read_(node,Skel2D::A_SCALE_Y,vDouble,boneTransform.scaleY);
		//boneTransform.scaleX -= boneOrigin.scaleX;
		//boneTransform.scaleY -= boneOrigin.scaleY;
		skeleton->AddBoneKey(boneTransform);
		boneAni.m_keyCount++;
	}
}

void Skeleton2DResource::LoadSkeleton(TiXmlElement* skeletonXmlNode
						,TiXmlElement* aniListNode,Skeleton2DResourceAvatar* avatar)
{
	m_name = skeletonXmlNode->Attribute(Skel2D::A_NAME);
	//����һ���������ֵ�ID��ת�������.m_boneListֱ�Ӳ���
	//��ȡ��������ʱ,ֱ�ӻ�ù���IDд�뵽Skeleton2DAnimation::m_boneList
	std::map<RString,Sort_SkelBone*>	BoneName2ID;

	RString temp_name;
	for(TiXmlElement* node = skeletonXmlNode->FirstChildElement(Skel2D::BONE);node
		;node = node->NextSiblingElement(Skel2D::BONE))
	{
		Sort_SkelBone* bone = new Sort_SkelBone;
		bone->node=node;
		temp_name = node->Attribute(Skel2D::A_NAME);
		bone->m_name=temp_name;
		BoneName2ID[temp_name]=bone;
	}
	RVector<Sort_SkelBone*>::T justRootBone;
	for (std::map<RString,Sort_SkelBone*>::iterator it = BoneName2ID.begin();
		it!=BoneName2ID.end();++it)
	{
		Sort_SkelBone* bone = it->second;
		const char* parentName=bone->node->Attribute(Skel2D::A_PARENT);
		if (!parentName)
		{
			justRootBone.push_back(bone);
			continue;
		}
		temp_name=parentName;
		bone->m_parent=BoneName2ID[temp_name];
		bone->m_parent->m_children.push_back(bone);
	}
	//////////////////////////////////////////////////////////////////////////
	//����ID,���Ҷ�ȡ����
	int id=0;
	for (size_t i=0;i<justRootBone.size();i++)
	{
		justRootBone[i]->SetID(id);
	}
	m_boneList.resize(BoneName2ID.size());

	Skeleton2DTransform helpNode;
	for (std::map<RString,Sort_SkelBone*>::iterator it = BoneName2ID.begin();
		it!=BoneName2ID.end();++it)
	{
		Sort_SkelBone* sortInfo = it->second;
		const RString& boneName = it->first;
		Skeleton2DBoneResource& bone=m_boneList[sortInfo->m_id];
		TiXmlElement* node = sortInfo->node;
		bone.m_boneID=sortInfo->m_id;
		bone.m_name = boneName;
		bone.ReadFromXml(node);
		if(sortInfo->m_parent)
		{
			bone.m_parentBoneID=sortInfo->m_parent->m_id;
			helpNode.ReadFromXml(sortInfo->m_parent->node);
			bone.transfromPointWithParent(helpNode);
		}
		//��ȡͼƬ
		for(TiXmlElement* nodeImage = node->FirstChildElement(Skel2D::DISPLAY);nodeImage
			;nodeImage = nodeImage->NextSiblingElement(Skel2D::DISPLAY))
		{
			Skeleton2DResourceAvatar::Skeleton2DImage image;
			image.m_name = nodeImage->Attribute(Skel2D::A_NAME);
			const char* isSkeletonStr=nodeImage->Attribute(Skel2D::A_IS_ARMATURE);
			if (isSkeletonStr&&isSkeletonStr[0]!='0')
			{
				image.m_isSkeleton=true;
			}
			bone.m_defaultImageID=avatar->AddImage(image);
			sortInfo->m_images.push_back(bone.m_defaultImageID);
		}
	}
	int vInt=0;
	double vDouble=0.0;
	for(TiXmlElement* node = aniListNode->FirstChildElement(Skel2D::MOVEMENT);node
		;node = node->NextSiblingElement(Skel2D::MOVEMENT))
	{//move
		Skeleton2DAnimation* ani = new Skeleton2DAnimation;
		ani->m_aniName = node->Attribute(Skel2D::A_NAME);
		_xml_read_(node,Skel2D::A_DURATION,vInt,ani->m_duration);
		_xml_read_(node,Skel2D::A_DURATION_TO,vInt,ani->m_durationInsertWhenPlay);
		_xml_read_(node,Skel2D::A_DURATION_TWEEN,vInt,ani->m_durationScaleTo);
		_xml_read_(node,Skel2D::A_LOOP,vInt,ani->m_isLoop);
		_xml_read_(node,Skel2D::A_TWEEN_EASING,vDouble,ani->m_tweenEasing);
		
		ani->m_boneList.resize(m_boneList.size());
		for(TiXmlElement* nodeBoneFrameList = node->FirstChildElement(Skel2D::BONE)
			;nodeBoneFrameList
			;nodeBoneFrameList = nodeBoneFrameList->NextSiblingElement(Skel2D::BONE))
		{//������֡�б�
			temp_name = nodeBoneFrameList->Attribute(Skel2D::A_NAME);
			Sort_SkelBone* boneSort = BoneName2ID[temp_name];
			Skeleton2DBone_Animation* boneAni = ani->GetBoneAnimation(boneSort->m_id);
			Skeleton2DBoneResource*	boneData = GetBone(boneSort->m_id);
			TiXmlElement* boneParentXML = 0;
			if (boneSort->m_parent)
			{
				boneParentXML = getElementByAttribute(node,Skel2D::BONE,Skel2D::A_NAME, boneSort->m_parent->m_name.c_str());
				_Skeleton2D_Assert_(boneParentXML,"ParentXml Is not find [%s],parent:[%s]",temp_name.c_str(),boneSort->m_parent->m_name.c_str());
			}
			
			boneAni->m_boneName=temp_name;
			boneAni->m_boneID=boneSort->m_id;
			parseMovementBoneData(nodeBoneFrameList, boneParentXML, *boneData
				, this, *boneAni,boneSort);
		}
		/*�¼��ؼ�֡,����
		var movementFrameXMLList:XMLList = movementXML.elements(Skel2D::FRAME);
		var length:uint = movementFrameXMLList.length();
		for(var i:int = 0;i < length;i ++)
		{
			var movementFrameXML:XML = movementFrameXMLList[i];
			var movementFrameData:MovementFrameData = movementData._movementFrameList.length > i?movementData._movementFrameList[i]:null;
			movementFrameData = parseMovementFrameData(movementFrameXML, movementFrameData);
			movementData._movementFrameList[i] = movementFrameData;
		}
		*/
		m_animationList.push_back(ani);
	}
	for (size_t i=0;i<m_animationList.size();i++)
	{
		Skeleton2DAnimation* ani = m_animationList[i];
		for (size_t k=0;k<ani->m_boneList.size();k++)
		{
			Skeleton2DBone_Animation& boneAni=ani->m_boneList[k];
			boneAni.m_keyList=GetKeyArray(boneAni.m_startKeyIndex);
			boneAni.UpdateDurationTotal();
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//ɾ����ʱ����
	for (std::map<RString,Sort_SkelBone*>::iterator it = BoneName2ID.begin();
		it!=BoneName2ID.end();++it)
	{
		Sort_SkelBone* bone = it->second;
		delete bone;
	}
}
//////////////////////////////////////////////////////////////////////////
void Skeleton2DTransform::ReadFromXml(TiXmlElement* node,bool readScale){
	double v=0.0;
	if(node->Attribute(Skel2D::A_X,&v)){
		x = v;
	}
	if(node->Attribute(Skel2D::A_Y,&v)){
		y = v;
	}
	if(node->Attribute(Skel2D::A_SKEW_X,&v)) {
		skewX=v* Skel2D::ANGLE_TO_RADIAN;
	}
	if(node->Attribute(Skel2D::A_SKEW_Y,&v)) {
		skewY = v* Skel2D::ANGLE_TO_RADIAN;
	}
	if (readScale)
	{
		_xml_read_(node,Skel2D::A_SCALE_X,v,scaleX);
		_xml_read_(node,Skel2D::A_SCALE_Y,v,scaleY);
	}
	z=0;
	node->Attribute(Skel2D::A_Z,&z);
}
//////////////////////////////////////////////////////////////////////////
Skeleton2DResourceSubTexture::Skeleton2DResourceSubTexture(void)
{

}
void Skeleton2DResourceSubTexture::Load(TiXmlElement* xml)
{
	int vInt=0;
	double vDouble=0;
	Skeleton2DResourceSubTexture& subTextureData=*this;
	subTextureData.name = xml->Attribute(Skel2D::A_NAME);
	_xml_read_(xml,Skel2D::A_X,vInt,subTextureData.x);
	_xml_read_(xml,Skel2D::A_Y,vInt,subTextureData.y);
	_xml_read_(xml,Skel2D::A_WIDTH,vInt,subTextureData.width);
	_xml_read_(xml,Skel2D::A_HEIGHT,vInt,subTextureData.height);
	_xml_read_(xml,Skel2D::A_PIVOT_X,vInt,subTextureData.pivotX);
	_xml_read_(xml,Skel2D::A_PIVOT_Y,vInt,subTextureData.pivotY);
}
//////////////////////////////////////////////////////////////////////////
Skeleton2DResourceTexture::Skeleton2DResourceTexture(void)
{

}
void Skeleton2DResourceTexture::Load(TiXmlElement* xml)
{
	int vInt=0;
	m_name = xml->Attribute(Skel2D::A_NAME);
	_xml_read_(xml,Skel2D::A_WIDTH,vInt,m_width);
	_xml_read_(xml,Skel2D::A_HEIGHT,vInt,m_height);
	for(TiXmlElement* nodeImage = xml->FirstChildElement(Skel2D::SUB_TEXTURE);nodeImage
		;nodeImage = nodeImage->NextSiblingElement(Skel2D::SUB_TEXTURE))
	{
		Skeleton2DResourceSubTexture subTex;
		subTex.Load(nodeImage);
		m_subTexs[subTex.name]=subTex;
	}
}
Skeleton2DResourceSubTexture* Skeleton2DResourceTexture::LookupSubTexture(const RString& name)
{
	Name2SubTexture::iterator it = m_subTexs.find(name);
	if (it != m_subTexs.end())
	{
		return &it->second;
	}
	return 0;
}
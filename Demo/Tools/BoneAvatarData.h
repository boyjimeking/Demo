//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2013-1-4
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef BoneAvatarData_h__
#define BoneAvatarData_h__

#include <string>
#include <map>

namespace Tools
{
	class BoneAnimationGroup;
	class BoneAvatarData
	{
	public:
		typedef std::map<std::string, BoneAnimationGroup*> AnimationTable;

		BoneAvatarData(void);
		virtual ~BoneAvatarData(void);

		void Read(unsigned char *buff, unsigned int size);
		unsigned int Write(unsigned char *buff, unsigned int size);
		void Clear(void);

		BoneAnimationGroup* Lookup(const std::string &type) const;
		//缩放比率
		const float& GetTransScale() const { return m_transScale; }
		void SetTransScale(const float &val) { m_transScale = val; }

		//骨骼动画描述文件
		const std::string& GetSkelFilename(void) const { return m_skelFilename; }
		void SetSkelFilename(const std::string& val) { m_skelFilename = val; }

		//资源描述文件
		const std::string& GetTexFilenameDesc(void) const { return m_texFilenameDesc; }
		void SetTexFilenameDesc(const std::string& val) { m_texFilenameDesc = val; }

		//资源图片文件
		const std::string& GetTexFilename(void) const { return m_texFilename; }
		void SetTexFilename(const std::string& val) { m_texFilename = val; }

		//骨骼名称
		const std::string& GetUseSkeletonName(void) const { return m_useSkeletonName; }
		void SetUseSkeletonName(const std::string& val) { m_useSkeletonName = val; }
	protected:
		//骨骼动画描述文件
		std::string m_skelFilename;
		//资源描述文件
		std::string m_texFilenameDesc;
		//资源图片文件
		std::string m_texFilename;
		//骨骼名称
		std::string m_useSkeletonName;
		//动画列表
		AnimationTable m_animationTable;
		//缩放比率
		float m_transScale;
	};
}

#endif // BoneAvatarData_h__

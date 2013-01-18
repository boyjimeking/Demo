//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Tools
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AvatarData_h__
#define AvatarData_h__

#include <map>
#include <string>

namespace Tools
{
	class AnimationGroup;
	class AvatarData
	{
	public:
		typedef std::map<std::string, AnimationGroup*> AnimationTable;
		virtual ~AvatarData(void);

		void Read(unsigned char *buff, unsigned int size);
		unsigned int Write(unsigned char *buff, unsigned int size);
		void Clear(void);

		const char* GetPList(void) const { return m_plist.c_str(); }
		const char* GetFrameList(void) const { return m_frameList.c_str(); }
		AnimationGroup* Lookup(const char *type) const;
		const AnimationTable& GetAnimationTable(void) const { return m_animationTable; }
		const float& GetTransScale() const { return m_transScale; }
		void SetTransScale(const float &val) { m_transScale = val; }

		virtual void Retain(void);
		virtual void Release(void);
	protected:
		AvatarData(void);
	protected:
		//plist
		std::string m_plist;
		std::string m_frameList;
		//动画列表
		AnimationTable m_animationTable;
		//缩放比率
		float m_transScale;

		int m_ref;
	private:
		enum ENVersion
		{
			enBase,
			enFrameList,
		};
		unsigned int m_version;
	};
}

#endif // AvatarData_h__

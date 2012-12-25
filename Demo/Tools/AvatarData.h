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

namespace Tools
{
	class AnimationGroup;
	class AvatarData
	{
	public:
		typedef std::map<int, AnimationGroup*> AnimationTable;

		AvatarData(void);
		virtual ~AvatarData(void);

		void Read(unsigned char *buff, unsigned int size);
		unsigned int Write(unsigned char *buff, unsigned int size);
		void Clear(void);

		const char* GetPList(void) const { return m_plist.c_str(); }
		AnimationGroup* Lookup(int animationID) const;
		const AnimationTable& GetAnimationTable(void) const { return m_animationTable; }
		const float& GetTransScale() const { return m_transScale; }
		void SetTransScale(const float &val) { m_transScale = val; }
	protected:
		//plist
		std::string m_plist;
		//动画列表
		AnimationTable m_animationTable;
		//缩放比率
		float m_transScale;
	private:
	};
}

#endif // AvatarData_h__

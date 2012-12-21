//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\GameFramework\Tools
//	created:	2012-12-21
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef AvatarData_h__
#define AvatarData_h__

#include <vector>
#include <string>

namespace Tools
{
	class AnimationData;
	class AvatarData
	{
	public:
		AvatarData(void);
		virtual ~AvatarData(void);

		void Read(unsigned char *buff, unsigned int size);
		unsigned int Write(unsigned char *buff, unsigned int size);

		AnimationData* LookupAnimation(int id);
	protected:
		void Clear(void);
	protected:
		std::string m_plist;
		//动画列表
		typedef std::vector<AnimationData*> AnimationTable;
		AnimationTable m_animationTable;
	private:

	};
}

#endif // AvatarData_h__

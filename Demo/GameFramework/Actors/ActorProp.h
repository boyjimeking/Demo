//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/ActorManager/ActorProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorProp_h__
#define ActorProp_h__

#include "../Base/INotifier.h"

namespace Game
{
	class ActorEntity;
	/*
	 *	角色属性类，用于记录并控制角色的各项属性
	 */
	class ActorProp
		:INotifier
	{
	public:
		ActorProp(void);
		virtual ~ActorProp(void);

		ActorEntity* Create(void);
		void Release(void);
	protected:
	private:
	};
}

#endif // ActorProp_h__

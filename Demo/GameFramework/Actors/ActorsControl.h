//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	E:/GitCode/SimpleGame/SourceCode/GameFramework/ActorManager/ActorsControl.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorsControl_h__
#define ActorsControl_h__

#include "../Base/INotifier.h"
#include <map>

namespace Game
{
	class ActorProp;
	/*
	 *	角色主控类，控制全部角色的逻辑处理及角色层
	 */
	class ActorsControl
		:public INotifier
	{
	public:
		ActorsControl(void);
		virtual ~ActorsControl(void);

		bool CreateActor(int actorID);
		void ReleaseActor(int actorID);
		void ClearActor(void);
	protected:
	private:
		typedef std::map<int, ActorProp*> ActorMap;
		ActorMap m_actorMap;
	};
}

#endif // ActorsControl_h__

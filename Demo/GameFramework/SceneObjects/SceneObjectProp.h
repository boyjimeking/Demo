//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/SceneObjectManager/SceneObjectProp.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef SceneObjectProp_h__
#define SceneObjectProp_h__

#include "../Base/INotifier.h"
#include "cocoa/CCGeometry.h"
#include <string>

namespace Tools
{
	struct ObjectInfo;
}

namespace Game
{
	class SceneObjectEntity;
	/*
	 *	建筑属性，用于记录建筑的各项信息及控制建筑的改变
	 */
	class SceneObjectProp
		:public INotifier
	{
	public:
		_Decl_Notifier(SceneObjectProp);
		SceneObjectProp(void);
		virtual ~SceneObjectProp(void);
		void Init(Tools::ObjectInfo *objInfo);
		void Remove(void);
		
		int GetID(void) const { return m_id; }
		const cocos2d::CCPoint& GetPosition(void) const { return m_position; }
		const cocos2d::CCSize& GetSize(void) const { return m_size; }

	protected:
	private:
		cocos2d::CCPoint m_position;
		cocos2d::CCSize m_size;
		int m_id;
	};
}

#endif // SceneObjectProp_h__

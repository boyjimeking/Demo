//////////////////////////////////////////////////////////////////////////
//
//	文件名: 	/SourceCode/GameFramework/UI/UIControl.h
//	创建日期:	2012年11月26日
//	创建者:		张明震
//
//////////////////////////////////////////////////////////////////////////
#ifndef UIControl_h__
#define UIControl_h__

#include "../Base/INotifier.h"

namespace GUI
{
	class UIControl
		:public INotifier
	{
	public:
		UIControl(void);
		virtual ~UIControl(void);
	protected:
	private:
	};
}

#endif // UIControl_h__

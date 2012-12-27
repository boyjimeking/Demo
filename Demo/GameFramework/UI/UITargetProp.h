//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/UI
//	created:	2012-12-27
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef UITargetProp_h__
#define UITargetProp_h__

#include "UIProperty.h"

namespace GUI
{
	class UITargetProp
		:public UIProperty
	{
	public:
		UITargetProp(void);
		virtual ~UITargetProp(void);

		virtual void Init( const std::string &windowName );

		virtual void OnNotifyChange( INotifier *notify, const INotifyEvent *event );

	protected:
		
	private:

	};
}

#endif // UITargetProp_h__

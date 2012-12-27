//////////////////////////////////////////////////////////////////////////
//
//	file path:	GameFramework/Base
//	created:	2012-12-27
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef INotifierType_h__
#define INotifierType_h__

#define _Decl_NotifierType(className) en##className
#define GetNotifierType(className) ENNotifierType::en##className

struct ENNotifierType
{
	enum Decl
	{
		enNone,
		_Decl_NotifierType(ActorProp),
		_Decl_NotifierType(ActorsControl),
		_Decl_NotifierType(Camera),
		_Decl_NotifierType(SceneObjectProp),
		_Decl_NotifierType(SceneObjectsControl),
		_Decl_NotifierType(GridProp),
		_Decl_NotifierType(TerrainProp),
		_Decl_NotifierType(UIProperty),
		_Decl_NotifierType(UIControl),

		Count,
	};
};

#endif // INotifierType_h__

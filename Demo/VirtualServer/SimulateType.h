//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef SimulateType_h__
#define SimulateType_h__

#define _Decl_SimulateType(className) en##className
#define _Get_SimulateType(className) ENSimulateType::en##className

struct ENSimulateType
{
	enum Decl
	{
		enError,
		_Decl_SimulateType(IActor),
		_Decl_SimulateType(Player),
		_Decl_SimulateType(NPC),
	};
};

#endif // SimulateType_h__

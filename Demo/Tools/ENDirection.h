//////////////////////////////////////////////////////////////////////////
//
//	file path:	E:\Codes\Demo\Demo\Tools
//	created:	2012-12-24
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef ENDirection_h__
#define ENDirection_h__

namespace Tools
{
	struct ENDirection 
	{
		enum Decl
		{
			enError = -1,
			enEast,			//→	0
			enNorthEast,	//↗	π/4
			enNorth,		//↑	π/2
			enNorthWest,	//↖	3π/4
			enWest,			//←	π
			enSouthWest,	//↙	-3π/4
			enSouth,		//↓	-π/2
			enSouthEast,	//↘	-π/4

			Count,
		};
	};
}

#endif // ENDirection_h__

//
//  GlobalDef.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-6.
//
//

#ifndef Demo_GlobalDef_h
#define Demo_GlobalDef_h

struct ENActorType
{
	enum Decl
	{
		enNone,
		enMain,
		enMonster,
		enNpc,
	};
};

struct ENSceneObjectType
{
	enum Decl
	{
		enNone,
	};
};

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
#endif

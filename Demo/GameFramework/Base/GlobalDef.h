//
//  GlobalDef.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-6.
//
//

#ifndef Demo_GlobalDef_h
#define Demo_GlobalDef_h

#include "../../Tools/ENDirection.h"

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

typedef Tools::ENDirection ENDirection;
typedef Tools::ENAnimation ENAnimation;

struct ENEquipType 
{
	enum Decl
	{
		enError = -1,
		enWeapon,

		Count,
	};
};
#endif

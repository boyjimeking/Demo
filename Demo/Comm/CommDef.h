//
//  CommDef.h
//  Demo
//
//  Created by xiangyu on 13-1-6.
//
//

#ifndef Demo_CommDef_h
#define Demo_CommDef_h

#define INVALID_ID      0
#define MSG_PTR_CVT(p, class, pMsg) class* p = (class *)pMsg

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;
typedef unsigned long long u64;

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

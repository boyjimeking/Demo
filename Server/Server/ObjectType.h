//
//  ObjectType.h
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef Server_ObjectType_h
#define Server_ObjectType_h

#define _Decl_ObjectType(className) en##className
#define _Get_ObjectType(className) ENObjectType::en##className

enum ENObjectType
{
	enError,
	_Decl_ObjectType(CPlayer),
	_Decl_ObjectType(CNpc),
    _Decl_ObjectType(MaxSize)
};


#endif

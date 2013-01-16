//
//  ILayer.h
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__ILayer__
#define __Server__ILayer__

#include <map>
#include "../../Demo/Comm/NetMessage.h"
#include "Tools.h"
#include "ObjectType.h"

class IObject;
class ILayer{
public:
    ILayer(void);
    virtual ~ILayer(void);
    
    virtual bool Init(void);
    
    virtual void PushObject(IObject* obj);
    virtual void PopObject(IObject* obj);
    IObject* LookupObject(u32 id);
    
    virtual void Send(NetMessage *message) const;
    virtual void Tick(u32 dt);
    virtual void Process(NetMessage *pMsg);

    u32 GeneratorId(ENObjectType type);
protected:
    
protected:
    typedef std::map<int, IObject*> TObjectMap;
    TObjectMap m_objMap;
private:
    u32 m_generator[ENObjectType::enMaxSize];
    u32 m_nClassType[ENObjectType::enMaxSize];
    
};

#endif /* defined(__Server__ILayer__) */

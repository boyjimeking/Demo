//
//  ISimulateLayer.h
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__ISimulateLayer__
#define __Server__ISimulateLayer__

#include <map>
#include "../../Demo/Comm/NetMessage.h"
#include "Tools.h"
#include "ObjectType.h"

class ISimulateObject;
class ISimulateLayer{
public:
    ISimulateLayer(void);
    virtual ~ISimulateLayer(void);
    
    virtual bool Init(void);
    
    virtual void PushObject(ISimulateObject* obj);
    virtual void PopObject(ISimulateObject* obj);
    ISimulateObject* LookupObject(u32 id);
    
    virtual void Send(NetMessage *message) const;
    virtual void Tick(u32 dt);
    virtual void Process(NetMessage *pMsg);

    u32 GeneratorId(ENObjectType type);
protected:
    
protected:
    typedef std::map<int, ISimulateObject*> TObjectMap;
    TObjectMap m_objMap;
private:
    u32 m_generator[ENObjectType::enMaxSize];
    u32 m_nClassType[ENObjectType::enMaxSize];
    
};

#endif /* defined(__Server__ISimulateLayer__) */

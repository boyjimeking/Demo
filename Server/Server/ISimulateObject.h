//
//  ISimulateObject.h
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__ISimulateObject__
#define __Server__ISimulateObject__

#include "ObjectType.h"
#include "../../Demo/Comm/NetMessage.h"
#include "Tools.h"

class ISimulateLayer;
class ISimulateObject{
public:
    virtual ENObjectType GetType() const { return ENObjectType::enError; }
    virtual bool IsKindof(ENObjectType type) const { return false; }
    
    ISimulateObject(void);
    virtual ~ISimulateObject(void);
    
    virtual void OnPush(ISimulateLayer *layer);
    virtual void OnPop(ISimulateLayer *layer);
    
    virtual void Process(NetMessage *message);
    virtual void Send(NetMessage *message) const;
    virtual void Tick(u32 dt);
    
    u32 GetID(void) const { return m_nId; }
    void SetID(u32 val) { m_nId = val; }
    
    ISimulateLayer* GetLayer(void) const { return m_pLayer; }
protected:

    
private:
    u32 m_nId;
    ISimulateLayer *m_pLayer;
};

#endif /* defined(__Server__ISimulateObject__) */

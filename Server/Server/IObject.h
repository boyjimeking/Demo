//
//  IObject.h
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__IObject__
#define __Server__IObject__

#include "ObjectType.h"
#include "../../Demo/Comm/NetMessage.h"
#include "Tools.h"

class ILayer;
class IObject{
public:
    virtual ENObjectType GetType() const { return ENObjectType::enError; }
    virtual bool IsKindof(ENObjectType type) const { return false; }
    
    IObject(void);
    virtual ~IObject(void);
    
    virtual void OnPush(ILayer *layer);
    virtual void OnPop(ILayer *layer);
    
    virtual void Process(NetMessage *message);
    virtual void Send(NetMessage *message) const;
    virtual void Tick(u32 dt);
    
    u32 GetID(void) const { return m_nId; }
    void SetID(u32 val) { m_nId = val; }
    
    ILayer* GetLayer(void) const { return m_pLayer; }
protected:

    
private:
    u32 m_nId;
    ILayer *m_pLayer;
};

#endif /* defined(__Server__IObject__) */

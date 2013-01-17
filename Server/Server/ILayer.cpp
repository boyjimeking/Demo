//
//  ILayer.cpp
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include <assert.h>
#include "ILayer.h"
#include "IObject.h"


ILayer::ILayer(void)
{
    assert(ENObjectType::enMaxSize < 16);
    memset(m_generator, 0, sizeof(m_generator));
    for(int i = 0; i < ENObjectType::enMaxSize; ++i)
    {
        m_nClassType[i] = 1<<(i+16);
    }
    
}

ILayer::~ILayer(void)
{
    
}

void ILayer::PushObject(IObject* obj)
{
    if (m_objMap.end() != m_objMap.find(obj->GetID()))
    {
        return;
    }
    obj->OnPush(this);
    m_objMap[obj->GetID()] = obj;
}

void ILayer::PopObject(IObject* obj)
{
    TObjectMap::iterator it = m_objMap.find(obj->GetID());
    if (m_objMap.end() != it)
    {
        assert(it->second);
        delete it->second;
        m_objMap.erase(it);
    }
}

IObject* ILayer::LookupObject( u32 id )
{
    TObjectMap::iterator it = m_objMap.find(id);
    if(it == m_objMap.end())
    {
        return  NULL;
    }
    assert(it->second);
    return it->second;
}

void ILayer::Process( NetMessage *message )
{
    switch (message->GetType())
    {
		default:
			break;
    }
}

void ILayer::Send( NetMessage *message ) const
{
    
}

void ILayer::Tick( u32 dt )
{
    for (TObjectMap::iterator it = m_objMap.begin(); m_objMap.end() != it; ++it)
    {
        assert(it->second);
        it->second->Tick(dt);
    }
}

bool ILayer::Init( void )
{
    return true;
}


u32 ILayer::GeneratorId(ENObjectType type)
{
    assert(type > ENObjectType::enError && type < ENObjectType::enMaxSize);
    return ++m_generator[type-1] + m_nClassType[type-1];
}
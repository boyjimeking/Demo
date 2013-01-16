//
//  IObject.cpp
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "IObject.h"
#include "ILayer.h"

IObject::IObject(void):
m_nId(0),
m_pLayer(NULL)
{
}

IObject::~IObject(void)
{
    
    
}

void IObject::OnPush( ILayer *layer )
{
    m_pLayer = layer;
}

void IObject::OnPop( ILayer *layer )
{
    m_pLayer = NULL;
}

void IObject::Process( NetMessage *message )
{

}

void IObject::Send( NetMessage *message ) const
{
    GetLayer()->Send(message);
}

void IObject::Tick( u32 dt )
{
    
}

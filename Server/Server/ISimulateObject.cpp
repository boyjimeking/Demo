//
//  ISimulateObject.cpp
//  Server
//
//  Created by xiangyu on 13-1-15.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#include "ISimulateObject.h"
#include "ISimulateLayer.h"

ISimulateObject::ISimulateObject(void):
m_nId(0),
m_pLayer(NULL)
{
}

ISimulateObject::~ISimulateObject(void)
{
    
    
}

void ISimulateObject::OnPush( ISimulateLayer *layer )
{
    m_pLayer = layer;
}

void ISimulateObject::OnPop( ISimulateLayer *layer )
{
    m_pLayer = NULL;
}

void ISimulateObject::Process( NetMessage *message )
{

}

void ISimulateObject::Send( NetMessage *message ) const
{
    GetLayer()->Send(message);
}

void ISimulateObject::Tick( u32 dt )
{
    
}

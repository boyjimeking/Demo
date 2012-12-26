#include "ISimulateObject.h"
#include "CSProtocol/CSMessageDef.h"
#include "ISimulateLayer.h"

namespace Server
{
	ISimulateObject::ISimulateObject(void)
		:m_id(0)
		,m_simulate(NULL)
	{

	}

	ISimulateObject::~ISimulateObject(void)
	{

	}

	void ISimulateObject::OnPush( ISimulateLayer *layer )
	{
		m_simulate = layer;
	}

	void ISimulateObject::OnPop( ISimulateLayer *layer )
	{
		
	}

	void ISimulateObject::Process( IMessage *message )
	{
		switch (message->GetType())
		{
		default:
			break;
		}
	}

	void ISimulateObject::Send( IMessage *message ) const
	{
		GetSimulate()->Send(message);
	}

	void ISimulateObject::Tick( float dt )
	{

	}

}
#include "ISimulateLayer.h"
#include "../CSProtocol/CSMessageDef.h"

namespace Server
{
	ISimulateLayer::ISimulateLayer(void)
	{

	}

	ISimulateLayer::~ISimulateLayer(void)
	{

	}

	void ISimulateLayer::PushObject(ISimulateObject::Ptr obj)
	{
		if (m_objList.end() != std::find(m_objList.begin(), m_objList.end(), obj))
		{
			return;
		}
		obj->SetID(m_objList.size() + 1);
		obj->OnPush(this);
		m_objList.push_back(obj);
	}

	void ISimulateLayer::PopObject(ISimulateObject::Ptr obj)
	{
		SimulateObjList::iterator it = std::find(m_objList.begin(), m_objList.end(), obj);
		if (m_objList.end() != it)
		{
			m_objList.erase(it);
			obj->OnPop(this);
		}
	}

	ISimulateObject::Ptr ISimulateLayer::LookupObject( int id )
	{
		for (SimulateObjList::iterator it = m_objList.begin(); m_objList.end() != it; ++it)
		{
			if ((*it)->GetID() == id)
			{
				return *it;
			}
		}
		return ISimulateObject::Ptr();
	}

	void ISimulateLayer::Process( IMessage *message )
	{
		switch (message->GetType())
		{
		default:
			break;
		}
	}

	void ISimulateLayer::Receive( IMessage *message )
	{
		ISimulateObject::Ptr obj = LookupObject(message->GetSenderID());
		if (NULL != obj)
		{
			obj->Process(message);
		}
		else
		{
			Process(message);
		}
	}

	void ISimulateLayer::Send( IMessage *message ) const
	{
		
	}

	void ISimulateLayer::Tick( float dt )
	{
		for (SimulateObjList::iterator it = m_objList.begin(); m_objList.end() != it; ++it)
		{
			(*it)->Tick(dt);
		}
	}

	void ISimulateLayer::Init( void )
	{

	}

}
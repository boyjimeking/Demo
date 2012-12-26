//////////////////////////////////////////////////////////////////////////
//
//	file path:	VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef ISimulateLayer_h__
#define ISimulateLayer_h__

#include <vector>
#include "ISimulateObject.h"

struct IMessage;

namespace Server
{
	class ISimulateObject;
	class ISimulateLayer
	{
	public:
		ISimulateLayer(void);
		virtual ~ISimulateLayer(void);

		virtual void Init(void);

		virtual void PushObject(ISimulateObject::Ptr obj);
		virtual void PopObject(ISimulateObject::Ptr obj);
		ISimulateObject::Ptr LookupObject(int id);

		void Receive(IMessage *message);
		virtual void Send(IMessage *message) const;
		virtual void Tick(float dt);
	protected:
		virtual void Process(IMessage *message);
	protected:
		typedef std::vector<ISimulateObject::Ptr> SimulateObjList;
		SimulateObjList m_objList;
	private:

	};
}

#endif // ISimulateLayer_h__

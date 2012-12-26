//////////////////////////////////////////////////////////////////////////
//
//	file path:	VirtualServer
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef ISimulateObject_h__
#define ISimulateObject_h__

#include "boost/smart_ptr.hpp"
#include "SimulateType.h"

struct IMessage;

namespace Server
{
	class ISimulateLayer;
	class ISimulateObject
	{
	public:
		typedef boost::shared_ptr<ISimulateObject> Ptr;
		virtual ENSimulateType::Decl GetType() const { return ENSimulateType::enError; }

		ISimulateObject(void);
		virtual ~ISimulateObject(void);

		virtual void OnPush(ISimulateLayer *layer);
		virtual void OnPop(ISimulateLayer *layer);

		virtual void Process(IMessage *message);
		virtual void Send(IMessage *message) const;
		virtual void Tick(float dt);

		int GetID(void) const { return m_id; }
		void SetID(int val) { m_id = val; }

		ISimulateLayer* GetSimulate(void) const { return m_simulate; }
	protected:

	private:
		int m_id;
		ISimulateLayer *m_simulate;
	};

#define _Decl_Simulate(className)\
	typedef boost::shared_ptr<className> Ptr;\
	virtual ENSimulateType::Decl GetType() const { return _Get_SimulateType(className); }\
	static Ptr CreateObject(void);

#define _Def_Simulate(className)\
	className::Ptr className::CreateObject(void)\
	{\
		return className::Ptr(new className);\
	}
}

#endif // ISimulateObject_h__

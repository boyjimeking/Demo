//
//  ServerActor.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__ServerActor__
#define __Demo__ServerActor__

#include "boost/smart_ptr.hpp"

namespace Net
{
	struct IMessage;
	class ServerActor
	{
	public:
		typedef boost::shared_ptr<ServerActor> Ptr;

		ServerActor(void);
		virtual ~ServerActor();
	
		int GetID(void) const { return m_id; }

		void Receive(IMessage *message);
    	void Send(IMessage *message);

    	static Ptr CreateObj(void);

    	float GetX(void) const { return m_x; }
    	float GetY(void) const { return m_y; }

    	void SetX(float x) { m_x = x; }
    	void SetY(float y) { m_y = y; }

    	virtual void Tick(float dt);

    	//向客户端同步位置
    	virtual void SycPosition(void);
    private:
    	float m_x;
    	float m_y;
	private:
		const int m_id;
		static int Count;
	};
}

#endif /* defined(__Demo__ServerActor__) */

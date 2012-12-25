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
	class Server;
	class ServerActor
	{
	public:
		typedef boost::shared_ptr<ServerActor> Ptr;

		ServerActor(void);
		virtual ~ServerActor();
	
		int GetID(void) const { return m_id; }

		virtual void Receive(IMessage *message);
    	void Send(IMessage *message);

    	static Ptr CreateObj(void);

    	float GetX(void) const { return m_x; }
    	float GetY(void) const { return m_y; }

    	void SetX(float x) { m_x = x; }
    	void SetY(float y) { m_y = y; }

    	virtual void Tick(float dt);

    	//向客户端同步位置
		virtual void SycPosition(void);
		//更换装备
		virtual void ChangeEquip(void);
		//攻击
		virtual void Attack(int targetID);

		void SetAttacking(bool isTrue);

		void SetServer(Server *server) { m_server = server; }
		Server* GetServer(void) const { return m_server; }
    private:
    	void ChangeTarget(void);
	protected:
    private:
		Server *m_server;
    	float m_x;
    	float m_y;

    	float m_totalTime;
		bool m_isAttacking;
	private:
		const int m_id;
		static int Count;
	};
}

#endif /* defined(__Demo__ServerActor__) */

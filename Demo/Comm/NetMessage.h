//
//  NetMessage.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Comm__NetMessage__H__
#define __Comm__NetMessage__H__


#include <stdlib.h>
#include <boost/thread/recursive_mutex.hpp>

#define _SE_En_Decl_V_(className,value,check1,check2,check3) en##className = value,
//#define _SE_AN_(className,value) en##className = value,

enum ENMSGID
{
#include "ClientMsgDef.h"
#include "ServerMsgDef.h"
};

#undef _SE_AN_
//#undef _SE_En_Decl_V_


#define GenSEID(a) this->MsgType=en##a

//消息包的特殊值
enum enumMsgFlag
{
	PacketFlag_Normal					= 0,  //正常消息包

	PacketFlag_Compress				    = 1,  //消息是压缩的
	PacketFlag_Encrypt					= 2,  //消息是加密的
	PacketFlag_WithSendRange            = 4,  //消息有附加数据

	PacketFlag_SubPacket                = 8,  //分割消息包

	PacketFlag_SubPacketEnd             = 16, //分割消息包结束

	PacketFlag_Compress_Need_Checksum   = 12345, //压缩的时候需要Checksum(crc32)//0x3039
};

//发送的目标范围
enum enumSendRange
{
	Sendrange_List = 0,//发送给消息后面带的id列表
	Sendrange_World = 1,//发送给全部游戏世界里的玩家
	Sendrange_All = 2//发送给所有的客户端(包括游戏世界里面和外面的)
};

enum MsgTypeBase
{
	MSG_SSLSendPublicKey = 1,
	MSG_SSLSendSessionKey = 2,
	MSG_NetPing = 3,
};

//#pragma pack(push,1)

//发到前置器去的消息，消息需要广播时附加的数据，放到消息最后面
//NetMessage.Length += 1 + arraycount*2 + 2;
//比如要发送给1000个对象，那么消息增加的大小为1+1000*2 +2 = 2003字节
//比如要发送给0个对象(SendRange != sendrange_list时)，那么消息增加的大小为1+0*2 +2 = 3字节
struct MsgAdditionalData
{
	char	SendRange;

	enum
	{
		max_id_number_broadcast = 4096,//最多一个消息将广播的对象个数
	};
	short playerarray[max_id_number_broadcast]; //最后一个是个数大小
};

//消息包头定义
struct NetMessage
{
	///Flags
	short	PacketFlag;

	//Packet Length
	short	Length;
	//Packet ID
	union
	{
        int     MsgType;
		int		PacketID;//为了方便和别的程序通讯，消息id还是采用枚举定义，在编译期确定
	};
	//CheckSum
	int     SerialNumber;

	//Client or DispatcherID (special use)
	union
	{
		int     DispatcherID;
		struct
		{
			short ClientID;//On FrontEnd
			short FrontEndID;
		};
	};

public:
	NetMessage()
		:PacketFlag(PacketFlag_Normal)
		,Length(sizeof(NetMessage))
        ,MsgType(0)
		,SerialNumber(0)
		,DispatcherID(0)
	{

	}

public:
	static const int MsgHeaderLength = 16;//16
	static const int MsgMustInfoLength = 4;//(ushort + ushort)
	static const int Max_Msg_Size = 32767;//<30K
	static const int Min_Compress_Size = 100;
	static const int SubPacketLength = 1024;//分割消息包的大小

	void   AddFlag(enumMsgFlag flag) {PacketFlag |= flag;}
	int    GetType(){return this->MsgType; }
	unsigned short GetLength(){return this->Length; }
};

struct TMsgLogin:public NetMessage
{
    TMsgLogin()
    {
        Length = sizeof(*this);
        MsgType = enLogin;
    }
    char m_userName[128];
	char m_password[128];
};

struct TMsgInitScene_S2C:public NetMessage
{
    TMsgInitScene_S2C()
    {
        Length = sizeof(*this);
        MsgType = enInitScene_S2C;
    }
    int m_sceneID;
	char m_sceneName[128];
};

struct PlayerBattleInfo{
    int m_HP;
	int m_maxHP;
	//是否存活
	bool m_isAlive;
    void Set(const PlayerBattleInfo& info)
    {
        m_HP = info.m_HP;
        m_maxHP = info.m_maxHP;
        m_isAlive = info.m_isAlive;
    }
};

struct TMsgInitPlayer_S2C:public NetMessage
{
    enum
	{
		PlayerNameLength = 32,
	};
    TMsgInitPlayer_S2C()
    {
        Length = sizeof(*this);
        MsgType = enInitPlayer_S2C;
    }
	int m_actorID;
	char m_playerName[PlayerNameLength];
	float m_x;
	float m_y;
    PlayerBattleInfo m_battleInfo;
};

struct TMsgChangeActorEquip_S2C:public NetMessage
{
	TMsgChangeActorEquip_S2C()
	{
		Length = sizeof(*this);
		MsgType = enChangeActorEquip_S2C;
	}
    int m_actorID;
	int m_equipType;
	char m_equipName[128];
};

struct TMsgInitNPC_S2C:public NetMessage
{
	TMsgInitNPC_S2C()
	{
		Length = sizeof(*this);
		MsgType = enInitNPC_S2C;
	}
	int m_actorID;
	int m_npcStaticID;
	float m_x;
	float m_y;
    PlayerBattleInfo m_battleInfo;
};

struct TMsgSycActor_S2C:public NetMessage
{
	TMsgSycActor_S2C()
	{
		Length = sizeof(*this);
		MsgType = enSycActor_S2C;
	}
	int m_actorID;
	float m_x;
	float m_y;
};

struct TMsgMoveTo_S2C:public NetMessage
{
	TMsgMoveTo_S2C()
	{
		Length = sizeof(*this);
		MsgType = enMoveTo_S2C;
	}
	int m_actorID;
	float m_x;
	float m_y;
};

struct TMsgAttackTarget_C2S:public NetMessage
{
	TMsgAttackTarget_C2S()
	{
		Length = sizeof(*this);
		MsgType = enAttackTarget_C2S;
	}
	int m_actorID;
	int m_targetID;
};

struct TMsgAttackTarget_S2C:public NetMessage
{
	TMsgAttackTarget_S2C()
	{
		Length = sizeof(*this);
		MsgType = enAttackTarget_S2C;
	}
	int m_actorID;
	int m_targetID;
};

struct TMsgDead_S2C:public NetMessage
{
	TMsgDead_S2C()
	{
		Length = sizeof(*this);
		MsgType = enDead_S2C;
	}
	int m_actorID;
};

struct TMsgBeAttack_S2C:public NetMessage
{
	TMsgBeAttack_S2C()
	{
		Length = sizeof(*this);
		MsgType = enBeAttack_S2C;
	}
	int m_actorID;
	int m_hpChanged;
};

struct SSLMSGSendPublicKey:public NetMessage
{
	SSLMSGSendPublicKey()
	{
		this->PacketID = MSG_SSLSendPublicKey;
		this->Length = sizeof(*this);
		int keylen = sizeof(KeyData);
		EncryptFlag = PacketFlag_Compress_Need_Checksum;
		for(int i=0;i<keylen;i++){
			unsigned char temp = rand()%256;
			KeyData[i] = temp;
		}
	}
	int EncryptFlag;
	unsigned char  KeyData[128];
};

struct SSLMSGSendSessionKey:public NetMessage
{
	SSLMSGSendSessionKey()
	{
		this->PacketID = MSG_SSLSendSessionKey;
		this->Length = sizeof(*this);
	}

	unsigned char  KeyData[128];
};

struct NetPingMsg : public NetMessage
{
	enum EntryType
	{
		enEntryClient=0,
		enEntryGateIn=1,
		enEntryServer=2,
		enEntryGateOut=3,
		enEntryMax=4,
	};
	NetPingMsg()
	{
		this->PacketID = MSG_NetPing;
		this->Length = sizeof(*this);
		m_fromEntry = enEntryClient;
		m_sendTime[enEntryClient]=0;
		m_recvTime[enEntryClient]=0;
		m_sendTime[enEntryGateIn]=0;
		m_recvTime[enEntryGateIn]=0;
		m_sendTime[enEntryServer]=0;
		m_recvTime[enEntryServer]=0;
		m_sendTime[enEntryGateOut]=0;
		m_recvTime[enEntryGateOut]=0;
	}
	//!获取entry到entry+1的网络延迟
	unsigned int GetNetworkLatencyTime(unsigned int entry)
	{
		if (entry==enEntryClient || entry == enEntryGateOut)
		{
			unsigned int totalWorkTime = m_sendTime[enEntryGateIn] - m_recvTime[enEntryGateIn]
			+m_sendTime[enEntryServer] - m_recvTime[enEntryServer]
			+m_sendTime[enEntryGateOut] - m_recvTime[enEntryGateOut];
			unsigned int later = m_recvTime[enEntryClient]>m_sendTime[enEntryClient] ? m_recvTime[enEntryClient]-m_sendTime[enEntryClient] : 0;
			unsigned int gateLatency = GetNetworkLatencyTime(enEntryGateIn);
			if (later>totalWorkTime && (later - totalWorkTime)/2>gateLatency)
			{
				return (later - totalWorkTime)/2 - gateLatency;
			}
		}
		else if (entry == enEntryGateIn || entry == enEntryServer)
		{
			int totalWorkTime = m_sendTime[enEntryServer] - m_recvTime[enEntryServer];
			int later = m_recvTime[enEntryGateOut]-m_sendTime[enEntryGateIn];
			if (later>totalWorkTime)
			{
				return (later - totalWorkTime)/2;
			}
		}
		return 0;
	}
	//!获取entry的处理延迟
	unsigned int GetWorkLatencyTime(unsigned int entry)
	{
		if (entry < enEntryMax && m_sendTime[entry] > m_recvTime[entry])
		{
			return m_sendTime[entry] - m_recvTime[entry];
		}
		return 0;
	}
	int m_fromEntry;
	unsigned int m_sendTime[enEntryMax]; //Client发送这个包的时间(C)
	unsigned int m_recvTime[enEntryMax]; //接收到时候时间（S）
};

//#pragma pack( pop )

#endif

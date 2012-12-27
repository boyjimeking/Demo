//
//  CSMessageDef.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__CSMessageDef__
#define __Demo__CSMessageDef__

#include "CSMessageType.h"

struct IMessage
{
	IMessage(void);
	virtual ~IMessage(void);

	void Build(ENMessage::Type type, int senderID, int length);

	inline ENMessage::Type GetType(void) const { return m_type; }
	inline int GetSenderID(void) const { return m_senderID; }
	inline int GetLength(void) const { return m_length; }
private:
	ENMessage::Type m_type;
	int m_senderID;
	int m_length;
};

struct CSInitScene_S2C
	:public IMessage
{
	int m_sceneID;
	char m_sceneName[128];
};
struct CSInitPlayer_S2C 
	:public IMessage
{
	enum
	{
		PlayerNameLength = 32,
		DataMaxLength = 1024,
	};
	int m_actorID;
	char m_playerName[PlayerNameLength];
	float m_x;
	float m_y;
	unsigned int m_dataLength;
	unsigned char m_data[DataMaxLength];
};
struct CSInitNPC_S2C
	:public IMessage
{
	enum
	{
		DataMaxLength = 1024,
	};
	int m_actorID;
	int m_npcStaticID;
	float m_x;
	float m_y;
	unsigned int m_dataLength;
	unsigned char m_data[DataMaxLength];
};

struct CSChangeActorEquip_S2C
	:public IMessage
{
	int m_actorID;
	int m_equipType;
	char m_equipName[128];
};
struct CSSycActor_S2C
	:public IMessage
{
	int m_actorID;
	float m_x;
	float m_y;
};
struct CSMoveTo_S2C
	:public IMessage
{
	int m_actorID;
	float m_x;
	float m_y;
};
struct CSAttackTarget_C2S
	:public IMessage
{
	int m_actorID;
	int m_targetID;
};
struct CSAttackTarget_S2C
	:public IMessage
{
	int m_actorID;
	int m_targetID;
};
struct CSDead_S2C
	:public IMessage
{
	int m_actorID;
};

#endif /* defined(__Demo__CSMessageDef__) */

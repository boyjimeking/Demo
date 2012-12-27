//
//  CSMessageType.h
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#ifndef __Demo__CSMessageType__
#define __Demo__CSMessageType__

#ifndef DefType
#define DefType(className) en##className
#endif

struct ENMessage
{
	enum Type
	{
		enError,
		//////////////////////////////////////////////////////////////////////////
		//Server to Client
		enServerMessageStart,
		DefType(CSInitScene_S2C),
		DefType(CSInitPlayer_S2C),
		DefType(CSInitNPC_S2C),
		DefType(CSSycActor_S2C),
		DefType(CSMoveTo_S2C),
		DefType(CSChangeActorEquip_S2C),
		DefType(CSAttackTarget_S2C),
		DefType(CSDead_S2C),
		DefType(CSBeAttack_S2C),

		S2CMax = 4096,
		//////////////////////////////////////////////////////////////////////////
		//Client to Server
		enClientMessageStart,
		DefType(CSAttackTarget_C2S),

		C2SMax = 8192,
	};
};

#ifndef GetMessageType
#define GetMessageType(className) ENMessage::en##className
#endif

#endif /* defined(__Demo__CSMessageType__) */

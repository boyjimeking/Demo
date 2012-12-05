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

namespace Net
{
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
    };
    struct CSInitMainActor_S2C
        :public IMessage
    {
        int m_mainActorID;
        float m_x;
        float m_y;
    };
    struct CSSycActor_S2C
        :public IMessage
    {
        int m_actorID;
        float m_x;
        float m_y;
    };
}

#endif /* defined(__Demo__CSMessageDef__) */

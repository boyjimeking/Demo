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

    struct CSInit_S2C
        :public IMessage
    {
        int m_mainActorID;
        int m_sceneID;
    };
}

#endif /* defined(__Demo__CSMessageDef__) */

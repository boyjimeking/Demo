//
//  CSMessageDef.cpp
//  Demo
//
//  Created by Mingzhen.Zhang on 12-12-5.
//
//

#include "CSMessageDef.h"

IMessage::IMessage(void)
	:m_type(ENMessage::enError)
	,m_senderID(0)
	,m_length(0)
{

}
IMessage::~IMessage(void)
{

}
void IMessage::Build(ENMessage::Type type, int senderID, int length)
{
	m_type = type;
	m_senderID = senderID;
	m_length = length;
}
//
//  NetConnect.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Comm__NetConnect__H__
#define __Comm__NetConnect__H__


#include "NetMessage.h"
#include "MsgPool.h"
#include "MsgQueue.h"
#include "NetCounter.h"

namespace Net
{
    enum NetState
    {
        NetState_Uninitialize = 0,
        NetState_Connected    = 1,
        NetState_SSLIniting   = 2,
        NetState_Close = 3,
    };
    
    inline void _safe_memcpy(void* dst,void* src,size_t size,size_t dstSize){
        if (size>dstSize)
        {
            printf("Error use _safe_memcpy\r\n");
        }
        memcpy(dst,src,size);
    }
    
    template<typename TSender,typename TFastMutex
	,typename TNetMessage=NetMessage
	,typename TCrypt=int,typename TCompress=void>
    class NetConnect
    {
    public:
        typedef TFastMutex				NCFastMutex;
        typedef typename NCFastMutex::scope_lock NCScope_lock;
        typedef TNetMessage				NCNetMessage;
        typedef MsgPoolA_Safe<4 * 1024 * 1024,NCFastMutex>	NCMsgPool; //实测4M的Buff比较合适
        typedef MsgQueue<NCNetMessage,NCMsgPool,NCFastMutex>			NCMsgQueue;
        typedef TCrypt												NCCrypt;
        
        TSender		m_sender;
        NCMsgQueue* m_inQueue;
        NCMsgQueue* m_outQueue;
        
        NCFastMutex m_SendMutex;
        char		m_sendBuffer[NCNetMessage::Max_Msg_Size + 8192];
        int			m_sendBufferSize;
        //!正在发送的字节数量
        int			m_sendingBytes;
        //!正在发送
        bool		m_isSending;
        
        char	m_ReceiveBuffer[NCNetMessage::Max_Msg_Size + 8192];//8k
        int		m_iSegmentSize;//未处理消息包的大小
        int     m_iPacketSerialNum;
        int     m_iLastPacketSerialNum;
        long	m_iRecPacketSerialNum;
        int		m_needFlushSendBytes;
        int		m_lastRecvPingTime;
        int		m_lastSendPingTime;
        unsigned long m_lIp;
        //!接收数据流量记录 [1/9/2010 tgame]
        NetPingMsg	m_lastPingMsg;
        NetRateCount m_recvRate;
        NetRateCount m_sendRate;
        int			m_recvRateBytesPerSecond;
        NetState	m_netState;
        NetConnect(NCMsgPool* msgPool,TSender sender)
		:m_sender(sender)
        {
            m_inQueue = new NCMsgQueue(msgPool, true);
            m_outQueue = new NCMsgQueue(msgPool, true);
            m_sender=sender;
            m_sendBufferSize=sizeof(m_sendBuffer);
            m_sendingBytes=0;
            m_isSending=false;
            m_iSegmentSize=0;
            m_iPacketSerialNum=0;
            m_iLastPacketSerialNum=0;
            m_iRecPacketSerialNum=0;
            m_needFlushSendBytes=4096;
            m_lastRecvPingTime=0;
            m_lastSendPingTime=0;
            m_lIp=0;
            m_recvRateBytesPerSecond=0;
            m_netState=NetState_Connected;
            memset(m_sendBuffer,0,m_sendBufferSize);
        }
        ~NetConnect(void){
            delete m_inQueue;
            delete m_outQueue;
        }
        
        void Release(){
            
        }
        void Update(void* state = 0){
            FlushSend();
        }
        void OnSendCompelete(int bytes_transferred){
            {
                m_sendRate.Count(bytes_transferred);
                NCScope_lock l(m_SendMutex);
                _safe_memcpy(m_sendBuffer,&m_sendBuffer[bytes_transferred],m_sendingBytes-bytes_transferred,sizeof(m_sendBuffer));
                m_sendingBytes-=bytes_transferred;
                m_isSending=false;
            }
            FlushSend();
        }
        void FlushSend(void){
            if (m_outQueue->blockcount()==0&&0==m_sendingBytes)
            {
                return;
            }
            NCScope_lock l(m_SendMutex);
            if (m_isSending)
            {
                return;
            }
            m_isSending=true;
            int msgCount=0;
            int bytes = m_outQueue->PopEnoughMsg((NCNetMessage*)(m_sendBuffer+m_sendingBytes),m_sendBufferSize-m_sendingBytes,msgCount);
            m_sendingBytes+=bytes;
            if (m_sendingBytes)
            {
                if(m_sender(m_sendBuffer,m_sendingBytes))
                {
                    return;
                }
            }
            m_isSending=false;
        }
        void SendMsg(NCNetMessage* pMsg,bool cryptifneed = false,bool relibaleudp = true){
            pMsg->SerialNumber = m_iLastPacketSerialNum++;
            m_outQueue->PushMsg(pMsg);
            if (m_outQueue->bytes()>=m_needFlushSendBytes)
            {
                FlushSend();
            }
        }
        template<int>
        bool DecryptAndDecompressMsg(NCNetMessage* pMsg){
            return false;
        }
        template<typename NCCrypt>
        bool DecryptAndDecompressMsg(NCNetMessage* pMsg){
            return false;
        }
        
        bool GetMsg(/*OUT*/NCNetMessage* pMsg)
        {
            if(m_inQueue->blockcount() == 0)
                return false;
            if(m_inQueue->PopMsg(pMsg))
            {
                if(	( (pMsg->PacketFlag & PacketFlag_Encrypt) == PacketFlag_Encrypt ||
                     (pMsg->PacketFlag & PacketFlag_Compress) == PacketFlag_Compress))
                {
                    if(!DecryptAndDecompressMsg<TCrypt>(pMsg))
                        return false;
                    return true;
                }
                return true;
            }
            return false;
        }
        
        bool ProcessRecvData(int size){
            if(size <= 0 )
                return false;
            m_recvRate.Count(size);
            m_recvRateBytesPerSecond = m_recvRate.RefreshRate();
            int startoffset = 0;
            m_iSegmentSize += size;
            if(m_iSegmentSize <= 0)
                return false;//end loop,socket reset!!!
            
            NCNetMessage* pMsg = (NCNetMessage*)m_ReceiveBuffer;
            while(m_iSegmentSize >= NetMessage::MsgMustInfoLength)//有消息flag和长度信息了，消息长度是short,2个字节
            {
                unsigned short msglength = pMsg->Length;
                if(msglength > NCNetMessage::Max_Msg_Size || msglength < NCNetMessage::MsgHeaderLength)
                {	//错误!
                    m_iSegmentSize = 0;
                    return false;
                }
                
                if(m_iSegmentSize >= msglength){
                    HandleAsynRecvOneRawMsg(pMsg);
                    pMsg = (NCNetMessage*)(((char*)pMsg) + msglength);
                    m_iSegmentSize -= msglength;
                    startoffset += msglength;
                }
                else
                    break;
            }
            if(startoffset > 0 && m_iSegmentSize > 0)
            {
                ::memcpy(m_ReceiveBuffer, pMsg, m_iSegmentSize);//剩余数据前移
            }
            return true;
        }
        void HandleAsynRecvOneRawMsg(NCNetMessage* pMsg)
        {
            if(0==m_iRecPacketSerialNum)
            {
                m_iRecPacketSerialNum = pMsg->SerialNumber;
            }
            else
            {
                m_iRecPacketSerialNum++;
            }
            if (m_iRecPacketSerialNum != pMsg->SerialNumber)
            {
                OnErrorClose(5432);
                return;
            }
            //InterlockedIncrement(&m_iRecPacketSerialNum);
            bool giveToAppLayer = false;
            if(pMsg->GetType() == MSG_SSLSendPublicKey||pMsg->GetType() == MSG_SSLSendSessionKey)//public key
                OnReceiveSSLInfo<TCrypt>(pMsg);
            else if(m_netState == NetState_SSLIniting)
                OnErrorClose(__LINE__ + 20000);
            else if(pMsg->GetType() == MSG_NetPing)
            {
                giveToAppLayer=true;
                OnReceivedPingMsg(pMsg);
            }
            else
            {
                giveToAppLayer=true;
            }
            if (giveToAppLayer)
            {
                m_inQueue->PushMsg(pMsg);
            }
        }
        template<int>
        void OnReceiveSSLInfo(NCNetMessage* pMsg){
        }
        
        template<typename NCCrypt>
        void OnReceiveSSLInfo(NCNetMessage* pMsg){
            
        }
        
        void OnReceivedPingMsg(NCNetMessage* pMsg)
        {
            NetPingMsg * pingMsg = (NetPingMsg *)pMsg;
            if (pMsg->GetLength() < sizeof(NetPingMsg))
            {
                return;
            }
            int me = (pingMsg->m_fromEntry+1)%NetPingMsg::enEntryMax;
            pingMsg->m_recvTime[me] = 0;//GetTickCount();
            pingMsg->m_fromEntry=me;
            m_lastPingMsg = *pingMsg;
            m_lastRecvPingTime = 0;//GetTickCount();
        }
        void OnErrorClose(int errorCode){
            printf("Error Msg Number\r\n");
        }
        //////////////////////////////////////////////////////////////////////////
        //
    };

}

#endif

//
//  MsgQueue.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Demo__MsgQueue__H__
#define __Demo__MsgQueue__H__

#include "CircleDeque.h"

namespace Net
{
    template<typename TMessage,class PoolType,typename TFastMutex>
    class MsgQueue
    {
    public:
        
        MsgQueue(PoolType* pool, bool isThreadSafe)
		:_pool(pool)
        {
            m_bytes=0;
            if (isThreadSafe)
                _mutex1 = new TFastMutex;
            else
                _mutex1 = 0;
        }
        ~MsgQueue()
        {
            if (_mutex1)
            {
                delete _mutex1;
            }
            _freeAll();
        }
        
        size_t blockcount()
        {
            return _queue1.size();
        }
        int bytes(void){
            return m_bytes;
        }
        
        bool PushMsg(TMessage* pMsg)
        {
            if(!pMsg || pMsg->Length >= TMessage::Max_Msg_Size)
                return false;
            
            void* buf = _alloc(pMsg->Length);
            memcpy(buf,pMsg,pMsg->Length);
            
            _push(reinterpret_cast<TMessage*>(buf));
            return true;
        }
        
        bool PopMsg(TMessage* pMsg = 0)
        {
            TMessage* headMsg  = _pop();
            if (headMsg != 0)
            {
                if(pMsg != 0)
                {
                    memcpy(pMsg,headMsg,headMsg->Length);
                }
                _free(headMsg);
                return true;
            }
            else
                return false;
        }
        
        
        int PopEnoughMsg(TMessage* pMsg,int maxlength,int& msgcount)
        {
            if(pMsg == 0 || maxlength <= 2)
                return 0;
            
            char* outptr = (char*)pMsg;
            
            int poplength = 0;
            msgcount = 0;
            if (_mutex1) _mutex1->lock();
            while(!_queue1.empty())
            {
                TMessage* headMsg = _queue1.front();
                if(poplength + headMsg->Length > maxlength)
                    break;
                memcpy(outptr + poplength,headMsg,headMsg->Length);
                ++msgcount;
                poplength += headMsg->Length;
                m_bytes-=headMsg->Length;
                _free(headMsg);
                _queue1.pop_front();
            }
            if (_mutex1) _mutex1->unlock();
            return poplength;
        }
        
        void reset()
        {
            if (_mutex1) _mutex1->lock();
            _freeAll();
            _queue1.clear();
            if (_mutex1) _mutex1->unlock();
        }
        
        //通过偏移获得消息指针，不保证多线程安全
        TMessage* get(size_t idx)
        {
            if (_mutex1)
            {
                _mutex1->lock();
                TMessage* msg=_queue1.get(idx);
                _mutex1->unlock();
                return msg;
            }
            else
            {
                return _queue1.get(idx);
            }
        }
        
        //线程安全
        bool get(TMessage* msg,size_t idx)
        {
            if (_mutex1) _mutex1->lock();
            TMessage* headMsg=_queue1.get(idx);
            if (headMsg)
            {
                ::memcpy(msg,headMsg,headMsg->Length);
            }
            
            if (_mutex1) _mutex1->unlock();
            return headMsg!=NULL;
        }
        
        
    private:
        
        CircleDeque<TMessage*> _queue1;
        TFastMutex* _mutex1;
        PoolType* _pool;
        int m_bytes;
        
        TMessage* _pop()
        {
            TMessage* ret = 0;
            if (_mutex1) _mutex1->lock();
            
            if (!_queue1.empty())
            {
                ret = _queue1.front();
                m_bytes-=ret->Length;
                _queue1.pop_front();
            }
            if (_mutex1) _mutex1->unlock();
            
            return ret;
        };
        
        void _push(TMessage* pMsg)
        {
            if (_mutex1) _mutex1->lock();
            
            _queue1.push_back(pMsg);
            m_bytes+=pMsg->Length;
            if (_mutex1) _mutex1->unlock();
            
        };
        
        void _freeAll()
        {
            while (!_queue1.empty())
            {
                _free(_queue1.front());
                _queue1.pop_front();
            }
            m_bytes=0;
        }
        TMessage* _alloc(size_t len)
        {
            return (TMessage*)(_pool ? _pool->alloc(len) : malloc(len));
        }
        void _free(TMessage* p)
        {
            if (_pool)
                _pool->free(p, p->Length) ;
            else
                free(p);
        }
    };
}

#endif //__Demo__MsgQueue__H__
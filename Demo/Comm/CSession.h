//
//  CSession.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//

#ifndef __Demo_CSession__H__
#define __Demo_CSession__H__

#include <vector>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include "NetMessage.h"
#include "NetConnect.h"

using boost::asio::ip::tcp;
using namespace boost::posix_time;

namespace Net
{
    template<typename TAccount>
    class CSession
    {
    public:
        struct _Sender
        {
            CSession* m_session;
            _Sender(CSession* s){
                m_session=s;
            }
            bool operator()(void* buf,int size){
                if (m_session->isclose())
                {
                    return false;
                }
                m_session->socket().async_write_some(boost::asio::buffer(buf, size),
                                                     boost::bind(&CSession::handle_write, m_session,boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred)
                                                     );
                return true;
            }
        };
        struct _FastMutex
        {
            struct scope_lock
            {
                _FastMutex& m_mutex;
                scope_lock(_FastMutex& mutex):m_mutex(mutex){
                    m_mutex.lock();
                }
                ~scope_lock(void){
                    m_mutex.unlock();
                }
            };
            boost::recursive_mutex m_mutex;
            void lock(void){
                m_mutex.lock();
            }
            void unlock(void){
                m_mutex.unlock();
            }
        };
        typedef NetConnect<_Sender,_FastMutex>	SessionConnect;
        typedef typename SessionConnect::NCMsgPool	MyMsgPool;
        
        //boost::bind(&CSession::send, this,sendBuf,boost::asio::placeholders::error,boost::asio::placeholders::bytes_transferred)
        CSession(boost::asio::io_service& io_service):
        m_socket(io_service),
        m_conn(0),
        m_pAccount(0),
        m_bConnected(false),
        m_nSessionID(0)
        {
            
            m_conn=new SessionConnect(&ms_pool,_Sender(this));
            m_isRecving=false;
            m_close=false;
        }
        ~CSession(void){
            delete m_conn;
            m_conn = NULL;
            m_bConnected = false;
        }
        tcp::socket& socket()
        {
            return m_socket;
        }
        void start(void)
        {
            boost::asio::ip::tcp::no_delay option1(true);
            socket().set_option(option1);
            boost::asio::socket_base::linger option2(false, 0);
            socket().set_option(option2);
            //		boost::asio::socket_base::send_buffer_size option3(0);
            //		socket().set_option(option3);
            //////////////////////////////////////////////////////////////////////////
            m_isRecving=true;
            m_bConnected = true;
            char* buf = m_conn->m_ReceiveBuffer+m_conn->m_iSegmentSize;
            int size = sizeof(m_conn->m_ReceiveBuffer)-m_conn->m_iSegmentSize;
            m_socket.async_read_some(boost::asio::buffer(buf,size),
                                     boost::bind(&CSession::handle_read, this,
                                                 boost::asio::placeholders::error,
                                                 boost::asio::placeholders::bytes_transferred));
        }
        void update(void){
            m_conn->Update(0);
        }
        void handle_read(const boost::system::error_code& error,
                         size_t bytes_transferred)
        {
            if (!error)
            {
                m_conn->ProcessRecvData(bytes_transferred);
                //////////////////////////////////////////////////////////////////////////
                char* buf = m_conn->m_ReceiveBuffer+m_conn->m_iSegmentSize;
                int size = sizeof(m_conn->m_ReceiveBuffer)-m_conn->m_iSegmentSize;
                m_socket.async_read_some(boost::asio::buffer(buf,size),
                                         boost::bind(&CSession::handle_read, this,
                                                     boost::asio::placeholders::error,
                                                     boost::asio::placeholders::bytes_transferred));
            }
            else
            {
                m_close=true;
                m_isRecving=false;
            }
        }
        
        void handle_write(const boost::system::error_code& error,
                          size_t bytes_transferred)
        {
            m_conn->OnSendCompelete(bytes_transferred);
            if(error)
            {
                m_close=true;
            }
        }
        bool isclose(void){
            return m_close;
        }
        bool IsConnected(){
            return m_bConnected;
        }
        
        
        bool canclose(void){
            return !m_isRecving && !m_conn->m_isSending;
        }
        
        SessionConnect*	m_conn;
        static MyMsgPool ms_pool;
        TAccount*       m_pAccount;
        int             m_nSessionID;
        
	private:
		
		tcp::socket m_socket;
		bool	m_close;
		bool	m_isRecving;
		bool	m_bConnected;
    };
    
    template<typename TAccount> typename CSession<TAccount>::MyMsgPool CSession<TAccount>::ms_pool;

}

#endif //__Demo_CSession__H__
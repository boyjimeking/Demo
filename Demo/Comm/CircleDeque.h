/********************************************************************
	created:	2009/09/24
	created:	24:9:2009   14:45
	filename: 	E:\Work_MZone\SourceCode\Src\Network\Network\CirecleD.h
	file path:	E:\Work_MZone\SourceCode\Src\Network\Network
	file base:	CirecleD
	file ext:	h
	author:		tgame

	purpose:
*********************************************************************/
#ifndef _24_9_2009_CirecleD
#define _24_9_2009_CirecleD

#include <vector>

namespace Net
{
    template<class T>
    struct CircleDeque
    {
        CircleDeque(void)
        {
            clear();
            reserve(512);
        }
        void clear(void)
        {
            m_beginPos=0;
            m_endPos=0;
        }
        void pop_front(void)
        {
            if (!empty())
            {
                m_beginPos++;
            }
        }
        T& front(void)
        {
            if (!empty())
            {
                return get_ref(m_beginPos);
            }
            static T t;
            return t;
        }
        
        T& get(size_t idx)
        {
            if (idx<size())
            {
                return get_ref(m_beginPos+idx);
            }
            
            static T t;
            return t;
        }
        
        size_t size(void)
        {
            return m_endPos-m_beginPos;
        }
        bool empty(void)
        {
            return m_beginPos==m_endPos;
        }
        void push_back(T& obj)
        {
            if (!havespace())
            {
                //得移动数据,大小改变,actualBegin和actualEnd是相等的.
                //assert(false);
                size_t actualBegin = get_actual_pos(m_beginPos);
                size_t actualEnd = get_actual_pos(m_endPos);
                /*
                 1.是移动前面这部分的数据到原来的末尾
                 例如300大小,begin位置为44,
                 扩大大小150,变成450,
                 0-43移动到300-343,
                 新的begin=44,end=344,
                 2.移动后面的数据到新的最末尾
                 例如300大小,begin位置为280
                 扩大大小150,变成450,
                 移动280-299到(449-(299-280)) - 449
                 新的begin=(449-(299-280)),end变成450+280
                 */
                size_t oldSize = m_container.size();
                size_t incSize = m_container.size()>>1;
                if (actualBegin<=incSize)
                {
                    m_container.resize(oldSize+incSize);
                    if (actualBegin)
                    {
                        memmove(&*m_container.begin()+oldSize,&*m_container.begin(),actualBegin* sizeof (T));
                        //std::_Move(m_container.begin(),m_container.begin()+actualBegin,m_container.begin()+oldSize);
                        //printf("\r\nMove data[%d] new reserve size:%d\r\n",actualBegin,m_container.size());
                    }
                    m_beginPos=actualBegin;
                    m_endPos = m_beginPos+oldSize;
                }
                else
                {
                    m_container.resize(oldSize+incSize);
                    if (oldSize-actualBegin>0)
                    {
                        size_t count = oldSize-actualBegin;
                        memmove(&*m_container.begin()+m_container.size()-(oldSize-actualBegin),
                                &*m_container.begin()+actualBegin,count* sizeof (T));
                        //std::_Move(m_container.begin()+actualBegin,m_container.begin()+oldSize
                        //	,m_container.begin()+m_container.size()-(oldSize-actualBegin));
                    }
                    m_beginPos = m_container.size()-(oldSize-actualBegin);
                    m_endPos = m_container.size()+actualBegin;
                }
            }
            if (havespace())
            {
                get_ref(m_endPos)=obj;
                m_endPos++;
                if (m_endPos == max_size())
                {
                    size_t curSize = size();
                    m_beginPos = get_actual_pos(m_beginPos);
                    m_endPos = m_beginPos+curSize;
                }
            }
        }
        void reserve(size_t s)
        {
            m_container.resize(s);
        }
        size_t max_size(void)
        {
            return (size_t)-1;
        }
        size_t capacity(void)
        {
            return m_container.capacity();
        }
    protected:
        T& get_ref(size_t pos)
        {
            return m_container[pos%m_container.size()];
        }
        bool havespace(void)
        {
            return size()<m_container.size();
        }
        size_t get_actual_pos(size_t pos)
        {
            return pos%m_container.size();
        }
        //!有效数据起始位置
        size_t m_beginPos;
        //!有效数据结束位置,
        size_t m_endPos;
        std::vector<T> m_container;
    };
}

#endif

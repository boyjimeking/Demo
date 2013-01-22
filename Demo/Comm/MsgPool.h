//
//  MsgPool.h
//
//
//  Created by xiangyu on 12-12-20.
//  Copyright (c) 2012年 xiangyu. All rights reserved.
//



///这个池子是专为发送和接受队列提供的内存池
///基于原理: 进入池子中的消息, 很快就会被取走
///此池在线程非安全的情况下申请和释放内存很快, 接近malloc 30 - 40倍, 特别在申请较大内存的情况(几十K)
///此池是线程不安全的.

namespace Net
{
    template<size_t BlockSize>
    class MsgPoolA
    {
    private:
        struct _MemBlock
        {
            _MemBlock()
			:next(0),pos(BlockSize),freePos(BlockSize)
            {
            }
            _MemBlock*	next;
            //!剩余空间
            size_t		pos;
            //!释放剩余
            size_t		freePos;
            //!是否已经空了
            bool empty(void)
            {
                return freePos<=pos;
            }
            char		buffer[BlockSize];
            
            void reset()
            {
                next=0;
                pos=freePos = BlockSize;
            }
        };
        
        _MemBlock*	_first;
        _MemBlock*	_last;
    public:
        size_t		BlockCount;
        MsgPoolA()
        {
            _first = _last = new _MemBlock;
            BlockCount = 1;
        }
        
        void* alloc(size_t cb)
        {
            if (_last->pos < cb)
            {
                _MemBlock* newBlock=0;
                
                //清除不使用的block
                _MemBlock* block = _first;
                while (block !=0 && block->freePos <= block->pos)
                {
                    _MemBlock* next = block->next;
                    if (BlockCount<=2)
                    {
                        newBlock=block;
                        block=next;
                        break;
                    }
                    
                    if (newBlock==0)
                    {
                        newBlock = block; //留着继续用, 不释放
                    }
                    else
                    {
                        delete block;
                        --BlockCount;
                    }
                    
                    block = next;
                }
                //从链表中找出一个空的
                if (newBlock == 0)
                {
                    _MemBlock* emptyBlock = _first;
                    _MemBlock* prevBlock = _first;
                    while (emptyBlock && !emptyBlock->empty())
                    {
                        prevBlock = emptyBlock;
                        emptyBlock = emptyBlock->next;
                    }
                    if (prevBlock && emptyBlock && prevBlock != emptyBlock)
                    {//将emptyBlock从列表中移除
                        prevBlock->next = emptyBlock->next;
                        emptyBlock->next = 0;
                        newBlock = emptyBlock;
                    }
                }
                if (newBlock == 0)
                {
                    //还是new一个吧
                    newBlock = new _MemBlock;
                    ++BlockCount;
                }
                else
                {
                    newBlock->reset();
                }
                
                
                if (block == 0)
                {
                    _first = _last = newBlock;
                }
                else
                {//此时,block是第一个非空的,block之前的都已经被释放或者变成了newBlock.
                    _first = block;
                    _last->next = newBlock;
                    _last = newBlock;
                }
            }
            
            return (_last->buffer) + (_last->pos -= cb);
        }
        
        //不要重复free, 需要设定alloc的尺寸
        void free(void *p, size_t cb)
        {
            _MemBlock* block = _first;
            //一般来说释放总是从后面开始
            do
            {
                if ( block->buffer<=(char*)p
                    && (char*)p<(char*)block+sizeof(_MemBlock))
                {
                    if (block->freePos>cb)
                    {
                        block->freePos -= cb;
                    }
                    else
                    {
                        block->freePos=0;
                    }
                    
                    return;
                }
            } while((block = block->next) != 0);
        }
    };
    
    typedef MsgPoolA<4 * 1024 * 1024> MsgPool; //实测4M的Buff比较合适
    
    
    //////////////////////////////////////////////////////////////////////////
    ///线程安全的MsgPool
    ///这个类和MsgPool除了使用锁以外完全一样
    ///本类在分配大于1K的内存比malloc和free非常有优势
    ///可以同时分配和释放
    template<size_t BlockSize,typename TFastMutex> class MsgPoolA_Safe
    {
    private:
        struct _MemBlock
        {
            _MemBlock()
			:next(0)
			,pos(BlockSize),
			freePos(BlockSize)
            {
            }
            _MemBlock* next;
            size_t pos;
            size_t freePos;
            char buffer[BlockSize];
            //!是否已经空了
            bool empty(void)
            {
                return freePos<=pos;
            }
            
            void reset()
            {
                next = 0;
                pos = freePos = BlockSize;
            }
        };
        
        _MemBlock* _first;
        _MemBlock* _last;
        TFastMutex _allocMutex;
        TFastMutex _freeMutex;
    public:
        typedef typename TFastMutex::scope_lock scope_lock;
        size_t BlockCount;
        MsgPoolA_Safe()
        {
            _first = _last = new _MemBlock;
            BlockCount = 1;
        }
        
        void* alloc(size_t cb)
        {
            scope_lock scopelock(_allocMutex);
            if (_last->pos < cb)
            {
                scope_lock scopelock(_freeMutex);
                _MemBlock* newBlock = 0;
                
                //清除不使用的block
                _MemBlock* block = _first;
                while ( block
                       && block->freePos <= block->pos)
                {
                    _MemBlock* next = block->next;
                    if (BlockCount<=2)
                    {
                        newBlock = block;
                        block = next;
                        break;
                    }
                    
                    if (newBlock==0)
                    {
                        newBlock = block; //留着继续用, 不释放
                    }
                    else
                    {
                        delete block;
                        --BlockCount;
                    }
                    
                    block = next;
                }
                //从链表中找出一个空的 add by tgame 2010-9-19
                if (newBlock == 0)
                {
                    _MemBlock* emptyBlock = _first;
                    _MemBlock* prevBlock = _first;
                    while (emptyBlock && !emptyBlock->empty())
                    {
                        prevBlock = emptyBlock;
                        emptyBlock = emptyBlock->next;
                    }
                    if (prevBlock && emptyBlock && prevBlock != emptyBlock)
                    {//将emptyBlock从列表中移除
                        prevBlock->next = emptyBlock->next;
                        emptyBlock->next = 0;
                        newBlock = emptyBlock;
                        if (_last == emptyBlock)
                        {
                            _last = prevBlock;
                        }
                    }
                }
                //////////////////////////////////////////////////////////////////////////
                if (newBlock == 0)
                {
                    //还是new一个吧
                    newBlock = new _MemBlock;
                    ++BlockCount;
                }
                else
                {
                    newBlock->reset();
                }
                
                if (block == 0)
                {
                    _first = _last = newBlock;
                }
                else
                {
                    _first = block;
                    _last = _last->next = newBlock;
                }
            }
            
            
            return (_last->buffer) + (_last->pos -= cb);
        }
        
        //不要重复free, 需要设定alloc的尺寸
        void free(void*p, size_t cb)
        {
            scope_lock scopelock(_freeMutex);
            _MemBlock* block = _first;
            //一般来说释放总是从后面开始
            while (block)
            {
                if ( block->buffer<=(char*)p
                    && (char*)p<(char*)block+sizeof(_MemBlock) )
                {
                    if (block->freePos>cb)
                    {
                        block->freePos-=cb;
                    }
                    else
                    {
                        block->freePos=0;
                    }
                    
                    return;
                }
                
                block=block->next;
            }
            int i=0;
            i++;
            
        }
    };
}

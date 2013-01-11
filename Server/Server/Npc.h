//
//  Npc.h
//  Server
//
//  Created by xiangyu on 13-1-7.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__Npc__
#define __Server__Npc__

#include <map>
#include "../../Demo/Comm/CommDef.h"
#include "IUnit.h"
#include "../../Demo/Comm/NetMessage.h"

class AIControl;

class CNpc: public IUnit{
public:
    typedef std::map<u32, CNpc*> TNpcMap;
    CNpc(u32 id);
    virtual ~CNpc();
    
    static CNpc* CreateObj(u32 id);
    static CNpc* FindNpc(u32 id);
    static void InitAll();
    
    static void SysAll(void)//xxxxxx
    {
        TNpcMap::iterator it = m_npcMap.begin();
        while(it != m_npcMap.end())
        {
            it->second->SycInfo();
            ++it;
        }
    }
    
    bool Init(void);
    virtual bool IsNpc(void) const { return true; }
    void SycInfo( void );
    static void UpdateAll(u32 elps);
    void Update(u32 elps);
    
    //被打
    virtual void BeAttacked(int targetID);
    //死亡
    virtual void Dead(void);
    
    int GetTarget(void) const { return m_target; }
    void SetTarget(int val) { m_target = val; }
    AIControl * GetControl(void) const { return m_control; }
    
public:
    static u32 m_nIdGenerator;
    AIControl *m_control;
private:
    static TNpcMap m_npcMap;

    int m_target;
};

#endif /* defined(__Server__Npc__) */

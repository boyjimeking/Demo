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
#include "SOBIUnit.h"
#include "../../Demo/Comm/NetMessage.h"
#include "ObjectType.h"

class AIControl;
class CPlayer;

class CNpc: public IUnit{
public:
    typedef std::map<u32, CNpc*> TNpcMap;
    CNpc();
    virtual ~CNpc();
    
    virtual ENObjectType GetType() const { return ENObjectType::enCNpc; }
    virtual bool IsKindof(ENObjectType type) const { return ENObjectType::enCNpc == type; }
    static CNpc* FindNpc(u32 id);
    static void SycAll(CPlayer *player);
    
    bool Init(void);
    virtual bool IsNpc(void) const { return true; }
    void SycInfo( CPlayer *player );
    static void UpdateAll(u32 elps);
    void Update(u32 elps);
    
    //被打
    virtual void BeAttacked(int targetID);
    //死亡
    virtual void Dead(void);
    
    int GetTarget(void) const { return m_target; }
    void SetTarget(int val) { m_target = val; }
    AIControl * GetControl(void) const { return m_control; }
    void AddObservers() { m_observers.insert(GetID());}
    void AddNpcMap() { m_npcMap[GetID()] = this;}
    
public:
    AIControl *m_control;
private:
    static TNpcMap m_npcMap;

    int m_target;
};

#endif /* defined(__Server__Npc__) */

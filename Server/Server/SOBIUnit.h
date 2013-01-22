//
//  IUnit.h
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__IUnit__
#define __Server__IUnit__

#include <map>
#include <set>
#include "../../Demo/Comm/NetMessage.h"
#include "../../Demo/Comm/CommDef.h"
#include "ISimulateObject.h"

class IUnit: public ISimulateObject{
public:
    typedef std::set<uint> TObserversSet;
    
    IUnit();
    virtual ~IUnit();
    
    //unit type
    virtual bool IsPlayer(void) const { return false; }
    virtual bool IsNpc(void) const { return false; }
    virtual bool IsPet(void) const { return false; }
    virtual bool IsVehicle(void) const { return false; }
    
    virtual void BoardcastMsg(NetMessage &msg, u32 ownerid = 0);
    virtual void SycInfo(void);
    
    //向客户端同步位置
    virtual void SycPosition(void);
    //攻击
    virtual void Attack(int targetID);
    //同步战斗属性信息
    void SycBattleInfo(void);
    //被打
    virtual void BeAttacked(int targetID);
    //死亡
    virtual void Dead(void);
    
    float GetX(void) const { return m_x; }
    float GetY(void) const { return m_y; }
    
    void SetX(float x) { m_x = x; }
    void SetY(float y) { m_y = y; }

protected:
    //observers
    TObserversSet m_observers;
    PlayerBattleInfo m_battleInfo;
    
private:

    //position
    float m_x;
    float m_y;

};

#endif /* defined(__Server__IUnit__) */

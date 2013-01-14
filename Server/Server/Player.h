//
//  Player.h
//  Server
//
//  Created by xiangyu on 13-1-6.
//  Copyright (c) 2013年 xiangyu. All rights reserved.
//

#ifndef __Server__Player__
#define __Server__Player__

#include <map>
#include "IUnit.h"
#include "../../Demo/Comm/CommDef.h"
#include "../../Demo/Comm/NetMessage.h"
#include "GameAccount.h"

class CPlayer: public IUnit{
public:
    typedef std::map<u32, CPlayer*> TPlayerMap;
    
    CPlayer(u32 id, CGameAccount* pAccount);
    virtual ~CPlayer(void);
    
    static CPlayer * CreateObj(u32 id, CGameAccount* pAccount);
    static CPlayer * FindPlayer(u32 id);
    
    bool Init(void);
    virtual bool IsPlayer(void) const { return true; }
    void SendToClient(NetMessage& msg) { m_pAccount->SendToClient(msg);}
    static void UpdateAll(u32 elps);
    void Update(u32 elps);
    virtual void SycInfo( void );
    //更换装备
    void ChangeEquip(void);
    void AttackTarget_C2S(NetMessage *pMsg);
    
    static u32 m_nIdGenerator;
    
protected:
    
    
private:

    static TPlayerMap m_playerMap;
    CGameAccount* m_pAccount;
    PlayerBattleInfo m_battleInfo;
};

#endif /* defined(__Server__Player__) */

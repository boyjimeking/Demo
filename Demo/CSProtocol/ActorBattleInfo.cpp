#include "ActorBattleInfo.h"
#include "../Tools/StreamHelper.h"

ActorBattleInfo::ActorBattleInfo(void)
	:m_dirtyMark(0)
	,m_isAlive(true)
	,m_HP(5)
	,m_maxHP(5)
{
	
}

ActorBattleInfo::~ActorBattleInfo(void)
{
	
}

void ActorBattleInfo::Read( StreamHelper *stream )
{
	stream->Read(m_isAlive);
	stream->Read(m_HP);
	stream->Read(m_maxHP);
}

void ActorBattleInfo::Write( StreamHelper *stream )
{
	stream->Write(m_isAlive);
	stream->Write(m_HP);
	stream->Write(m_maxHP);
}

void ActorBattleInfo::SetHP( int hp )
{
	m_HP = hp;
	SetDirty(ENBattlePropType::enHP);
}

void ActorBattleInfo::SetDirty( ENBattlePropType::Decl type )
{
	m_dirtyMark |= type;
}

bool ActorBattleInfo::GetDirty( ENBattlePropType::Decl type ) const
{
	return 0 != (m_dirtyMark & type);
}

void ActorBattleInfo::SetAlive( bool isAlive )
{
	m_isAlive = isAlive;
	SetDirty(ENBattlePropType::enAlive);
}

void ActorBattleInfo::SetMaxHP( int val )
{
	m_maxHP = val;
	SetDirty(ENBattlePropType::enMaxHp);
}

//////////////////////////////////////////////////////////////////////////
//
//	file path:	CSProtocol
//	created:	2012-12-26
//	author:		Mingzhen Zhang
//
//////////////////////////////////////////////////////////////////////////
#ifndef ActorBattleInfo_h__
#define ActorBattleInfo_h__

namespace Tools
{
	class StreamHelper;
}

struct ENBattlePropType 
{
	enum Decl
	{
		enError = -1,
		enHP = 1 << 0,
		enAlive = 1 << 1,
	};
};

class ActorBattleInfo
{
public:
	ActorBattleInfo(void);
	virtual ~ActorBattleInfo(void);

	void Read(Tools::StreamHelper *stream);
	void Write(Tools::StreamHelper *stream);

	//Hp
	int GetHP(void) const { return m_HP; }
	void SetHP(int hp);
	//是否存活
	bool IsAlive(void) const { return m_isAlive; }
	void SetAlive(bool isAlive);
protected:
	void SetDirty(ENBattlePropType::Decl type);
	bool GetDirty(ENBattlePropType::Decl type) const;
	bool IsDirty(void) const { return 0 == m_dirtyMark; }
	void ResetDirty(void) { m_dirtyMark = 0; }
private:
	int m_dirtyMark;
	//生命
	int m_HP;
	//是否存活
	bool m_isAlive;
};

#endif // ActorBattleInfo_h__

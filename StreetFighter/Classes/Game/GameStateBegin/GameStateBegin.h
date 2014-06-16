#ifndef __GAME_STATE_BEGIN_H__
#define __GAME_STATE_BEGIN_H__
#include "../GameStateBase.h"
class CGameStateBegin:public CGameStateBase
{    
public:
	CGameStateBegin ();
	virtual ~CGameStateBegin(){}
	virtual bool OnEnterState(){ return true;};
	virtual bool OnLeaveState(){ return true;};
private:
	int m_iType;
};

#endif // __GAME_STATE_BEGIN_H__

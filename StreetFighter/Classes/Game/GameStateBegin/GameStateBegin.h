#ifndef __GAME_STATE_BEGIN_H__
#define __GAME_STATE_BEGIN_H__
#include "../GameStateBase.h"
#include "2d/CCScene.h"
class CBeginUI;
class CGameStateBegin:public CGameStateBase
{    
public:
	CGameStateBegin ();
	virtual ~CGameStateBegin(){}
	virtual bool init();
	virtual bool OnEnterState();
	virtual bool OnLeaveState();
	cocos2d::Scene* GetScene() { return m_pBeginScene;}
	CREATE_FUNC(CGameStateBegin);
private:
	int m_iType;
	cocos2d::Scene* m_pBeginScene;
	CBeginUI* m_pBeginUI;
};

#endif // __GAME_STATE_BEGIN_H__

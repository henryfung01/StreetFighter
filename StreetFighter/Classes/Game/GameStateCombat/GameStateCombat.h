#ifndef __GAME_STATE_COMBAT_H__
#define __GAME_STATE_COMBAT_H__
#include "../BaseClass/GameStateBase.h"
class CCombatController;
class CCombatUI;
class CCombatScene;
class CGameStateCombat:public CGameStateBase
{    
public:
	CGameStateCombat ();
	virtual ~CGameStateCombat(){}
	//create cocos resource
	virtual bool OnEnterState();
	//destroy cocos resource
	virtual bool OnLeaveState(){ return true;}
	//this is the initialize of classes without cocos resource
	virtual bool init();
	CREATE_FUNC(CGameStateCombat);
public: 
	CCombatController* GetController() { return m_pCombatController;}
	CCombatUI* GetUI() { return m_pCombatUI;}
	CCombatScene* GetScene() { return m_pCombatScene;}
	virtual void OnLoadingComplete();
private:
	CCombatController* m_pCombatController;
	CCombatUI* m_pCombatUI;
	CCombatScene* m_pCombatScene;
};

#endif // __GAME_STATE_COMBAT_H__

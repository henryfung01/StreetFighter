/*game state machine manager */
#ifndef __GAME_STATE_MANAGER_H__
#define __GAME_STATE_MANAGER_H__
#include <vector>
class CGameStateBase;
typedef std::vector<CGameStateBase*> GameStateVec;
class CGameStateManager
{    
public:
	CGameStateManager();
	void Init();
	static CGameStateManager* Create();
	virtual ~CGameStateManager();
	virtual void GotoGameState(int gameState);
	CGameStateBase* GetGameState(int gameState);
	//this function will call pGameState->Retain(),so,the refcount should be zero
	virtual bool RegisterGameState(int gameStateType,CGameStateBase* pGameState);
private:
	inline bool _CheckTypeValid(int gameStateType);
	int m_iCurrentType;
	GameStateVec m_allGameStates;
};

#endif // __GAME_STATE_MANAGER_H__

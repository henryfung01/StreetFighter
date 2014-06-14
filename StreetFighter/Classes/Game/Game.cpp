#include "Game.h"
#include "GameStateManager.h"
CGame* CGame::pStaticGame = nullptr;
CGame* CGame::GetInstance()
{
	if(!pStaticGame)
	{
		pStaticGame = new CGame();
		pStaticGame->Init();
	}
	return pStaticGame;
}

bool CGame::Init()
{
	m_pGameStateManager = CGameStateManager::Create();
	if(m_pGameStateManager)
		return true;
	return false;
}

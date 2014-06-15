#include "GameStateManager.h"
#include "../Common/CommonDef.h"
#include "GameStateBase.h"
CGameStateManager::CGameStateManager()
{
	m_iCurrentType = GameStateType_None;
}

CGameStateManager* CGameStateManager::Create()
{
	CGameStateManager* pManager = new CGameStateManager();
	pManager->Init();
	return pManager;
}

void CGameStateManager::Init()
{
	m_allGameStates.resize(GameStateType_Count);
	for(unsigned i=0;i<m_allGameStates.size();++i)
	{
		m_allGameStates[i] = nullptr;
	}
}

bool CGameStateManager::RegisterGameState( int gameStateType,CGameStateBase* pGameState )
{
	if(_CheckTypeValid(gameStateType) && pGameState)
	{
		if(m_allGameStates[gameStateType])
		{
			//not use delete but call release function
			//this can support the pGameState point from another module such as a DLL
			m_allGameStates[gameStateType]->release();
			//ref ++,the ref should be 0
			pGameState->retain();
			m_allGameStates[gameStateType] = pGameState;
			return true;
		}
	}
	return false;
}

bool CGameStateManager::_CheckTypeValid( int gameStateType )
{
	return gameStateType >= GameStateType_Begin && gameStateType < GameStateType_Count;
}

CGameStateManager::~CGameStateManager()
{
	//release all the game state object
	for(unsigned i=0;i<m_allGameStates.size();++i)
	{
		if(m_allGameStates[i])
		{
			m_allGameStates[i]->release();
			m_allGameStates[i] = nullptr;
		}
	}
}

void CGameStateManager::GotoGameState( int gameState )
{
	if(_CheckTypeValid(gameState) && m_iCurrentType != gameState && m_allGameStates[gameState])
	{
		if(m_iCurrentType != GameStateType_None)
		{
			m_allGameStates[m_iCurrentType]->OnLeaveState();
		}
		m_allGameStates[gameState]->OnEnterState();
		m_iCurrentType = gameState;
	}
}

CGameStateBase* CGameStateManager::GetGameState( int gameState )
{
	if(_CheckTypeValid(gameState))
	{
		return m_allGameStates[gameState];
	}
	return nullptr;
}

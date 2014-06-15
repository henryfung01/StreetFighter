#include "GameStateCombat.h"
#include "../../Common/CommonDef.h"
#include "Controller/CombatController.h"
CGameStateCombat::CGameStateCombat():
m_pCombatUI(nullptr),
m_pCombatScene(nullptr),
m_pCombatController(nullptr)
{
	m_iType = GameStateType_Combat;
}

bool CGameStateCombat::init()
{
	m_pCombatController = new CCombatController();
	return true;
}

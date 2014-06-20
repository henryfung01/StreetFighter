#include "GameStateCombat.h"
#include "Common/CommonDef.h"
#include "Controller/CombatController.h"
#include "Game/Game.h"
#include "CCTransition.h"
#include "Game/LoadingScene.h"
USING_NS_CC;
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

bool CGameStateCombat::OnEnterState()
{
	CLoadingScene* loadingScene = CGame::GetInstance()->GetLoadingScene();
	auto* fadeScene = TransitionCrossFade::create(1.0, loadingScene);
	Director::getInstance()->replaceScene(fadeScene);
	return true;
}

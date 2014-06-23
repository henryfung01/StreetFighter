#include "GameStateCombat.h"
#include "Common/CommonDef.h"
#include "Controller/CombatController.h"
#include "Scene/CombatScene.h"
#include "UI/CombatUI.h"
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
	m_pCombatController = CCombatController::create();
	m_pCombatController->retain();
	return true;
}

bool CGameStateCombat::OnEnterState()
{
	CLoadingScene* loadingScene = CGame::GetInstance()->GetLoadingScene();
	auto* fadeScene = TransitionCrossFade::create(1.0, loadingScene);
	Director::getInstance()->replaceScene(fadeScene);
	return true;
}

void CGameStateCombat::OnLoadingComplete()
{
	m_pCombatScene = CCombatScene::create(false);
	m_pCombatScene->retain();
	m_pCombatUI = CCombatUI::create();
	m_pCombatUI->retain();
	Director::getInstance()->setDepthTest(true);
	Director::getInstance()->replaceScene(TransitionPageTurn::create(1.5f, m_pCombatScene, false));
}

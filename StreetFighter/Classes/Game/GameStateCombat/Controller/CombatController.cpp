#include "SpecialTouchHandler.h"
#include "CombatController.h"
USING_NS_CC;
#include "Recognizer/GeometricRecognizer.h"
#include "Common/CommonDef.h"
#include "../Scene/CombatScene.h"
#include "../UI/CombatUI.h"
#include "../GameStateCombat.h"
#include "Game/Game.h"
using namespace ui;
using namespace DollarRecognizer;
void CCombatController::OnSpecialTouchEvent(Ref *pSender, TouchEventType type)
{
	m_SpTouchHandler.OnTouchEvent(pSender,type);
}

CCombatController::CCombatController():
m_SpTouchHandler(this)
{

}

CCombatController::~CCombatController()
{

}

bool CCombatController::init()
{
	m_SpTouchHandler.Init();
	return true;
}

void CCombatController::OnSpecialInput( const char* input )
{
	CGameStateCombat* pState = _GetCombatState();
	if(pState)
	{
		pState->GetUI()->SetStatusLabel(input);
	}
}

CGameStateCombat* CCombatController::_GetCombatState()
{
	CGameStateBase* pState = CGame::GetInstance()->GetGameState(GameStateType_Combat);
	return static_cast<CGameStateCombat*>(pState);
}


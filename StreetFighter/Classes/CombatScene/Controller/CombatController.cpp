#include "SpecialTouchHandler.h"
#include "CombatController.h"
USING_NS_CC;
#include "Recognizer/GeometricRecognizer.h"
#include "../../Common/CommonDef.h"
#include "../CombatScene.h"
#include "../View/CombatView.h"
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
	CCombatScene* pScene = _GetCombatScene();
	if(pScene)
	{
		pScene->GetView()->SetStatusLabel(input);
	}
}

CCombatScene* CCombatController::_GetCombatScene()
{
	Scene* pOwner = getScene();
	//确保是一个combat scene
	if(pOwner && pOwner->getTag() == SceneType_Combat)
	{
		return static_cast<CCombatScene*>(pOwner);
	}
	return nullptr;
}

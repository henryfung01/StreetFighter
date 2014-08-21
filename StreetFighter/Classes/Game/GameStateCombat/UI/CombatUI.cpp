#include "CombatUI.h"
#include "Common/CommonDef.h"
#include "../Controller/CombatController.h"
#include "../Scene/CombatScene.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "CombatUINames.h"
#include "SuperAttackDisplayer.h"
#include "../CombatCommonDefine.h"
#include "Game/Game.h"
#include "Game/GameStateManager.h"
#include "../GameStateCombat.h"
#include "CombatMenu.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool CCombatUI::init()
{
	_CreateUI();
	return true;
}


void CCombatUI::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
CGameStateCombat* CCombatUI::_GetCombatState()
{
	CGameStateBase* pState = CGame::GetInstance()->GetGameState(GameStateType_Combat);
	return static_cast<CGameStateCombat*>(pState);
}
void CCombatUI::OnTouchEvent(Ref *pSender, TouchEventType type)
{
	CCombatController* pCombatController = _GetCombatState()->GetController();
	pCombatController->OnSpecialTouchEvent(pSender,type);
}

void CCombatUI::_CreateUI()
{
	//add ui to ui layer
	_GetGameScene()->AddUINode(this);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	Layout*  _widget = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("UI/CombatUI/CombatUI_1.ExportJson"));
	if(_widget)
	{
		addChild(_widget);
	}
	//获得这些控件然后注册事件回调等操作
	Widget* pWidget = GetChildByNameRecursive(SpecialTouchArea,3);
	if(pWidget)
	{
		pWidget->setTouchEnabled(true);
		pWidget->addTouchEventListener(this, toucheventselector(CCombatUI::OnTouchEvent));
	}
	pWidget = GetChildByNameRecursive(ResultDisplay,3);
	if(pWidget)
	{
		std::string description = pWidget->getDescription();
		if(description == "Label") //is real a text
		{
			m_pStatusLabel = static_cast<Text*>(pWidget);
		}
	}
    m_pSuperAttackDisplayer = CSuperAttackDisplayer::create();
	const Size& winSize = Director::getInstance()->getWinSize();
	m_pSuperAttackDisplayer->setPosition(winSize.width/2,winSize.height/2);
	addChild(m_pSuperAttackDisplayer);
	m_pSuperAttackDisplayer->PostInit();
	m_pCombatMenu = CCombatMenu::create();
	m_pCombatMenu->retain();
	addChild(m_pCombatMenu);
	
}

void CCombatUI::SetStatusLabel( const char* status )
{
	if(status && m_pStatusLabel)
	{
		m_pStatusLabel->setText(status);
	}
}

void CCombatUI::SetDrawGestureType( int gestureType )
{
	m_iGestureType = gestureType;
	if(m_iGestureType == QTEGestureType_None)
	{
		m_pSuperAttackDisplayer->setVisible(false);
	}
	else
	{
		m_pSuperAttackDisplayer->setVisible(true);
		m_pSuperAttackDisplayer->SetDrawPath(_GetCombatState()->GetController()->GetGesturePath(m_iGestureType));
	}
}

CCombatUI::CCombatUI():
m_pStatusLabel(nullptr),
m_pCombatMenu(nullptr),
m_pSuperAttackDisplayer(nullptr)
{

}

CGameScene* CCombatUI::_GetGameScene()
{
	CGameStateBase* gameState = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
	CGameScene* pGameScene = gameState->GetGameScene();
	return pGameScene;
}

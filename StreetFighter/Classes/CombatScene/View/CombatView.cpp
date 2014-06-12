#include "CombatView.h"
#include "../../Common/CommonDef.h"
#include "../Controller/CombatController.h"
#include "../CombatScene.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "CombatViewNames.h"
#include "SuperAttackDisplayer.h"
#include "../CombatCommonDefine.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool CCombatView::init()
{
	return true;
}


void CCombatView::menuCloseCallback(Ref* pSender)
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
CCombatScene* CCombatView::_GetCombatScene()
{
	Scene* pOwner = getScene();
	//确保是一个combat scene
	if(pOwner && pOwner->getTag() == SceneType_Combat)
	{
		return static_cast<CCombatScene*>(pOwner);
	}
	return nullptr;
}
void CCombatView::OnTouchEvent(Ref *pSender, TouchEventType type)
{
	CCombatScene* combatScene = _GetCombatScene();
	if(combatScene)
	{
		CCombatController* pCombatController = combatScene->GetController();
		pCombatController->OnSpecialTouchEvent(pSender,type);
	}
}

void CCombatView::CreateUILayer()
{
	//因为在addchild内部会retain，所以m_pUILayer不用管引用计数
	m_pUILayer = Layer::create();
	Scene* ownerScene = getScene();
	ownerScene->addChild(m_pUILayer);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
	Layout*  _widget = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("UI/CombatUI/CombatUI_1.ExportJson"));
	if(_widget)
	{
		m_pUILayer->addChild(_widget);
	}
	//获得这些控件然后注册事件回调等操作
	Widget* pWidget = GetChildByNameRecursive(SpecialTouchArea,3);
	if(pWidget)
	{
		pWidget->setTouchEnabled(true);
		pWidget->addTouchEventListener(this, toucheventselector(CCombatView::OnTouchEvent));
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
	m_pUILayer->addChild(m_pSuperAttackDisplayer);
	m_pSuperAttackDisplayer->PostInit();
}

void CCombatView::SetStatusLabel( const char* status )
{
	if(status && m_pStatusLabel)
	{
		m_pStatusLabel->setText(status);
	}
}

void CCombatView::SetDrawGestureType( int gestureType )
{
	m_iGestureType = gestureType;
	if(m_iGestureType == QTEGestureType_None)
	{
		m_pSuperAttackDisplayer->setVisible(false);
	}
	else
	{
		m_pSuperAttackDisplayer->setVisible(true);
		m_pSuperAttackDisplayer->SetDrawPath(_GetCombatScene()->GetController()->GetGesturePath(m_iGestureType));
	}
}

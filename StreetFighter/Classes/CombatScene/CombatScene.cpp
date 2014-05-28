#include "CombatScene.h"
#include "View\CombatView.h"
#include "Controller\CombatController.h"
USING_NS_CC;
#include "../Common/CommonDef.h"
cocos2d::Scene* CCombatScene::create(bool usePhysics)
{
	CCombatScene* combatScene = NULL;
	if(usePhysics)
	{
		combatScene = new CCombatScene();
		if (combatScene && combatScene->initWithPhysics())
		{
			 combatScene->autorelease();
		}
		else
		{
			CC_SAFE_DELETE(combatScene);
			return nullptr;
		}
	}
	else
	{
		combatScene = CCombatScene::create();
	}
	if(combatScene)
	{
		combatScene->_InitCombatScene();
		return combatScene;
	}
	return NULL;
}
void CCombatScene::_InitCombatScene()
{
	setTag(SceneType_Combat);
	m_pCombatView = CCombatView::create();
	addChild(m_pCombatView);
	m_pCombatView->CreateUILayer();
	m_pCombatController = CCombatController::create();
	addChild(m_pCombatController);
}
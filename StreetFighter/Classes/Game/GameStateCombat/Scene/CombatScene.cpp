#include "CombatScene.h"
#include "../UI/CombatUI.h"
#include "../Controller/CombatController.h"
USING_NS_CC;
#include "Common/CommonDef.h"
CCombatScene* CCombatScene::create(bool usePhysics)
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
}
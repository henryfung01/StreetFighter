#include "CombatScene.h"
#include "../UI/CombatUI.h"
#include "../Controller/CombatController.h"
USING_NS_CC;
#include "Common/CommonDef.h"
#include "CCTMXTiledMap.h"
CCombatScene* CCombatScene::create(bool usePhysics)
{
	CCombatScene* combatScene = NULL;
	if(usePhysics)
	{
		combatScene = new CCombatScene();
		if (combatScene && combatScene->initWithPhysics())
		{
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
		combatScene->autorelease();
		return combatScene;
	}
	return NULL;
}
void CCombatScene::_InitCombatScene()
{
	setTag(SceneType_Combat);
	m_map = TMXTiledMap::create("Levels/Level1/level1.tmx");
	m_map->retain();
	addChild(m_map);
}

CCombatScene::CCombatScene()
{
	m_map = nullptr;
}

#include "CombatScene.h"
#include "../UI/CombatUI.h"
#include "../Controller/CombatController.h"
USING_NS_CC;
using namespace cocostudio;
#include "Common/CommonDef.h"
#include "CCTMXTiledMap.h"
#include "Game/Actor/Player.h"
#include "SceneTouchLayer.h"
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

	//spawn player
	m_pPlayer = CPlayer::create();
	m_pPlayer->retain();
	Node* pRenderObj = m_pPlayer->GetenderNode();
	if(pRenderObj)
	{
		m_map->addChild(pRenderObj);
	}
	addChild(CSceneInputLayer::create());
}

CCombatScene::CCombatScene()
{
	m_map = nullptr;
	m_pPlayer = nullptr;
}

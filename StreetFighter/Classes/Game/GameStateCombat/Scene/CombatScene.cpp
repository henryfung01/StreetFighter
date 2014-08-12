#include "CombatScene.h"
#include "../UI/CombatUI.h"
#include "../Controller/CombatController.h"
USING_NS_CC;
using namespace cocostudio;
#include "Common/CommonDef.h"
#include "CCTMXTiledMap.h"
#include "Game/Actor/Player.h"
#include "SceneTouchLayer.h"
#include "CombatArea.h"
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
	return combatScene;
}
void CCombatScene::_InitCombatScene()
{
	setTag(SceneType_Combat);
	m_map = TMXTiledMap::create("Levels/Level02/OceanCity.tmx");
	m_map->retain();
	addChild(m_map);
	//create entity layer
	m_EntityLayer = Layer::create();
	m_EntityLayer->retain();
	m_map->addChild(m_EntityLayer);
	m_EntityLayer->setLocalZOrder(1);

	//spawn player
	m_pPlayer = CPlayer::create();
	m_pPlayer->retain();
	m_pCombatArea = new CCombatArea();
	m_pCombatArea->Init(m_map);
	m_pPlayer->SetSize(EntityPos(2,1));
	m_pPlayer->SetGridPos(EntityPos(10,2));
	addChild(CSceneInputLayer::create());
}

CCombatScene::CCombatScene()
{
	m_map = nullptr;
	m_pPlayer = nullptr;
	m_pCombatArea = nullptr;
}

CCombatScene::~CCombatScene()
{
	SAFE_RELEASE(m_map);
	SAFE_RELEASE(m_EntityLayer);
	SAFE_RELEASE(m_pPlayer);
}

void CCombatScene::PostInit()
{
	_InitCombatScene();
}

CGridArea* CCombatScene::GetGridArea()
{
	return m_pCombatArea;
}

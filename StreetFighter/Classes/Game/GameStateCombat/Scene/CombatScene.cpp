#include "CombatScene.h"
#include "../UI/CombatUI.h"
#include "../Controller/CombatController.h"
USING_NS_CC;
using namespace cocostudio;
#include "CCTMXTiledMap.h"
#include "Game/Actor/Player.h"
#include "SceneTouchLayer.h"
#include "CombatArea.h"
#include "Game/Game.h"
#include "Game/BaseClass/EntitySystem.h"
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
	//init combat area
	m_pCombatArea = new CCombatArea();
	m_pCombatArea->Init(m_map);
	//spawn player
	CEntity* pEntity = CGame::GetInstance()->GetEntitySystem()->CreateEntity(EntityType_Player);

	pEntity->SetGridPos(EntityPos(10,2));
	MoveProcessReq req;
	req.pos = pEntity->GetGridPos();
	req.size = pEntity->GetSize();
	req.stepCount = 8;
	m_pCombatArea->ProcessMoveInfo(req);
	addChild(CSceneInputLayer::create());
}

CCombatScene::CCombatScene()
{
	m_map = nullptr;
	m_iPlayerId = Invalid_Id;
	m_pCombatArea = nullptr;
}

CCombatScene::~CCombatScene()
{
	SAFE_RELEASE(m_map);
	SAFE_RELEASE(m_EntityLayer);
	SAFE_RELEASE(m_pCombatArea);
}

void CCombatScene::PostInit()
{
	_InitCombatScene();
}

CGridArea* CCombatScene::GetGridArea()
{
	return m_pCombatArea;
}

void CCombatScene::OnTouchGrid( const EntityPos& pos )
{
	m_pCombatArea->SetCurTarget(pos);
}

void CCombatScene::AddRenderNode( cocos2d::Node* pNode )
{
	if(m_EntityLayer)
	{
		m_EntityLayer->addChild(pNode);
	}
}

#include "Actor.h"
#include "../components/Movement.h"
#include "Game/BaseClass/GameScene.h"
#include "Game/BaseClass/GridArea.h"
#include "Game/BaseClass/GameStateBase.h"
#include "Game/Game.h"
#include "Game/GameStateManager.h"
CActor::CActor():
m_pArmature(nullptr)
{

}

bool CActor::init()
{
	if(CEntity::init())
	{
		AddComponent(CMovement::create(this));
		return true;
	}
	return false;
}

void CActor::SetGridPos( const EntityPos& pos)
{
	CEntity::SetGridPos(pos);
	CGameStateBase * pSate = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
	CGridArea* pGridArea = pSate->GetGameScene()->GetGridArea();
	if(pGridArea)
	{
		cocos2d::Point renderPos = pGridArea->TransToRenderPos(m_vPosition,m_vSize);
		m_pArmature->setPosition(renderPos.x,renderPos.y);
	}
}

void CActor::GotoPos( const EntityPos& pos )
{
	CGameStateBase * pSate = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
	CGridArea* pGridArea = pSate->GetGameScene()->GetGridArea();
	if(pGridArea)
	{
		
	}
}

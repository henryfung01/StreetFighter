//cocos include
#include "cocostudio/CCArmature.h"
#include "cocostudio/CCArmatureDataManager.h"
using namespace cocostudio;
//game include
#include "Player.h"
#include "Game/Game.h"
#include "Game/GameStateManager.h"
#include "Game/BaseClass/GameStateBase.h"
#include "Game/BaseClass/GameScene.h"
CPlayer::CPlayer()
{

}

bool CPlayer::init()
{
	CActor::init();
	ArmatureDataManager::getInstance()->addArmatureFileInfo("animData/Player_Cat/Player_Cat.ExportJson");
	Armature *armature = nullptr;
	armature = Armature::create("Player_Cat");
	SetSize(EntityPos(2,1));
	if(armature)
	{
		m_pArmature = armature;
		m_pArmature->retain();
		m_pArmature->getAnimation()->play("idle");
		//通过设置这个参数可以让左右互换
		m_pArmature->setRotationSkewY(180.0f);
		CGameStateBase* gameState = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
		CGameScene* pGameScene = gameState->GetGameScene();
		pGameScene->GetEntityContainer()->addChild(m_pArmature);
		return true;
	}
	return false;
}

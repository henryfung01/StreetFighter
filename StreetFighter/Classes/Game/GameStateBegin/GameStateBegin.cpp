#include "GameStateBegin.h"
#include "Common/CommonDef.h"
#include "UI/BeginUI.h"
USING_NS_CC;
CGameStateBegin::CGameStateBegin()
{
	m_iType = GameStateType_Begin;
}

bool CGameStateBegin::OnEnterState()
{
	m_pBeginScene = Scene::create();
	//game state will save the point ,so increase the ref 1
	//when leave the state ,will release the scene
	m_pBeginScene->retain();
	//begin ui init function will add the object to the scene
	m_pBeginUI = CBeginUI::create();
	m_pBeginUI->retain();
	Director::getInstance()->runWithScene(m_pBeginScene);
	return true;
}

bool CGameStateBegin::init()
{
	m_pBeginScene = nullptr;
	m_pBeginUI = nullptr;
	return true;
}

bool CGameStateBegin::OnLeaveState()
{

}

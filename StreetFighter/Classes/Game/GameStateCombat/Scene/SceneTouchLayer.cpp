#include "SceneTouchLayer.h"
#include "CCEventListenerTouch.h"
#include "Game/Game.h"
#include "Game/GameStateManager.h"
#include "Common/GamePos.h"
#include "Common/CommonDef.h"
#include "Game/BaseClass/GameStateBase.h"
#include "CombatScene.h"
#include "Game/BaseClass/GridArea.h"

USING_NS_CC;
bool CSceneInputLayer::init()
{
	Layer::init();
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true);

	touchListener->onTouchBegan = CC_CALLBACK_2(CSceneInputLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(CSceneInputLayer::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(CSceneInputLayer::onTouchEnded, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(CSceneInputLayer::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	return true;
}

bool CSceneInputLayer::onTouchBegan( Touch* touch, Event* event )
{
	_ClearRecords();
	m_RecordPoints[m_iRecordCount++] = touch->getLocation();
	m_bRecording = true;
	return true;
}

void CSceneInputLayer::onTouchEnded( Touch* touch, Event* event )
{
	//小于3认为是一次触摸，取最后的点作为触摸点，防止手抖专用
	if(m_iRecordCount < 3)
	{
		CGameStateBase* pState = CGame::GetInstance()->GetGameStateManager()->GetGameState(GameStateType_Combat);
		CGameScene* pGameScene = pState->GetGameScene();
		//may be null
		if(pGameScene)
		{
			//用最后一个点作为目标点
			EntityPos touchGrid = pGameScene->GetGridArea()->TransToGridPos(m_RecordPoints[m_iRecordCount-1]);
			CCombatScene* pCombatScene = static_cast<CCombatScene*>(pGameScene);
			pCombatScene->OnTouchGrid(touchGrid);
		}
	}
	_ClearRecords();
	m_bRecording = false;
}

void CSceneInputLayer::onTouchCancelled( Touch* touch, Event* event )
{
	m_bRecording = false;
	_ClearRecords();
}

void CSceneInputLayer::onTouchMoved( Touch* touch, Event* event )
{
	if(m_bRecording)
	{
		m_RecordPoints[m_iRecordCount] = touch->getLocation();
		m_iRecordCount ++;
	}
}

CSceneInputLayer::CSceneInputLayer()
{

}

void CSceneInputLayer::_ClearRecords()
{
	m_iRecordCount = 0;
	memset(m_RecordPoints,0,sizeof(Point)*MAXRECORDPOINT);
}

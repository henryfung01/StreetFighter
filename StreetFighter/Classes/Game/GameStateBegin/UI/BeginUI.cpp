#include "BeginUI.h"
#include "Common/CommonDef.h"
#include "Game/Game.h"
#include "Game/GameStateManager.h"
#include "../GameStateBegin.h"
#include "CCLabel.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool CBeginUI::init()
{
	//create color layer
	m_colorLayer = LayerColor::create(Color4B(0, 0, 0, 255));
	//add to scene
	CGameStateBegin* pState = _GetState();
	pState->GetScene()->addChild(m_colorLayer);
	auto tintto = TintTo::create(2, 255,255,255);
	auto pCallback = CallFunc::create(CC_CALLBACK_0(CBeginUI::OnTintOver,this));
	auto pSequence = Sequence::create(tintto, pCallback, NULL);
	m_colorLayer->runAction(pSequence);
	return true;
}

CGameStateBegin* CBeginUI::_GetState()
{
	CGameStateBase* pState = CGame::GetInstance()->GetGameState(GameStateType_Begin);
	return static_cast<CGameStateBegin*>(pState);
}

void CBeginUI::OnTintOver()
{
	auto label1 = Label::createWithBMFont("fonts/futura-48.fnt","whitebai");
	m_colorLayer->addChild(label1);
	Size s = m_colorLayer->getContentSize();
	label1->setPosition(Point(-100, s.height/2));
	auto moveto = MoveTo::create(2,Point(s.width/2,s.height/2));
	auto pCallback = CallFunc::create(CC_CALLBACK_0(CBeginUI::OnNameFadeIn,this));
	auto pSequence = Sequence::create(moveto, pCallback, NULL);
	label1->runAction(pSequence);
}

void CBeginUI::OnNameFadeIn()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(CBeginUI::onTouchHappen, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, m_colorLayer);
}

bool CBeginUI::onTouchHappen( Touch *touch, Event *unused_event )
{
	//do nothing
	CGame::GetInstance()->GetGameStateManager()->GotoGameState(GameStateType_Combat);
	return true;
}


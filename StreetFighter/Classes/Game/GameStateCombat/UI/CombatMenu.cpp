#include "2d/CCMenuItem.h"
#include "2d/CCMenu.h"
#include "2d/CCActionInterval.h"
#include "base/CCEventListenerTouch.h"
#include "base/CCTouch.h"
#include "base/CCEvent.h"
#include "base/CCDirector.h"
#include "base/CCRef.h"
USING_NS_CC;
#include "CombatMenu.h"
#include "Common/CommonDef.h"
#include "Game/Game.h"
#include "Game/StringInfoManager.h"
#include "Game/ConstStrings.h"
bool CCombatMenu::init()
{
	EventListenerTouchOneByOne* _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->setSwallowTouches(true);
	_touchListener->onTouchBegan = CC_CALLBACK_2(CCombatMenu::onTouchBegan, this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(CCombatMenu::onTouchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(CCombatMenu::onTouchEnded, this);
	_touchListener->onTouchCancelled = CC_CALLBACK_2(CCombatMenu::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(_touchListener, this);

	const std::string& strMove = CGame::GetInstance()->GetStringManager()->GetString(combatMenu_move);
	m_pMenuItemMove = MenuItemFont::create(strMove, CC_CALLBACK_1(CCombatMenu::OnMenuMove, this));

	const std::string& strAttack = CGame::GetInstance()->GetStringManager()->GetString(combatMenu_attack);
	m_pMenuItemAttack = MenuItemFont::create(strAttack, CC_CALLBACK_1(CCombatMenu::OnMenuAttack, this));

	const std::string& strEnd = CGame::GetInstance()->GetStringManager()->GetString(combatMenu_end);
	m_pMenuItemEnd = MenuItemFont::create(strEnd, CC_CALLBACK_1(CCombatMenu::OnMenuMove, this));

	auto pMenu = Menu::create( m_pMenuItemMove, m_pMenuItemAttack, m_pMenuItemEnd,nullptr);
	pMenu->alignItemsVertically();


	// elastic effect
	auto s = Director::getInstance()->getWinSize();
	addChild(pMenu);
	pMenu->setPosition(Vec2(30.0f, s.height/2));
	pMenu->setScale(0);
	pMenu->runAction(ScaleTo::create(1,1));
	return true;
}


bool CCombatMenu::onTouchBegan(Touch *touch, Event * event)
{
	return m_bEnableTouch;
}

void CCombatMenu::onTouchEnded(Touch *touch, Event * event)
{
}

void CCombatMenu::onTouchCancelled(Touch *touch, Event * event)
{
}

void CCombatMenu::onTouchMoved(Touch *touch, Event * event)
{
}

void CCombatMenu::OnMenuMove(Ref* sender)
{
	this->setVisible(false);
	m_bEnableTouch = false;
}

void CCombatMenu::OnMenuAttack(Ref* sender)
{

}

CCombatMenu::~CCombatMenu()
{
}

CCombatMenu::CCombatMenu():
m_bEnableTouch(true)
{

}

void CCombatMenu::EnableMenu( bool bEnable )
{
	this->setVisible(bEnable);
	m_bEnableTouch = bEnable;
}

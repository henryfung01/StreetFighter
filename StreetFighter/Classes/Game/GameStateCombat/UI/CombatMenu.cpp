#include "2d/CCMenuItem.h"
#include "2d/CCMenu.h"
#include "base/CCEventListenerTouch.h"
#include "base/CCTouch.h"
#include "base/CCEvent.h"
USING_NS_CC;
#include "CombatMenu.h"

bool CCombatMenu::init()
{
	EventListenerTouchOneByOne* _touchListener = EventListenerTouchOneByOne::create();
	_touchListener->setSwallowTouches(true);
	_touchListener->onTouchBegan = CC_CALLBACK_2(CCombatMenu::onTouchBegan, this);
	_touchListener->onTouchMoved = CC_CALLBACK_2(CCombatMenu::onTouchMoved, this);
	_touchListener->onTouchEnded = CC_CALLBACK_2(CCombatMenu::onTouchEnded, this);
	_touchListener->onTouchCancelled = CC_CALLBACK_2(CCombatMenu::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithFixedPriority(_touchListener, 1);

	

/*	m_pMenuItemMove = MenuItemFont::create("ÒÆ¶¯", CC_CALLBACK_1(MenuLayerMainMenu::menuCallbackBugsTest, this));

	// Font Item
	auto item7= MenuItemFont::create("Quit", CC_CALLBACK_1(MenuLayerMainMenu::onQuit, this));

	auto item8 = MenuItemFont::create("Remove menu item when moving", CC_CALLBACK_1(MenuLayerMainMenu::menuMovingCallback, this));

	auto color_action = TintBy::create(0.5f, 0, -255, -255);
	auto color_back = color_action->reverse();
	auto seq = Sequence::create(color_action, color_back, nullptr);
	item7->runAction(RepeatForever::create(seq));

	auto menu = Menu::create( item1, item2, item3, item4, item5, item6, item7, item8,  nullptr);
	menu->alignItemsVertically();


	// elastic effect
	auto s = Director::getInstance()->getWinSize();

	int i=0;
	for(const auto &child : menu->getChildren()) {
		auto dstPoint = child->getPosition();
		int offset = (int) (s.width/2 + 50);
		if( i % 2 == 0)
			offset = -offset;

		child->setPosition( Vec2( dstPoint.x + offset, dstPoint.y) );
		child->runAction(
			EaseElasticOut::create(MoveBy::create(2, Vec2(dstPoint.x - offset,0)), 0.35f)
			);
		i++;
	}

	_disabledItem = item3; item3->retain();
	_disabledItem->setEnabled( false );

	addChild(menu);
	menu->setPosition(Vec2(s.width/2, s.height/2));
	menu->setScale(0);
	menu->runAction(ScaleTo::create(1,1)); */
	return true;
}


bool CCombatMenu::onTouchBegan(Touch *touch, Event * event)
{
	return true;
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
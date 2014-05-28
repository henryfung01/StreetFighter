#include "CombatInputHandler.h"
#include "CombatView.h"
#include "ui\UIButton.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool CCombatView::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(CCombatUILayer::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    //add a test button
	ui::Button* button = ui::Button::create("cocosui/animationbuttonnormal.png",
		"cocosui/animationbuttonpressed.png");
	button->setPosition(Point(origin.x + button->getContentSize().width/2 ,
                                origin.y + button->getContentSize().height/2));
	m_pCombatInputHandler = new CCombatInputHandler();
	m_pCombatInputHandler->Init();
	button->addTouchEventListener(this, toucheventselector(CCombatUILayer::OnTouchEvent));
	this->addChild(button);
    return true;
}


void CCombatView::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void CCombatView::OnTouchEvent(Ref *pSender, TouchEventType type)
{
	if(m_pCombatInputHandler)
	{
		m_pCombatInputHandler->OnTouchEvent(pSender,type);
	}
}

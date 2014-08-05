#include "SceneTouchLayer.h"
#include "CCEventListenerTouch.h"
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
	return true;
}

void CSceneInputLayer::onTouchEnded( Touch* touch, Event* event )
{

}

void CSceneInputLayer::onTouchCancelled( Touch* touch, Event* event )
{

}

void CSceneInputLayer::onTouchMoved( Touch* touch, Event* event )
{

}

CSceneInputLayer::CSceneInputLayer()
{

}

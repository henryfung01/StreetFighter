#ifndef __COMBAT_MENU_H__
#define __COMBAT_MENU_H__
#include "2d/CCLayer.h"
namespace cocos2d
{
	MenuItemFont;
	Touch;
	Event;
	Ref;
};
class CCombatMenu : public cocos2d::Layer
{
public:
    virtual bool init();
	CCombatMenu();
	virtual ~CCombatMenu();
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatMenu);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
	void OnMenuMove(cocos2d::Ref* sender);
	void OnMenuAttack(cocos2d::Ref* sender);
	virtual void EnableMenu(bool bEnable);
private:
	cocos2d::MenuItemFont* m_pMenuItemMove;
	cocos2d::MenuItemFont* m_pMenuItemAttack;
	cocos2d::MenuItemFont* m_pMenuItemEnd;
	bool m_bEnableTouch;
};

#endif // __COMBAT_MENU_H__

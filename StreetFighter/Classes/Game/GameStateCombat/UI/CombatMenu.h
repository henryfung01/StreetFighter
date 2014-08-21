#ifndef __COMBAT_MENU_H__
#define __COMBAT_MENU_H__
#include "2d/CCLayer.h"
namespace cocos2d
{
	MenuItemFont;
	Touch;
	Event;
};
class CCombatMenu : public cocos2d::Layer
{
public:
    virtual bool init(); 
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatMenu);
	bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event * event);
	void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event * event);
private:
	MenuItemFont* m_pMenuItemMove;
	MenuItemFont* m_pMenuItemAttack;
	MenuItemFont* m_pMenuItemSkill;
	MenuItemFont* m_pMenuItemMagic;
	MenuItemFont* m_pMenuItemItem;
	MenuItemFont* m_pMenuItemEnd;
};

#endif // __COMBAT_MENU_H__

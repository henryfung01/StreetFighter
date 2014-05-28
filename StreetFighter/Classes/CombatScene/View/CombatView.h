#ifndef __COMBAT_VIEW_H__
#define __COMBAT_VIEW_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
class CCombatInputHandler;
class CCombatView : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void OnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatView);
private:
	CCombatInputHandler* m_pCombatInputHandler;
};

#endif // __COMBAT_VIEW_H__

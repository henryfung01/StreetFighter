#ifndef __COMBATUI_LAYER_H__
#define __COMBATUI_LAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
class CCombatUILayer : public cocos2d::Layer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

	void touchEvent(Ref *pSender, cocos2d::ui::TouchEventType type);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatUILayer);
};

#endif // __COMBATUI_LAYER_H__

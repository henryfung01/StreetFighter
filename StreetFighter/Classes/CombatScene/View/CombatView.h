#ifndef __COMBAT_VIEW_H__
#define __COMBAT_VIEW_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
class CCombatScene;
class CCombatView : public cocos2d::Node
{
public:
    virtual bool init();  
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void OnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatView);
	void CreateUILayer();
private:
	cocos2d::Layer* m_pUILayer;
	CCombatScene* _GetCombatScene();
};

#endif // __COMBAT_VIEW_H__

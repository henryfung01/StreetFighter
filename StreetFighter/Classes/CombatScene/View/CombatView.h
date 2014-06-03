#ifndef __COMBAT_VIEW_H__
#define __COMBAT_VIEW_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Common/CommonView.h"
class CCombatScene;
class CCombatView : public CCommonView
{
public:
    virtual bool init();  
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void OnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatView);
	void CreateUILayer();
	void SetStatusLabel(const char* status);
private:
	CCombatScene* _GetCombatScene();
	cocos2d::ui::Text* m_pStatusLabel;
};

#endif // __COMBAT_VIEW_H__

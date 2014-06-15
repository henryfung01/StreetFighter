#ifndef __COMBAT_UI_H__
#define __COMBAT_UI_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Common/CommonView.h"
class CGameStateCombat;
class CSuperAttackDisplayer;
class CCombatUI : public CCommonView
{
public:
    virtual bool init();  
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void OnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatUI);
	void CreateUILayer();
	void SetStatusLabel(const char* status);
	void SetDrawGestureType(int gestureType);
private:
	CGameStateCombat* _GetCombatState();
	cocos2d::ui::Text* m_pStatusLabel;
	CSuperAttackDisplayer* m_pSuperAttackDisplayer;
	int m_iGestureType;
};

#endif // __COMBAT_UI_H__

#ifndef __COMBAT_UI_H__
#define __COMBAT_UI_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Common/CommonView.h"
class CGameStateBegin;
class CSuperAttackDisplayer;
class cocos2d::LayerColor;
class CBeginUI : public CCommonView
{
public:
    virtual bool init();  
    // implement the "static create()" method manually
    CREATE_FUNC(CBeginUI);
	void OnTintOver();
	void OnNameFadeIn();
	bool onTouchHappen(cocos2d::Touch *touch, cocos2d::Event *unused_event); 
private:
	CGameStateBegin* _GetState();
	cocos2d::LayerColor* m_colorLayer;
};

#endif // __COMBAT_UI_H__

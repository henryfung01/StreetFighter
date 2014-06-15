#ifndef __COMBAT_CONTROLLER_H__
#define __COMBAT_CONTROLLER_H__
//whitebai 2014.5.22
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SpecialTouchHandler.h"
class CGameStateCombat;
class CCombatController
{
public:
	CCombatController();
	virtual ~CCombatController();
   void OnSpecialTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
   bool init();
   void OnSpecialInput(const char* input);
   const DollarRecognizer::Path2D* GetGesturePath(int gestureType) { return m_SpTouchHandler.GetGesturePath(gestureType);}
private:
	CSpTouchHandler m_SpTouchHandler;
	CGameStateCombat* _GetCombatState();
};

#endif // __COMBAT_CONTROLLER_H__

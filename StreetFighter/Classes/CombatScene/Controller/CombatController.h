#ifndef __COMBAT_CONTROLLER_H__
#define __COMBAT_CONTROLLER_H__
//whitebai 2014.5.22
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SpecialTouchHandler.h"
class CCombatScene;
class CCombatController:public cocos2d::Node
{
public:
	CCombatController();
	virtual ~CCombatController();
   void OnSpecialTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
   bool init();
   CREATE_FUNC(CCombatController);
   void OnSpecialInput(const char* input);
   const DollarRecognizer::Path2D* GetGesturePath(int gestureType) { return m_SpTouchHandler.GetGesturePath(gestureType);}
private:
	CSpTouchHandler m_SpTouchHandler;
	CCombatScene* _GetCombatScene();
};

#endif // __COMBAT_CONTROLLER_H__

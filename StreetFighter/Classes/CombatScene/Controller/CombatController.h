#ifndef __COMBAT_CONTROLLER_H__
#define __COMBAT_CONTROLLER_H__
//whitebai 2014.5.22
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "SpecialTouchHandler.h"
//设置最大的缓存touch点的数目，之所以提前处理，为了防止反复resize缓存vector造成低效
#define MAX_TOUCH_POINT 128
class CCombatController:public cocos2d::Node
{
public:
	CCombatController();
	virtual ~CCombatController();
   void OnSpecialTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
   bool init();
   CREATE_FUNC(CCombatController);
private:
	CSpTouchHandler m_SpTouchHandler;
};

#endif // __COMBAT_CONTROLLER_H__

#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__
//whitebai 2014.5.21
#include "cocos2d.h"
class CCombatView;
class CCombatController;
class CCombatScene : public cocos2d::Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* create(bool usePhysics); 
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatScene);
	CCombatView* GetView() {return m_pCombatView;}
	CCombatController* GetController() {return m_pCombatController;}
private:
	void _InitCombatScene();
	CCombatView* m_pCombatView;
	CCombatController* m_pCombatController;
};

#endif // __COMBAT_SCENE_H__

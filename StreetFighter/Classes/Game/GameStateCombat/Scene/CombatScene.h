#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__
//whitebai 2014.5.21
#include "cocos2d.h"
class CCombatUI;
class CCombatController;
class cocos2d::TMXTiledMap;
class CCombatScene : public cocos2d::Scene
{
public:
	CCombatScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static CCombatScene* create(bool usePhysics); 
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatScene);
private:
	void _InitCombatScene();
	cocos2d::TMXTiledMap* m_map;
};

#endif // __COMBAT_SCENE_H__

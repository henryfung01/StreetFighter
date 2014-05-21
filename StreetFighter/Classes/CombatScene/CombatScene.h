#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__
//whitebai 2014.5.21
#include "cocos2d.h"

class CCombatScene : public cocos2d::Scene
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createCombatScene(bool usePhysics); 
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatScene);
};

#endif // __COMBAT_SCENE_H__

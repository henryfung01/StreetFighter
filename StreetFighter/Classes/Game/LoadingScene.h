#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__
//whitebai 2014.5.21
#include "cocos2d.h"
class CCombatUI;
class CCombatController;
class CLoadingScene : public cocos2d::Scene
{
public:
    virtual bool init();
    CREATE_FUNC(CLoadingScene);
};

#endif // __LOADING_SCENE_H__

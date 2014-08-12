#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__
//whitebai 2014.5.21
#include "Game/BaseClass/GameScene.h"
class CGridArea;
class CLoadingScene:public CGameScene
{
public:
    virtual bool init();
    CREATE_FUNC(CLoadingScene);
	virtual void OnLoadingComplete(float dt);
	virtual void onEnterTransitionDidFinish();
	//will not give the entity container temporary
	cocos2d::Node* GetEntityContainer() { return nullptr;}
	//loading scene will not give the converter
	CGridArea* GetGridArea() { return nullptr;}
	void PostInit(){}
};

#endif // __LOADING_SCENE_H__

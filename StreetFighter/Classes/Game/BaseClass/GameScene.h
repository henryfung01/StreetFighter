#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
//whitebai 2014.8.10
//convert the grid position to render position
#include "CCScene.h"
class CPosConverter;
class CGameScene:public cocos2d::Scene
{
public:
	CGameScene(){}
	virtual ~CGameScene(){}
	//should implement the interface
	//all the player,enemy,item will add to this node
	virtual cocos2d::Node* GetEntityContainer() = 0;
	//return the converter from logic to render
	virtual CPosConverter* GetPosConverter() = 0;
	//this function will be called outside create function,so
	//you can do this when create a object in the object's init function
	/*
	CGameStateBase* gameState = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
	CGameScene* pGameScene = gameState->GetGameScene();
	pGameScene->GetEntityContainer()->addChild(m_node);
	*/
	//use composite to reuse cocos class,can reduce the function call between all game objects
	//and easy to upgrade the cocos version
	virtual void PostInit() = 0;
};
#endif // __GAME_SCENE_H__

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__
//whitebai 2014.8.10
//convert the grid position to render position
#include "2d/CCScene.h"
class CGridArea;
class CGameScene:public cocos2d::Scene
{
public:
	CGameScene(){}
	virtual ~CGameScene(){}
	//return the converter from logic to render
	virtual CGridArea* GetGridArea() = 0;
	virtual void PostInit() = 0;
	//a logic entity will hold a cocos node for rendering,
	//every scene should give a interface to add render node
	//this function will be called outside create function,so
	//you can do this when create a object in the object's init function
	/*
	CGameStateBase* gameState = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
	CGameScene* pGameScene = gameState->GetGameScene();
	pGameScene->GetEntityContainer()->addChild(m_node);
	*/
	//use composite to reuse cocos class,can reduce the function call between all game objects
	//and easy to upgrade the cocos version
	virtual void AddEntityNode(cocos2d::Node* pNode) = 0;
	virtual void AddUINode(cocos2d::Node* pNode) = 0;
};
#endif // __GAME_SCENE_H__

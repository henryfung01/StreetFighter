#include "CombatScene.h"
#include "CombatUILayer.h"
USING_NS_CC;

cocos2d::Scene* CCombatScene::createCombatScene(bool usePhysics)
{
	Scene* combatScene = NULL;
	if(usePhysics)
	{
		combatScene = Scene::create();
	}
	else
	{
		combatScene = Scene::createWithPhysics();
	}
	if(combatScene)
	{
		// 'layer' is an autorelease object
		auto layer = CCombatUILayer::create();

		// add layer as a child to scene
		combatScene->addChild(layer);
		return combatScene;
	}
	return NULL;
}
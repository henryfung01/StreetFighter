#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__
//whitebai 2014.5.21
namespace cocos2d
{
	class TMXTiledMap;
}
#include "CCNode.h"
#include "CCLayer.h"
#include "Game/BaseClass/GameScene.h"
class CCombatUI;
class CCombatController;
class CPlayer;
class CCombatArea;
class CPosConverter;
class CCombatScene : public CGameScene
{
public:
	CCombatScene();
	~CCombatScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static CCombatScene* create(bool usePhysics); 
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatScene);
	const cocos2d::Rect& GetMoveRect() { return m_moveRect;}
	cocos2d::Node* GetEntityContainer() { return m_EntityLayer;}
	CPosConverter* GetPosConverter();
	void PostInit();
private:
	void _InitCombatScene();
	cocos2d::TMXTiledMap* m_map;
	cocos2d::Layer* m_EntityLayer;
	cocos2d::Rect m_moveRect;
	CPlayer* m_pPlayer;
	CCombatArea* m_pCombatArea;
};

#endif // __COMBAT_SCENE_H__

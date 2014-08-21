#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__
//whitebai 2014.5.21
namespace cocos2d
{
	class TMXTiledMap;
}
#include "2d/CCNode.h"
#include "2d/CCLayer.h"
#include "Game/BaseClass/GameScene.h"
#include "Common/CommonDef.h"
class CCombatUI;
class CCombatController;
class CPlayer;
class CCombatArea;
class CGridArea;
struct EntityPos;
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
	virtual void AddEntityNode(cocos2d::Node* pNode);
	virtual void AddUINode(cocos2d::Node* pNode);
	CGridArea* GetGridArea();
	void PostInit();
	void OnTouchGrid(const EntityPos& pos);
private:
	void _InitCombatScene();
	cocos2d::TMXTiledMap* m_map;
	cocos2d::Layer* m_EntityLayer;
	cocos2d::Layer* m_UILayer;
	cocos2d::Rect m_moveRect;
	EntityId m_iPlayerId;
	CCombatArea* m_pCombatArea;
};

#endif // __COMBAT_SCENE_H__

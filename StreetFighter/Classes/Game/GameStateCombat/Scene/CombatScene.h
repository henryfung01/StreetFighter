#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__
//whitebai 2014.5.21
#include "cocos2d.h"
class CCombatUI;
class CCombatController;
class cocos2d::TMXTiledMap;
class CPlayer;
class CCombatScene : public cocos2d::Scene
{
public:
	CCombatScene();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
	static CCombatScene* create(bool usePhysics); 
    // implement the "static create()" method manually
    CREATE_FUNC(CCombatScene);
	const cocos2d::Rect& GetMoveRect() { return m_moveRect;}
private:
	void _InitCombatScene();
	cocos2d::TMXTiledMap* m_map;
	cocos2d::Rect m_moveRect;
	CPlayer* m_pPlayer;
};

#endif // __COMBAT_SCENE_H__

#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "../Actor/Actor.h"
class CPlayer:public cocostudio::Armature
{    
public:
	CPlayer ();
	virtual ~CPlayer(){}
	//create cocos resource
	virtual bool init();
	CREATE_FUNC(CPlayer);
public: 
	Play* GetController() { return m_pCombatController;}
	CCombatUI* GetUI() { return m_pCombatUI;}
	CCombatScene* GetScene() { return m_pCombatScene;}
	virtual void OnLoadingComplete();
private:
	CCombatController* m_pCombatController;
	CCombatUI* m_pCombatUI;
	bool m_bIsLocal;
};

#endif // __PLAYER_H__

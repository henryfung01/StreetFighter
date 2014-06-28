#ifndef __MOVEMENT_CONTROLLER_H__
#define __MOVEMENT_CONTROLLER_H__
#include "cocostudio/CCArmature.h"
class CActor:public cocostudio::Armature
{    
public:
	CActor ();
	virtual ~CActor(){}
	//create cocos resource
	virtual bool init();
	CREATE_FUNC(CActor);
public: 
	CCombatController* GetController() { return m_pCombatController;}
	CCombatUI* GetUI() { return m_pCombatUI;}
	CCombatScene* GetScene() { return m_pCombatScene;}
	virtual void OnLoadingComplete();
private:
	CCombatController* m_pCombatController;
	CCombatUI* m_pCombatUI;
	bool m_bIsLocal;
};

#endif // __MOVEMENT_CONTROLLER_H__

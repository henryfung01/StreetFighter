#ifndef __ACTOR_MANAGER_H__
#define __ACTOR_MANAGER_H__
#include "Actor.h"
#include <set>
typedef std::set<EntityId> ActorIDSet; 
class CActorManager:public cocos2d::Ref 
{    
public:
	CActorManager();
	virtual ~CActorManager(){}
	//create cocos resource
	virtual bool init();
	CREATE_FUNC(CActorManager);
	bool AddActor(EntityId id);
	bool RemoveActor(EntityId id);
	//may return null ,so you should write like this 
	/* CActor* pActor = CGame::GetInstance()->GetActorManager()->GetActor(id);
	if(pActor)
	{ 
		ooxx;
	}*/
	CActor* GetActor(EntityId id);
private:
	ActorIDSet m_allActorIDs;
};

#endif // __ACTOR_MANAGER_H__

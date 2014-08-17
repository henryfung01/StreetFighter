//cocos include
#include "ActorManager.h"
#include "Game/Game.h"
#include "Game/BaseClass/EntitySystem.h"
CActorManager::CActorManager()
{

}

bool CActorManager::init()
{
	return true;
}

bool CActorManager::AddActor( EntityId id )
{
	m_allActorIDs.insert(id);
	return true;
}

bool CActorManager::RemoveActor( EntityId id )
{
	m_allActorIDs.erase(id);
	return true;
}

CActor* CActorManager::GetActor( EntityId id )
{
	return static_cast<CActor*>(CGame::GetInstance()->GetEntitySystem()->GetEntityFromID(id));
}

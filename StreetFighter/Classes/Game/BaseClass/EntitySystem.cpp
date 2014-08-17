#include "EntitySystem.h"
#include "Game/Actor/Actor.h"
#include "Game/Actor/Player.h"
bool CEntitySystem::init()
{
	unsigned dwMaxIndex = (unsigned)(m_EntitySaltBuffer.GetTSize());
	m_EntityArray.resize(dwMaxIndex);
	RegisterCreateFunc(EntityType_Player,&EntityCreateFuncT<CPlayer>);
	RegisterCreateFunc(EntityType_Actor,&EntityCreateFuncT<CActor>);
	return true;
}

CEntitySystem::CEntitySystem()
{

}

CEntitySystem::~CEntitySystem()
{

}

EntityId CEntitySystem::GenerateEntityId()
{
	EntityId returnId = 0;
	returnId = HandleToId(m_EntitySaltBuffer.InsertDynamic());
	return returnId;
}

CEntity* CEntitySystem::GetEntityFromID( EntityId id )
{
	if ( id == 0 )
		return NULL;

	unsigned dwMaxUsed = m_EntitySaltBuffer.GetMaxUsed();
	unsigned hdl = IdToIndex(id);
	unsigned hd1cond = hdl<=dwMaxUsed ? 0xffffffff:0;
//	hd1cond = (unsigned)((unsigned)hd1cond | -(unsigned)hd1cond ); //0 for hdl>dwMaxUsed, 0xFFFFFFFF for hdl<=dwMaxUsed
	hdl = hd1cond & hdl;

	CEntity *const pEntity = m_EntityArray[hdl];

	if(pEntity)
	{
		if (pEntity->GetId()==id)  //my salt not equaled
			return pEntity;
	}
	return 0;
}

bool CEntitySystem::_AddEntity( CEntity* pEntity )
{
	if(pEntity->GetId() == Invalid_Id)
	{
		EntityId newId = GenerateEntityId();
		m_EntityArray[IdToHandle(newId).GetIndex()]=pEntity;
		pEntity->SetId(newId);
		return true;
	}
	else
	{
		CEntity* tempEnt = GetEntityFromID(pEntity->GetId());
		if(tempEnt == pEntity)
		{
			CCASSERT(0,"Entity %u has already been add to entitysystem!");
			return true;
		}
		else
		{
			CCASSERT(0,"fetal error,please reset the game");
		}
	}
	return false;
}

bool CEntitySystem::RegisterCreateFunc( EntityType entityType,EntityCreateFunc func )
{
	if(_CheckTypeValid(entityType))
	{
		m_allCreateFuncs[entityType] = func;
		return true;
	}
	else
	{
		return false;
	}
}

CEntity* CEntitySystem::CreateEntity( EntityType entityType )
{
	if(_CheckTypeValid(entityType))
	{
		//the ref will be 1,will not auto release
		CEntity* pEntity = m_allCreateFuncs[entityType]();
		if(pEntity && _AddEntity(pEntity) && pEntity->init())  //init ID and add the entity to manager
		{
			return pEntity;
		}
		else
		{
			pEntity->release();
		}
	}
	return nullptr;
}

bool CEntitySystem::_CheckTypeValid( EntityType entityType )
{
	return entityType > EntityType_None && entityType < EntityType_Count;
}

//whitebai 2014.629
//������entity manager,�������entity�������𴴽���ɾ��,�����ṩͨ��id����entityʵ��Ĺ���
#ifndef __ENTITY_SYSTEM_H__
#define __ENTITY_SYSTEM_H__
#include "Entity.h"
#include "base/CCRef.h"
#include "SaltBufferArray.h"
#include "Common/CommonDef.h"
template<typename T>
CEntity* EntityCreateFuncT() 
{
	CEntity* pEntity = new T();
	return pEntity;
}

typedef CEntity*(*EntityCreateFunc)();
class CEntitySystem:public cocos2d::Ref
{    
public:
	CEntitySystem();
	virtual ~CEntitySystem();
	bool init();
	CREATE_FUNC(CEntitySystem);
	static inline unsigned short IdToIndex(const EntityId id) { return id & 0xffff; }
	static inline CSaltHandle<> IdToHandle( const EntityId id ) { return CSaltHandle<>(id>>16,id&0xffff); }
	static inline EntityId HandleToId( const CSaltHandle<> id ) { return (((unsigned)id.GetSalt())<<16) | ((unsigned)id.GetIndex()); }
	CEntity* GetEntityFromID( EntityId id );
	bool RegisterCreateFunc(EntityType entityType,EntityCreateFunc func);
	CEntity* CreateEntity(EntityType entityType);
	
private:
	inline bool _CheckTypeValid(EntityType entityType);
	bool _AddEntity(CEntity* pEntity);
	EntityId CEntitySystem::GenerateEntityId();
	CSaltBufferArray<>	m_EntitySaltBuffer;		
	std::vector<CEntity *>	m_EntityArray;
	EntityCreateFunc m_allCreateFuncs[EntityType_Count];
};

#endif // __ENTITY_SYSTEM_H__

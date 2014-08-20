/*add by whitebai 2014.6.29*/
#ifndef __COMPONENT_H__
#define __COMPONENT_H__
#include "base/CCRef.h"
class CEntity;
#define CREATE_FUNC_EX(type) static CComponent*create( CEntity* pEntity )\
{\
	CComponent* pComponent = new type(pEntity);\
	if(pComponent->init()) \
	{\
		pComponent->autorelease();\
		return pComponent;\
	}\
	else\
	{\
		delete pComponent;\
		return nullptr;\
	}\
}
class CComponent:public cocos2d::Ref
{    
public:
	CComponent(CEntity* pOwner);
	virtual bool init();
	virtual ~CComponent(){}
	int GetType() {return m_iType;}
	
protected:
	int m_iType;
	CEntity* m_pOwner;
};

#endif // __COMPONENT_H__

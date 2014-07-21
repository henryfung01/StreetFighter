//whitebai 2014.629
//基础的逻辑实体，其他逻辑从这个派生，这个有基础逻辑，可以组合各种component
#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "CCRef.h"
#include "CCVector.h"
#include "CCGeometry.h"
#include "../../Common/CommonDef.h"
class CComponent;
typedef cocos2d::Vector<CComponent*> ComponentVec;
class CEntity:public cocos2d::Ref
{    
public:
	CEntity();
	virtual ~CEntity();
	bool init();
	void ClearAll();
	bool AddComponent(CComponent* pComponent);
private:
	CComponent* m_BaseComponents[CComponentType_BaseCount];
	ComponentVec m_ExtendedComponents;
	cocos2d::Point m_vPosition;
	float m_fHeight;
};

#endif // __ENTITY_H__

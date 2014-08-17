//whitebai 2014.629
//基础的逻辑实体，其他逻辑从这个派生，这个有基础逻辑，可以组合各种component
#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "CCRef.h"
#include "CCVector.h"
#include "CCGeometry.h"
#include "../../Common/CommonDef.h"
#include "Common/GamePos.h"
class CComponent;
class CPosConverter;
typedef cocos2d::Vector<CComponent*> ComponentVec;
//继承自ref是为了合适的时候可以使用lua的基本功能
class CEntity:public cocos2d::Ref
{    
public:
	CEntity();
	virtual ~CEntity();
	virtual bool init();
	void ClearAll();
	virtual EntityType GetType() { return EntityType_None;}
	virtual EntityId GetId() { return m_iID;}
	virtual void SetId(EntityId id) { m_iID = id;}
	bool AddComponent(CComponent* pComponent);
	virtual cocos2d::Node* GetRenderNode() { return nullptr;}
	virtual void SetGridPos(const EntityPos& pos);
	virtual void SetSize(const EntityPos& size);
	virtual const EntityPos& GetSize() { return m_vSize;}
	virtual const EntityPos& GetGridPos() {return m_vPosition;}
protected:
	CComponent* m_BaseComponents[CComponentType_BaseCount];
	ComponentVec m_ExtendedComponents;
	//entity 所在的格子
	EntityPos m_vPosition;
	//竖直水平方向占用的格子
	EntityPos m_vSize;
	//用来记录高度的，比如手榴弹的飞行轨迹，要把高度转换为Y轴的偏移
	float m_fHeight; 
	EntityId m_iID;
};

#endif // __ENTITY_H__

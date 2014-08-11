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
class CEntity:public cocos2d::Ref
{    
public:
	CEntity();
	virtual ~CEntity();
	bool init();
	void ClearAll();
	bool AddComponent(CComponent* pComponent);
	virtual cocos2d::Node* GetRenderNode() { return nullptr;}
	virtual void SetGridPos(const EntityPos& pos,CPosConverter* pConverter);
	virtual void SetSize(const EntityPos& size);
protected:
	CComponent* m_BaseComponents[CComponentType_BaseCount];
	ComponentVec m_ExtendedComponents;
	//entity 所在的格子
	EntityPos m_vPosition;
	//竖直水平方向占用的格子
	EntityPos m_vSize;
	//用来记录高度的，比如手榴弹的飞行轨迹，要把高度转换为Y轴的偏移
	float m_fHeight; 
};

#endif // __ENTITY_H__

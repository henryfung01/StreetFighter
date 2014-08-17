//whitebai 2014.629
//�������߼�ʵ�壬�����߼����������������л����߼���������ϸ���component
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
//�̳���ref��Ϊ�˺��ʵ�ʱ�����ʹ��lua�Ļ�������
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
	//entity ���ڵĸ���
	EntityPos m_vPosition;
	//��ֱˮƽ����ռ�õĸ���
	EntityPos m_vSize;
	//������¼�߶ȵģ��������񵯵ķ��й켣��Ҫ�Ѹ߶�ת��ΪY���ƫ��
	float m_fHeight; 
	EntityId m_iID;
};

#endif // __ENTITY_H__

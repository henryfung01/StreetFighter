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
	//entity ���ڵĸ���
	EntityPos m_vPosition;
	//��ֱˮƽ����ռ�õĸ���
	EntityPos m_vSize;
	//������¼�߶ȵģ��������񵯵ķ��й켣��Ҫ�Ѹ߶�ת��ΪY���ƫ��
	float m_fHeight; 
};

#endif // __ENTITY_H__

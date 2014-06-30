//whitebai 2014.629
//�������߼�ʵ�壬�����߼����������������л����߼���������ϸ���component
#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "CCRef.h"
#include "CCVector.h"
#include "CCGeometry.h"
class CComponent;
typedef cocos2d::Vector<CComponent*> ComponentVec;
class CEntity:public cocos2d::Ref
{    
public:
	CEntity();
	virtual ~CEntity();
	bool init();
	void ClearAll();
private:
	ComponentVec m_allComponents;
	cocos2d::Point m_vPosition;
	float m_fHeight;
};

#endif // __ENTITY_H__

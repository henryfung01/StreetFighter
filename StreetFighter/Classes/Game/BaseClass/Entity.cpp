#include "Entity.h"
#include "Component.h"
CEntity::CEntity():
m_vPosition(0.0f,0.0f),
m_fHeight(0.0f)
{

}

bool CEntity::init()
{
	ClearAll();
	return true;
}

void CEntity::ClearAll()
{
	//cocos vector will call release function
	m_allComponents.clear();
}

CEntity::~CEntity()
{
	ClearAll();
}

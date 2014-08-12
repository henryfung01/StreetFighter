#include "Entity.h"
#include "Component.h"
CEntity::CEntity():
m_vPosition(0.0f,0.0f),
m_fHeight(0.0f)
{

}

bool CEntity::init()
{
	for(int i=0;i<CComponentType_BaseCount;++i)
	{
		m_BaseComponents[i] = nullptr;
	}
	m_ExtendedComponents.clear();
	return true;
}

void CEntity::ClearAll()
{
	for(int i = 0;i<CComponentType_BaseCount;++i)
	{
		if(m_BaseComponents[i] != nullptr)
		{
			m_BaseComponents[i]->release();
		}
		m_BaseComponents[i] = nullptr;
	}
	//cocos vector will call release function
	m_ExtendedComponents.clear();
}

CEntity::~CEntity()
{
	ClearAll();
}

bool CEntity::AddComponent( CComponent* pComponent )
{
	bool sucess = false;
	int itype = pComponent->GetType();
	if(itype > CComponentType_None && itype < CComponentType_BaseCount)
	{
		if(m_BaseComponents[itype])
		{
			m_BaseComponents[itype]->release();
		}
		m_BaseComponents[itype] = pComponent;
		sucess = true;
	}
	else
	{
		ComponentVec::iterator it = m_ExtendedComponents.begin();
		for(;it!= m_ExtendedComponents.end();++it)
		{
			if((*it)->GetType() == pComponent->GetType())
			{
				m_ExtendedComponents.erase(it);
				break;
			}
		}
		m_ExtendedComponents.pushBack(pComponent);
		sucess = true;
	}
	return sucess;
}

void CEntity::SetGridPos( const EntityPos& pos)
{
	m_vPosition = pos;
}

void CEntity::SetSize( const EntityPos& size )
{
	m_vSize = size;
}

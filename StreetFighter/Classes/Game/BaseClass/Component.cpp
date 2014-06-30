#include "Component.h"
#include "Common/CommonDef.h"
CComponent::CComponent( CEntity* pOwner ):
m_pOwner(pOwner),
m_iType(CComponentType_None)
{

}

bool CComponent::init()
{
	//do nothing
	return true;
}


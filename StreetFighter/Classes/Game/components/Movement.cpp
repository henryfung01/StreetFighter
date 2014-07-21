#include "Movement.h"
#include "../../Common/CommonDef.h"
USING_NS_CC;

CMovement::CMovement( CEntity* pEntity ):
CComponent(pEntity),
m_fGravity(0.0f),
m_fSpeedX(0.0f),
m_fSpeedY(0.0f),
m_fSpeedH(0.0f)
{
	m_iType = CComponentType_Move;
}

bool CMovement::init()
{
	return true;
}

#include "Actor.h"
#include "../components/Movement.h"
CActor::CActor():
m_pArmature(nullptr)
{

}

bool CActor::init()
{
	if(CEntity::init())
	{
		AddComponent(CMovement::create(this));
		return true;
	}
	return false;
}

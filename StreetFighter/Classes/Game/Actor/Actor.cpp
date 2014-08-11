#include "Actor.h"
#include "../components/Movement.h"
#include "Game/BaseClass/PosConverter.h"
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

void CActor::SetGridPos( const EntityPos& pos,CPosConverter* pConverter )
{
	CEntity::SetGridPos(pos,pConverter);
	if(pConverter)
	{
		cocos2d::Point renderPos = pConverter->TransToRenderPos(m_vPosition,m_vSize);
		m_pArmature->setPosition(renderPos.x,renderPos.y);
	}
}

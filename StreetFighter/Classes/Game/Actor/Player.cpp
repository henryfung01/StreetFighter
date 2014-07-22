#include "Player.h"
#include "cocostudio/CCArmature.h"
#include "cocostudio/CCArmatureDataManager.h"
using namespace cocostudio;
CPlayer::CPlayer()
{

}

bool CPlayer::init()
{
	CActor::init();
	ArmatureDataManager::getInstance()->addArmatureFileInfo("animData/Player/Player.ExportJson");
	Armature *armature = nullptr;
	armature = Armature::create("Player");
	if(armature)
	{
		m_pArmature = armature;
		m_pArmature->retain();
		m_pArmature->getAnimation()->playWithIndex(0);
		return true;
	}
	return false;
}

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
	ArmatureDataManager::getInstance()->addArmatureFileInfo("animData/Player_Cat/Player_Cat.ExportJson");
	Armature *armature = nullptr;
	armature = Armature::create("Player_Cat");
	if(armature)
	{
		m_pArmature = armature;
		m_pArmature->retain();
		m_pArmature->getAnimation()->play("idle");
		//通过设置这个参数可以让左右互换
		m_pArmature->setRotationSkewY(180.0f);
		return true;
	}
	return false;
}

#include "SkillSystem.h"

CSkillSystem::CSkillSystem()
{

}

CSkillSystem::~CSkillSystem()
{

}

bool CSkillSystem::init()
{
	return true;
}

bool CSkillSystem::StartSkill( int skillID )
{
	m_iCurrentSkill = skillID;
	return true;
}

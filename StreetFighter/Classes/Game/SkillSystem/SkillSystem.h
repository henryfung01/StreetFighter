//whitebai 2014.7.2
//skill system, relative to animation system
#ifndef __SKILLSYSTEM_H__
#define __SKILLSYSTEM_H__
#include "CCRef.h"
class CSkillSystem:public cocos2d::Ref
{    
public:
	CSkillSystem();
	virtual ~CSkillSystem();
	bool init();
	bool StartSkill(int skillID);
private:
	int m_iCurrentSkill;
	float m_currTime;
};

#endif // __SKILLSYSTEM_H__

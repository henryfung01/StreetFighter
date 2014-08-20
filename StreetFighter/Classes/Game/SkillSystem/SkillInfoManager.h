//whitebai 2014.7.2
//skill info, static data for skill system
#ifndef __SKILL_INFO_MANAGER_H__
#define __SKILL_INFO_MANAGER_H__
#include "SkillInfo.h"
#include <map>
#include "base/CCRef.h"
typedef std::map<int,SkillInfo*> SkillInfoMap;
class CSkillInfoManager:public cocos2d::Ref
{    
public:
	CSkillInfoManager();
	virtual ~CSkillInfoManager();
	bool init();
	void ClearAll();
	
private:
	bool _AddSkillInfo(SkillInfo* pSkill);
	SkillInfoMap m_allSkillInfos;
};

#endif // __SKILL_INFO_MANAGER_H__

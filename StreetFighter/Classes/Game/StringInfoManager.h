//whitebai 2014.7.2
//skill info, static data for skill system
#ifndef __STRING_INFO_MANAGER_H__
#define __STRING_INFO_MANAGER_H__
#include <map>
#include "base/CCRef.h"
typedef std::map<std::string,std::string> StringInfoMap;
class CStringInfoManager:public cocos2d::Ref
{    
public:
	CStringInfoManager();
	virtual ~CStringInfoManager();
	virtual bool init();
	void ClearAll();
	CREATE_FUNC(CStringInfoManager);
	const std::string& GetString(const std::string& key);
private:
	StringInfoMap m_allStrings;
};

#endif // __STRING_INFO_MANAGER_H__

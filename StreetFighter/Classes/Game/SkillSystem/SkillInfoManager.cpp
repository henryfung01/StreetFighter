#include "SkillInfoManager.h"
#include "platform/CCFileUtils.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "cocostudio/DictionaryHelper.h"
using namespace cocostudio;
CSkillInfoManager::CSkillInfoManager()
{

}

CSkillInfoManager::~CSkillInfoManager()
{

}

bool CSkillInfoManager::init()
{
	ssize_t len = 0;  
	std::string des = cocos2d::FileUtils::getInstance()->getStringFromFile("Data/SkillInfo.json");  
	std::string jsonpath;
	rapidjson::Document jsonDict;
	jsonDict.Parse<0>(des.c_str());
	if (jsonDict.HasParseError())
	{
		CCLOG("GetParseError %s\n",jsonDict.GetParseError());
	}
	unsigned int nCount = jsonDict.Size(); 
	for (unsigned int i=0;i<nCount;i++)  
	{ 
		rapidjson::Value& info = jsonDict[i];
		SkillInfo* newInfo = new SkillInfo;
		newInfo->skillID = DICTOOL->getIntValue_json(info,"id");
		newInfo->time = DICTOOL->getFloatValue_json(info,"time");
		newInfo->animationName = DICTOOL->getStringValue_json(info,"anim");
		if(!_AddSkillInfo(newInfo))
		{
			delete newInfo;
		}
	}
	return true;
}

void CSkillInfoManager::ClearAll()
{

}

bool CSkillInfoManager::_AddSkillInfo( SkillInfo* pSkill )
{
	return true;
}

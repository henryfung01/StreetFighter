#include "StringInfoManager.h"
#include "platform/CCFileUtils.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "cocostudio/DictionaryHelper.h"
using namespace cocostudio;
CStringInfoManager::CStringInfoManager()
{

}

CStringInfoManager::~CStringInfoManager()
{

}

bool CStringInfoManager::init()
{
	ssize_t len = 0;  
	std::string des = cocos2d::FileUtils::getInstance()->getStringFromFile("Data/strings.json");  
	std::string jsonpath;
	rapidjson::Document jsonDict;
	jsonDict.Parse<0>(des.c_str());
	if (jsonDict.HasParseError())
	{
		CCLOG("GetParseError %s\n",jsonDict.GetParseError());
	}
	unsigned int nCount = jsonDict.Size(); 
	for (unsigned int i=1;i<nCount;i++)  
	{ 
		int a = 0;
		rapidjson::Value& info = jsonDict[i];
		const char* sID = info[a++].GetString();
		const char* sValue = info[a++].GetString();
		m_allStrings.insert(std::make_pair<std::string,std::string>(sID,sValue));
	}
	return true;
}

void CStringInfoManager::ClearAll()
{
	m_allStrings.clear();
}


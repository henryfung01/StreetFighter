//whitebai 2014.629
//×´Ì¬»úÊµÏÖ
#ifndef __FSM_H__
#define __FSM_H__
#include "CCRef.h"
#include "CCVector.h"
#include <map>
class CFSMState;
typedef std::map<std::string,CFSMState*> FSMStateMap;
class CFSM:public cocos2d::Ref
{    
public:
	CFSM();
	virtual ~CFSM();
	bool init();
	void ClearAll();
private:
	FSMStateMap m_allStates;
	CFSMState* m_pCurrentState;
};

#endif // __FSM_H__

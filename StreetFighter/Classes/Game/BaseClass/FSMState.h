//whitebai 2014.629
//状态机的基础类型，状态机驱动技能，技能驱动动画
#ifndef __FSM_STATE_H__
#define __FSM_STATE_H__
class CFSMState
{    
public:
	CFSMState();
	virtual ~CFSMState();
	virtual bool init();
	virtual bool OnEnterState() = 0;
	virtual bool OnLeaveState() = 0;
	virtual bool Update(float dt) = 0;
private:
	bool m_bNeedUpdate;
};

#endif // __FSM_STATE_H__

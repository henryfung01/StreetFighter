/*这个文件是独立于cocos逻辑的一个游戏模块，所有
跟game play 相关的逻辑都可以在内部创建实例*/
#ifndef __GAME_STATE_BASE_H__
#define __GAME_STATE_BASE_H__
#include "CCRef.h"
class CGameStateBase:public cocos2d::Ref
{    
public:
	CGameStateBase ();
	virtual ~CGameStateBase(){}
	int GetType() {return m_iType;}
	virtual bool OnEnter(){ return true;};
	virtual bool OnLeave(){ return true;};
private:
	int m_iType;
};

#endif // __GAME_H__

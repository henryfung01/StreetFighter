/*这个文件是独立于cocos逻辑的一个游戏模块，所有
跟game play 相关的逻辑都可以在内部创建实例*/
#ifndef __GAME_H__
#define __GAME_H__
#include "cocos2d.h"
class CGame
{    
protected:
	virtual ~CGame(){}
	CGame* GetInstance();
private:
	CGame(){}
	static CGame* pStaticGame;
};

#endif // __GAME_H__

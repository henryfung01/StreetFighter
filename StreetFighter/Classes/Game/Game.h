/*这个文件是独立于cocos逻辑的一个游戏模块，所有
跟game play 相关的逻辑都可以在内部创建实例*/
#ifndef __GAME_H__
#define __GAME_H__
class CGameStateManager;
class CGame
{    
protected:
	virtual ~CGame(){}
	CGame* GetInstance();
	virtual bool Init();
private:
	CGame(){}
	static CGame* pStaticGame;
	CGameStateManager* m_pGameStateManager;
};

#endif // __GAME_H__

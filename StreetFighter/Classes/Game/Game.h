/*这个文件是独立于cocos逻辑的一个游戏模块，所有
跟game play 相关的逻辑都可以在内部创建实例*/
#ifndef __GAME_H__
#define __GAME_H__
class CGameStateManager;
class CGameStateBase;
class CGame
{    
public:
	static CGame* GetInstance();
	CGameStateBase* GetGameState(int gameState);
protected:
	virtual ~CGame(){}
	virtual bool Init();
	CGameStateManager* GetGameStateManager() { return m_pGameStateManager;}
private:
	CGame(){}
	static CGame* pStaticGame;
	CGameStateManager* m_pGameStateManager;
};

#endif // __GAME_H__

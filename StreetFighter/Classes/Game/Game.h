/*����ļ��Ƕ�����cocos�߼���һ����Ϸģ�飬����
��game play ��ص��߼����������ڲ�����ʵ��*/
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

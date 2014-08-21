/*����ļ��Ƕ�����cocos�߼���һ����Ϸģ�飬����
��game play ��ص��߼����������ڲ�����ʵ��*/
#ifndef __GAME_H__
#define __GAME_H__
class CGameStateManager;
class CGameStateBase;
class CLoadingScene;
class CEntitySystem;
class CActorManager;
class CStringInfoManager;
class CGame
{    
public:
	static CGame* GetInstance();
	CGameStateBase* GetGameState(int gameState);
	CGameStateManager* GetGameStateManager() { return m_pGameStateManager;}
	CLoadingScene* GetLoadingScene() { return m_pLoadingScene;}
	CEntitySystem* GetEntitySystem() { return m_pEntitySystem;}
	CActorManager* GetActorManager() { return m_pActorManager;}
	CStringInfoManager* GetStringManager(){ return m_pStringInfoManager;}
protected:
	virtual ~CGame(){}
	virtual bool Init();
private:
	CGame(){}
	static CGame* pStaticGame;
	CGameStateManager* m_pGameStateManager;
	CLoadingScene* m_pLoadingScene;
	CEntitySystem* m_pEntitySystem;
	CActorManager* m_pActorManager;
	CStringInfoManager* m_pStringInfoManager;
};

#endif // __GAME_H__

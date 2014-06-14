/*����ļ��Ƕ�����cocos�߼���һ����Ϸģ�飬����
��game play ��ص��߼����������ڲ�����ʵ��*/
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

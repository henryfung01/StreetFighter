/*����ļ��Ƕ�����cocos�߼���һ����Ϸģ�飬����
��game play ��ص��߼����������ڲ�����ʵ��*/
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

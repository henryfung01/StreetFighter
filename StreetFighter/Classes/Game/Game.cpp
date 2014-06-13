#include "Game.h"
CGame* CGame::pStaticGame = NULL;
CGame* CGame::GetInstance()
{
	if(!pStaticGame)
	{
		pStaticGame = new CGame();
	}
	return pStaticGame;
}

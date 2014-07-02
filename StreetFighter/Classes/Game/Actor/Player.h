#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Actor.h"
class CPlayer:public CActor 
{    
public:
	CPlayer();
	virtual ~CPlayer(){}
	//create cocos resource
	virtual bool init();
};

#endif // __PLAYER_H__

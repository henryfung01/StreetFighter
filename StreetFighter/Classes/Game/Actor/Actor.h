#ifndef __ACTOR_H__
#define __ACTOR_H__
#include "../BaseClass/Entity.h"
#include "cocostudio/CCArmature.h"
class cocostudio::Armature;
class CActor:public CEntity
{    
public:
	CActor();
	virtual ~CActor(){}
	//create cocos resource
	virtual bool init();
private:
	cocostudio::Armature* m_pArmature;
};

#endif // __ACTOR_H__

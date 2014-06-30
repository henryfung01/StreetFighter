#ifndef __MOVEMENT_CONTROLLER_H__
#define __MOVEMENT_CONTROLLER_H__
#include "../BaseClass/Component.h"
class CMovement:public CComponent
{    
public:
	CMovement(CEntity* pEntity);
	virtual ~CMovement(){}
	//create cocos resource
	virtual bool init();
	CREATE_FUNC_EX(CMovement);
	bool GetIgnoreBlock(){ return m_bIgnoreBlock;}
	void SetIgnoreBlcok(bool ignore) { m_bIgnoreBlock = ignore;}
public: 
	
private:
	float m_fSpeedX;
	float m_fSpeedY;
	float m_fSpeedH; //height ,an additive Y
	float m_fGravity;
	bool m_bIgnoreBlock;
};

#endif // __MOVEMENT_CONTROLLER_H__

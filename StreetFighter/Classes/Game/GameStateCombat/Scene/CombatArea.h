#ifndef __COMBAT_AREA_H__
#define __COMBAT_AREA_H__
//whitebai 2014.8.9
#include "CCGeometry.h"
struct EntityPos;
enum GridMulNumber
{
	GridMulPositive = 1,
	GridMulNegative = -1
};
struct GridInfo
{
	byte bUsed;
	GridInfo()
	{
		bUsed = false;
	}
};
class CCombatArea
{
public:
    CCombatArea();
	virtual ~CCombatArea();
	void SetAreaRect(const cocos2d::Rect& BottomLeft,const cocos2d::Rect& TopRight);
	cocos2d::Point TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize );
	bool ParseRect();
private:
	GridInfo* m_AreaGridInfo;
	//最大支持255*255个格子
	byte m_GridXCount;
	byte m_GridYCount;
	//右上相对于左下的坐标正负，取值为1和-1
	char m_GridXMulNum;
	char m_GridYMulNum;
	cocos2d::Point m_BeginPoint;
};

#endif // __LOADING_SCENE_H__

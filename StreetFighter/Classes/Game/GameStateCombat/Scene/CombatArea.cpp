#include "CombatArea.h"
USING_NS_CC;
#include "Common/CommonDef.h"
#include "Common/GamePos.h"

void CCombatArea::SetAreaRect( const cocos2d::Rect& BottomLeft,const cocos2d::Rect& TopRight )
{
	int beginX = (int)(BottomLeft.getMidX()/(float)MAPGRIDSIZE);
	int beginY = (int)(BottomLeft.getMidY()/(float)MAPGRIDSIZE);
	int endX = (int)(TopRight.getMidX()/(float)MAPGRIDSIZE);
	int endY = (int)(TopRight.getMidY()/(float)MAPGRIDSIZE);
	m_BeginPoint.x = beginX*MAPGRIDSIZE;
	m_BeginPoint.y = beginY*MAPGRIDSIZE;
	int deltaX = endX - beginX;
	m_GridXMulNum = deltaX < 0 ? GridMulNegative : GridMulPositive;
	m_GridXCount = deltaX * m_GridXMulNum + 1;
	int deltaY = endY - beginY;
	m_GridYMulNum = deltaY < 0 ? GridMulNegative : GridMulPositive;
	m_GridYCount = deltaY * m_GridYMulNum + 1;
	//store info by row
	m_AreaGridInfo = new GridInfo[m_GridXCount*m_GridYCount];
}

bool CCombatArea::ParseRect()
{
	//向下取整得到初始位置，rect只是一个大概标识
	return true;
}

CCombatArea::CCombatArea():
m_AreaGridInfo(nullptr)
{

}

cocos2d::Point CCombatArea::TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize )
{
	//渲染转换不考虑Y方向，X方向考虑
	//y就是从底部算起，X轴从中间算起
	float tempX = pos.x + (float)entitySize.x/2.0f;
	return m_BeginPoint + Point(tempX*m_GridXMulNum*MAPGRIDSIZE,pos.y*m_GridYMulNum*MAPGRIDSIZE);
}

CCombatArea::~CCombatArea()
{
	if(m_AreaGridInfo)
	{
		delete[] m_AreaGridInfo; 
	}
}

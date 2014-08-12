#include "CCTMXTiledMap.h"
#include "CCStdC.h"
USING_NS_CC;
#include "CombatArea.h"
#include "Common/CommonDef.h"
#include "Common/GamePos.h"
#define  OBJGROUPNAME "Objects"
#define  LEFTBOTTOMRECTNAME "LeftBottom"
#define  RIGHTTOPRECTNAME "RightTop"
#define  RECTX "x"
#define  RECTY "y"
#define  RECTWIDTH "width"
#define  RECTHEIGHT "height"
void CCombatArea::SetAreaRect( const cocos2d::Rect& LeftBottom,const cocos2d::Rect& RightTop )
{
	int beginX = (int)(LeftBottom.getMidX()/(float)MAPGRIDSIZE);
	int beginY = (int)(LeftBottom.getMidY()/(float)MAPGRIDSIZE);
	int endX = (int)(RightTop.getMidX()/(float)MAPGRIDSIZE);
	int endY = (int)(RightTop.getMidY()/(float)MAPGRIDSIZE);
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

bool CCombatArea::Init( TMXTiledMap* map )
{
	if(map)
	{
		TMXObjectGroup* pGroup = map->getObjectGroup(OBJGROUPNAME);
		if(pGroup)
		{
			ValueMap values = pGroup->getObject(LEFTBOTTOMRECTNAME);
			Rect leftBottom = _ReadRectFromValueMap(values);
			values = pGroup->getObject(RIGHTTOPRECTNAME);
			Rect rightTop = _ReadRectFromValueMap(values);
			SetAreaRect(leftBottom,rightTop);
			return true;
		}
	}
	return false;
}

cocos2d::Rect CCombatArea::_ReadRectFromValueMap(const ValueMap& map)
{
	ValueMap::const_iterator it = map.find(RECTX);
	float rectX = it->second.asFloat();
	it = map.find(RECTY);
	float recty = it->second.asFloat();
	it = map.find(RECTWIDTH);
	float width = it->second.asFloat();
	it = map.find(RECTHEIGHT);
	float height = it->second.asFloat();
	return Rect(rectX,recty,width,height);
}

const GridInfo& CCombatArea::GetGridInfo( int row,int column )
{
	row = MAX(row,m_GridXCount-1);
	column = MAX(column,m_GridYCount-1);
	return m_AreaGridInfo[row*m_GridYCount+column];
}

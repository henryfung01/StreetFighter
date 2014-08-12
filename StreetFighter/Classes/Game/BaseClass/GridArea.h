#ifndef __GRID_AREA_H__
#define __GRID_AREA_H__
//whitebai 2014.8.10
//convert the grid position to render position
struct EntityPos;
#include "CCGeometry.h"
class CGridArea
{
public:
	CGridArea(){}
	virtual ~CGridArea(){}
	//should implement the interface
	virtual cocos2d::Point TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize ) = 0;
};
#endif // __GRID_AREA_H__

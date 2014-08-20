#ifndef __GRID_AREA_H__
#define __GRID_AREA_H__
//whitebai 2014.8.10
//convert the grid position to render position
struct EntityPos;
#include "math/CCGeometry.h"
struct MoveProcessReq
{
	EntityPos pos;
	EntityPos size;
	byte stepCount;
};
class CGridArea:public cocos2d::Ref
{
public:
	CGridArea(){}
	virtual ~CGridArea(){}
	//should implement the interface
	virtual cocos2d::Point TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize ) = 0;
	virtual bool ProcessMoveInfo(const MoveProcessReq& req) = 0;
	virtual int GetDirByPos(const EntityPos& targetPos,EntityPos* posArray,int arraySize) = 0;
	virtual	const EntityPos TransToGridPos(cocos2d::Point& RenderPos) = 0;
};
#endif // __GRID_AREA_H__

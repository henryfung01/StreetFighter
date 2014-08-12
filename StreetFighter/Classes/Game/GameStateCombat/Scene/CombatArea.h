#ifndef __COMBAT_AREA_H__
#define __COMBAT_AREA_H__
//whitebai 2014.8.9
#include "CCGeometry.h"
namespace cocos2d
{
	class SpriteBatchNode;
}
#include "CCTMXTiledMap.h"
#include "CCValue.h"
#include "Game/BaseClass/GridArea.h"
#include "Common/GamePos.h"
enum GridMulNumber
{
	GridMulPositive = 1,
	GridMulNegative = -1
};
struct GridMoveInfo
{
	EntityPos parent;
	int cost;
	bool processed;
	GridMoveInfo():
	parent(0,0),
	cost(0),
	processed(false)
	{
	}
};
struct MoveProcessReq
{
	EntityPos pos;
	EntityPos size;
	byte move;
};
struct GridInfo
{
	byte bUsed;
	GridMoveInfo* pMoveInfo;
	GridInfo()
	{
		bUsed = false;
		pMoveInfo = nullptr;
	}
};
class CCombatArea:public CGridArea
{
public:
    CCombatArea();
	virtual ~CCombatArea();
	bool Init(cocos2d::TMXTiledMap* map);
	void SetAreaRect(const cocos2d::Rect& LeftBottom,const cocos2d::Rect& RightTop);
	cocos2d::Point TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize );
	bool ParseRect();
	inline const GridInfo& GetConstGridInfo(int row,int column);
	
	bool ProcessMoveInfo(const MoveProcessReq& req);
private:
	inline GridInfo& _GetGridInfo(int row,int column);
	bool _GetValidGridInfo(GridInfo& gridInfo,const EntityPos& pos,int deltaRow,int deltaColumn);
	cocos2d::Rect _ReadRectFromValueMap(const cocos2d::ValueMap& map);
	GridInfo* m_AreaGridInfo;
	//最大支持255*255个格子
	byte m_GridXCount;
	byte m_GridYCount;
	//右上相对于左下的坐标正负，取值为1和-1
	char m_GridXMulNum;
	char m_GridYMulNum;
	cocos2d::Point m_BeginPoint;
	cocos2d::SpriteBatchNode* m_pMoveArea;
	MoveProcessReq m_lastReq;
};

#endif // __LOADING_SCENE_H__

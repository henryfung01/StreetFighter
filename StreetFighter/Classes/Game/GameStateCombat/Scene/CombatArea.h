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
	byte stepCount;
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
	typedef std::vector<EntityPos> PosVector;
    CCombatArea();
	virtual ~CCombatArea();
	bool Init(cocos2d::TMXTiledMap* map);
	void SetAreaRect(const cocos2d::Rect& LeftBottom,const cocos2d::Rect& RightTop);
	cocos2d::Point TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize );
	bool ParseRect();
	inline const GridInfo& GetConstGridInfo(byte row,byte column);
	
	bool ProcessMoveInfo(const MoveProcessReq& req);
private:
	void _UpdateOpenList(const EntityPos& possiableParent, const EntityPos& checkPos,const EntityPos& size,bool checkAxisX,PosVector& openlist);
	inline bool _CheckValid(byte row,byte column);
	inline GridInfo& _GetGridInfo(byte row,byte column);
	bool _CheckPosValid(const EntityPos& pos,const EntityPos& size);
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

#include "CCTMXTiledMap.h"
#include "CCStdC.h"
#include "CCDrawNode.h"
#include "CCDirector.h"
#include "CCScheduler.h"
USING_NS_CC;
#include "Common/GamePos.h"
#include "CombatArea.h"
#include "Common/CommonDef.h"
#include "Game/Game.h"
#include "Game/GameStateManager.h"
#include "Game/BaseClass/GameStateBase.h"
#include "Game/BaseClass/GameScene.h"
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
m_AreaGridInfo(nullptr),
m_curAlpha(0.0f)
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
			m_pDrawNode = DrawNode::create();
			CGameStateBase* gameState = CGame::GetInstance()->GetGameStateManager()->GetCurrentState();
			CGameScene* pGameScene = gameState->GetGameScene();
			pGameScene->GetEntityContainer()->addChild(m_pDrawNode);
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

const GridInfo& CCombatArea::GetConstGridInfo( byte row,byte column )
{
	return _GetGridInfo(row,column);
}
//采用传说的广度优先算法，把所有可能走到的位置的路径计算出来
bool CCombatArea::ProcessMoveInfo( const MoveProcessReq& req )
{
	PosVector buffer;
	PosVector buffer2;
	PosVector* LastOpenList = &buffer;
	PosVector* CurOpenList = &buffer2;
	//store the req
	memcpy(&m_lastReq,&req,sizeof(MoveProcessReq));
	GridInfo& info = _GetGridInfo(req.pos.x,req.pos.y);
	if(!info.pMoveInfo)
	{
		info.pMoveInfo = new GridMoveInfo();
		info.pMoveInfo->cost = 0;
		info.pMoveInfo->parent = EntityPos(-1,-1);
		info.pMoveInfo->processed = true;
		LastOpenList->push_back(EntityPos(req.pos.x,req.pos.y));
	}
	for(int i = 0;i<req.stepCount;++i)
	{
		PosVector::const_iterator it = LastOpenList->begin();
		for(;it!=LastOpenList->end();++it)
		{
			//process up
			EntityPos upPos(it->x,it->y+1);
			_UpdateOpenList(*it,upPos,req.size,false,*CurOpenList);
			//process right
			EntityPos rightPos(it->x+1,it->y);
			_UpdateOpenList(*it,rightPos,req.size,true,*CurOpenList);
			//process down
			EntityPos downPos(it->x,it->y-1);
			_UpdateOpenList(*it,downPos,req.size,false,*CurOpenList);
			//process left
			EntityPos leftPos(it->x-1,it->y);
			_UpdateOpenList(*it,leftPos,req.size,true,*CurOpenList);

			//after update all the dir,set the point processed
			GridInfo& info = _GetGridInfo(it->x,it->y);
			info.pMoveInfo->processed = true;
		}
		//after update ,swap the open list
		PosVector* temVec = CurOpenList;
		CurOpenList = LastOpenList;
		LastOpenList = temVec;
		CurOpenList->resize(0);
	}
	 Director::getInstance()->getScheduler()->schedule(schedule_selector(CCombatArea::DrawMoveInfo), this, 0.1f , false);
	return true;
}

GridInfo& CCombatArea::_GetGridInfo( byte row,byte column )
{
	row = MIN(row,m_GridXCount-1);
	column = MIN(column,m_GridYCount-1);
	return m_AreaGridInfo[row*m_GridYCount+column];
}

bool CCombatArea::_CheckValid( byte row,byte column )
{
	if(row >= 0 && row <m_GridXCount && column >=0 && column < m_GridYCount)
	{
		GridInfo& info = _GetGridInfo(row,column);
		if(!info.bUsed)
		{
			return true;	
		}
	}
	return false;
}

bool CCombatArea::_CheckPosValid( const EntityPos& pos,const EntityPos& size)
{
	int destX = pos.x ;
	int destY = pos.y ;
	for(int i = 0;i<size.x;++i)
	{
		for(int j=0;j<size.y;++j)
		{
			if(!_CheckValid(destX+i,destY+j))
				return false;
		}
	}
	return true;
}

void CCombatArea::_UpdateOpenList( const EntityPos& possiableParent, const EntityPos& checkPos,const EntityPos& size,bool checkAxisX,PosVector& openlist )
{
	//first check this position can stand the entity
	if(_CheckPosValid(checkPos,size))
	{
		//get possible parent gird info
		const GridInfo& parentInfo = GetConstGridInfo(possiableParent.x,possiableParent.y);
		int cost = parentInfo.pMoveInfo->cost + 100;
		//one corner will increase 1
		if(checkAxisX)
		{
			if(parentInfo.pMoveInfo->parent.x != possiableParent.x) 
			{
				cost += 1;
			}
		}
		else
		{
			if(parentInfo.pMoveInfo->parent.y != possiableParent.y) 
			{
				cost += 1;
			}
		}
		GridInfo& info = _GetGridInfo(checkPos.x,checkPos.y);
		//certainly not processed
		if(!info.pMoveInfo)
		{
			//push up pos in open list
			openlist.push_back(checkPos);
			info.pMoveInfo = new GridMoveInfo();
			//set parent
			info.pMoveInfo->parent = possiableParent;
			//one step will cost 100
			info.pMoveInfo->cost = cost;
		}
		//only not processed grid can update the info
		else if(!info.pMoveInfo->processed)
		{
			//current cost smaller than last one
			if(cost < info.pMoveInfo->cost)
			{
				//will not push to open list ,the pMoveInfo is not null means it already be pushed
				//set parent
				info.pMoveInfo->parent = possiableParent;
				//one step will cost 100
				info.pMoveInfo->cost = cost;
			}
		}
	}
}

void CCombatArea::_DrawGrid( byte row,byte column ,float alpha)
{
	Point rectangle[4];
	float beginX = m_BeginPoint.x +row*MAPGRIDSIZE*m_GridXMulNum;
	float beginY = m_BeginPoint.y +column*MAPGRIDSIZE*m_GridYMulNum;
	rectangle[0] = Point(beginX+1,beginY+1);  //left bottom
	rectangle[1] = Point(beginX+MAPGRIDSIZE-1,beginY+1 );  //right bottom
	rectangle[2] = Point(beginX+MAPGRIDSIZE-1,beginY+MAPGRIDSIZE-1);  //right top
	rectangle[3] = Point(beginX+1,beginY+MAPGRIDSIZE-1);  //left top
	Color4F green(0,1,0,alpha);
	Color4F white(1, 1, 1, alpha);
	m_pDrawNode->drawPolygon(rectangle, 4, green, 1, white);
}

void CCombatArea::DrawMoveInfo(float dt)
{
	static float inc = 1.0f;
	m_curAlpha += 0.03f*inc;
	if(m_curAlpha >= 0.4f)
	{
		inc = -1.0f;
	}
	else if(m_curAlpha <= 0.1f)
	{
		inc = 1.0f;
		m_curAlpha = 0.1f;
	}
	m_pDrawNode->clear();
	for(int row=0;row<m_GridXCount;++row)
	{
		for(int column=0;column<m_GridYCount;++column)
		{
			const GridInfo& gridInfo = GetConstGridInfo(row,column);
			if(gridInfo.pMoveInfo && gridInfo.pMoveInfo->processed)
			{
				_DrawGrid(row,column,m_curAlpha);
			}
		}
	}
}

int CCombatArea::GetDirByPos( const EntityPos& targetPos,EntityPos* posArray,int arraySize )
{
	const GridInfo& targetInfo = GetConstGridInfo(targetPos.x,targetPos.y);
	int index = 0;
	if(targetInfo.pMoveInfo && targetInfo.pMoveInfo->processed)  //存在路径
	{
		EntityPos curPos = targetPos;
		const EntityPos endPos(-1,-1);
		while (curPos.x != -1 && index < arraySize)  //that means arrive start point
		{
			posArray[index++] = curPos;
			const GridInfo& curGridInfo = GetConstGridInfo(curPos.x,curPos.y);
			curPos = curGridInfo.pMoveInfo?curGridInfo.pMoveInfo->parent:endPos;
		}
	}
	return index;
}

const EntityPos CCombatArea::TransToGridPos( Point& RenderPos )
{
	EntityPos pos;
	Point deltaP = RenderPos - m_BeginPoint;
	pos.x = deltaP.x / m_GridXMulNum*MAPGRIDSIZE;
	pos.y = deltaP.y / m_GridYMulNum*MAPGRIDSIZE;
	return pos;
}

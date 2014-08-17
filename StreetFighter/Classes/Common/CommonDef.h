#ifndef _SCENE_TYPE_H
#define _SCENE_TYPE_H
enum SceneType
{
	SceneType_Welcome = 0,
	SceneType_Town = 1,
	SceneType_Combat = 2,
};

enum GameStateType
{
	GameStateType_None = -1,
	GameStateType_Begin = 0,
	GameStateType_Login,
	GameStateType_ActorSelect,
	GameStateType_Town,
	GameStateType_Combat,
	GameStateType_Count,
};

enum ComponentType
{
	CComponentType_None = -1,
	CComponentType_Move,
	CComponentType_Rotate,
	CComponentType_BaseCount,
};
enum EntityType
{
	EntityType_None = 0,
	EntityType_Actor,
	EntityType_Player,
	EntityType_Enemy,
	EntityType_Item,
	EntityType_Block,
	EntityType_Count,
};
#define SAFE_RELEASE(p) do{ if(p){p->release();}}while(0)
#define MAPGRIDSIZE 32  //one actor will stand on a grid 64*64,but when move ,can use 32 as a element
#define MAXMAPSIZE 50   //1600*1600 pixel
typedef unsigned int EntityId;
#define Invalid_Id 0
#endif
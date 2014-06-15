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
#endif
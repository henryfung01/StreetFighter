//whitebai 2014.6.8
#ifndef _COMBAT_COMMON_DEFINE_H_
#define _COMBAT_COMMON_DEFINE_H_
//Gesture recognize relative
#define MAX_RECONGNIZE_SIZE 64

enum QTEGestureType
{
	QTEGestureType_None = -1,
	QTEGestureType_Rect = 0,
	QTEGestureType_RectCC,
	QTEGestureType_Circle,
	QTEGestureType_CircleCC,
	QTEGestureType_Left,
	QTEGestureType_Right,
	QTEGestureType_Up,
	QTEGestureType_Down,
	QTEGestureType_Triangle,
	QTEGestureType_TriangleCC,
	QTEGestureType_V,
	QTEGestureType_W,
	QTEGestureType_N,
	QTEGestureType_Z,
	QTEGestureType_M,
	QTEGestureType_Count,
};
#endif
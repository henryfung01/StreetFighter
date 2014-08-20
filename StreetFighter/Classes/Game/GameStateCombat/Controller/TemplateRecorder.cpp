#include "TemplateRecorder.h"
#include "ui\UIButton.h"
#include "Common/CommonDef.h"
#include "../Controller/Recognizer/GeometricRecognizer.h"
USING_NS_CC;
using namespace DollarRecognizer;
//use 40 point
Path2D CTemplateRecorder::OutputRectange()
{
	Path2D path;
	path.resize(40);
	int curIndex = 0;
	//left edge
	//four points 
	//left bottom 0,0
	//left top 0,100
	//right top 100,100
	//right bottom 100,0
	for(int i=0;i<10;++i)  //left bottom to left top
	{
		path[curIndex].x = 0.0f;
		path[curIndex].y = i*10.0f; 
		curIndex ++;
	}
	for(int i=0;i<10;++i) //left top to right top
	{
		path[curIndex].x = i*10.0f;
		path[curIndex].y = 100.0f; 
		curIndex ++;
	}
	for(int i=0;i<10;++i)  //right top to right bottom
	{
		path[curIndex].x = 100.0f;
		path[curIndex].y = 100.0f - i*10.0f;
		curIndex ++;
	}
	for(int i=0;i<10;++i)
	{
		path[curIndex].x = 100.0f - i*10.0f;
		path[curIndex].y = 0.0f; 
		curIndex ++;
	}
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputRectangeCC()
{
	Path2D path;
	path.resize(40);
	int curIndex = 0;
	//left edge
	//four points 
	//left bottom 0,0
	//left top 0,100
	//right top 100,100
	//right bottom 100,0
	for(int i=0;i<10;++i)  //left bottom to right bottom
	{
		path[curIndex].x = i*10.0f;
		path[curIndex].y = 0.0f; 
		curIndex ++;
	}
	for(int i=0;i<10;++i) //right bottom to right top
	{
		path[curIndex].x = 100.0f;
		path[curIndex].y = i*10.0f; 
		curIndex ++;
	}
	for(int i=0;i<10;++i)  //right top to left top
	{
		path[curIndex].x = 100.0f - i*10.0f;
		path[curIndex].y = 100.0f; 
		curIndex ++;
	}
	for(int i=0;i<10;++i)//left top to left bottom
	{
		path[curIndex].x = 0.0f;
		path[curIndex].y = 100.0f-i*10.0f;
		curIndex ++;
	}
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputCircle()
{
	Path2D path;
	path.resize(64);
/*	kmVec2 vec;
	kmVec2Fill(&vec,0.0f,50.0f);
	kmVec2 center;
	kmVec2Fill(&center,100.0f,100.0f);
	int index = 0;
	kmVec2 currentPoint;
	for(int i =64;i> 0;--i)
	{
		kmVec2RotateBy(&currentPoint,&vec,i*5.625f,&center);
		path[index].x = currentPoint.x;
		path[index].y = currentPoint.y;
		index++;
	} */
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputCircleCC()
{
	Path2D path;
	path.resize(64);
/*	kmVec2 vec;
	kmVec2Fill(&vec,0.0f,50.0f);
	kmVec2 center;
	kmVec2Fill(&center,100.0f,100.0f);
	int index = 0;
	kmVec2 currentPoint;
	for(int i =0;i< 64;++i)
	{
		kmVec2RotateBy(&currentPoint,&vec,i*5.625f,&center);
		path[index].x = currentPoint.x;
		path[index].y = currentPoint.y;
		index++;
	}  */
	return path;
}
//use 32 points
DollarRecognizer::Path2D CTemplateRecorder::OutputTriangle()
{
	Path2D path;
	path.resize(32);
/*	//设置3个关键点，每条边长度为100，左下角在(0,0)
	path[0].x = 0.0f;
	path[0].y = 0.0f;
	//右下角则为 (100,0)
	path[22].x = 100.0f;
	path[22].y = 0.0f;
	//计算上顶点
	kmVec2 vec;
	kmVec2Fill(&vec,100.0f,0.0f);
	//逆时针旋转60度则为上顶点
	kmVec2 upPoint;
	kmVec2 center;
	kmVec2Fill(&center,0.0f,0.0f);
	kmVec2RotateBy(&upPoint,&vec,60.0f,&center);
	path[11].x = upPoint.x;
	path[11].y = upPoint.y;
	//在左侧边插入10个点
	kmVec2 dir;
	dir.x = (path[11].x - path[0].x)/11.0f;
	dir.y = (path[11].y - path[0].y)/11.0f;
	for(int i =1;i<11;++i)
	{
		path[i].x = path[0].x + i*dir.x;
		path[i].y = path[0].y + i*dir.y;
	}
	//右边插入10个点
	dir.x = (path[22].x - path[11].x)/11.0f;
	dir.y = (path[22].y - path[11].y)/11.0f;
	for(int i =12;i<22;++i)
	{
		int j = i - 11;
		path[i].x = path[11].x + j*dir.x;
		path[i].y = path[11].y + j*dir.y;
	}
	//底边插入9个点
	dir.x = (path[0].x - path[22].x)/10.0f;
	dir.y = (path[0].y - path[22].y)/10.0f;
	for(int i =23;i<32;++i)
	{
		int j = i - 22;
		path[i].x = path[22].x + j*dir.x;
		path[i].y = path[22].y + j*dir.y;
	}  */
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputTriangleCC()
{
	Path2D path;
	path.resize(32);
	//设置3个关键点，每条边长度为100，左下角在(0,0)
/*	path[0].x = 0.0f;
	path[0].y = 0.0f;
	//右下角则为 (100,0)
	path[10].x = 100.0f;
	path[10].y = 0.0f;
	//计算上顶点
	kmVec2 vec;
	kmVec2Fill(&vec,100.0f,0.0f);
	//逆时针旋转60度则为上顶点
	kmVec2 upPoint;
	kmVec2 center;
	kmVec2Fill(&center,0.0f,0.0f);
	kmVec2RotateBy(&upPoint,&vec,60.0f,&center);
	path[21].x = upPoint.x;
	path[21].y = upPoint.y;
	//底边插入9个点
	kmVec2 dir;
	dir.x = (path[10].x - path[0].x)/10.0f;
	dir.y = (path[10].y - path[0].y)/10.0f;
	for(int i =1;i<10;++i)
	{
		path[i].x = path[0].x + i*dir.x;
		path[i].y = path[0].y + i*dir.y;
	}

	//右边插入10个点
	dir.x = (path[21].x - path[10].x)/11.0f;
	dir.y = (path[21].y - path[10].y)/11.0f;
	for(int i =11;i<21;++i)
	{
		int j = i - 10;
		path[i].x = path[10].x + j*dir.x;
		path[i].y = path[10].y + j*dir.y;
	}

	//在左侧边插入10个点
	dir.x = (path[0].x - path[21].x)/11.0f;
	dir.y = (path[0].y - path[21].y)/11.0f;
	for(int i =22;i<32;++i)
	{
		int j = i - 21;
		path[i].x = path[21].x + j*dir.x;
		path[i].y = path[21].y + j*dir.y;
	}   */
	return path;
}

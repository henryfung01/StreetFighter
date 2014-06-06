#include "TemplateRecorder.h"
#include "ui\UIButton.h"
#include "../../Common/CommonDef.h"
#include "../Controller/Recognizer/GeometricRecognizer.h"
USING_NS_CC;
using namespace DollarRecognizer;
//use 40 point
Path2D CTemplateRecorder::OutputRectange()
{
	Path2D path;
	//left edge
	//four points 
	//left bottom 0,0
	//left top 0,100
	//right top 100,100
	//right bottom 100,0
	for(int i=0;i<10;++i)  //left bottom to left top
	{
		path.push_back(Point2D(0.0f,i*10.0f));
	}
	for(int i=0;i<10;++i) //left top to right top
	{
		path.push_back(Point2D(i*10.0f,100.0f));
	}
	for(int i=0;i<10;++i)  //right top to right bottom
	{
		path.push_back(Point2D(100.0f,100.0f - i*10.0f));
	}
	for(int i=0;i<10;++i)
	{
		path.push_back(Point2D(100.0f - i*10.0f,0.0f));
	}
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputRectangeCC()
{
	Path2D path;
	//left edge
	//four points 
	//left bottom 0,0
	//left top 0,100
	//right top 100,100
	//right bottom 100,0
	for(int i=0;i<10;++i)  //left bottom to right bottom
	{
		path.push_back(Point2D(i*10.0f,0.0f));
	}
	for(int i=0;i<10;++i) //right bottom to right top
	{
		path.push_back(Point2D(100.0f,i*10.0f));
	}
	for(int i=0;i<10;++i)  //right top to left top
	{
		path.push_back(Point2D(100.0f - i*10.0f,100.0f));
	}
	for(int i=0;i<10;++i)//left top to left bottom
	{
		path.push_back(Point2D(0.0f,100.0f-i*10.0f));
	}
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputCircle()
{
	Path2D path;
	return path;
}

DollarRecognizer::Path2D CTemplateRecorder::OutputCircleCC()
{
	Path2D path;
	return path;
}

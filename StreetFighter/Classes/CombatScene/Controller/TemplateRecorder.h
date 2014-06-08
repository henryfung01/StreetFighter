#ifndef __TEMPLATE_RECORDER_H__
#define __TEMPLATE_RECORDER_H__

#include "cocos2d.h"
#include "../Controller/Recognizer/GeometricRecognizerTypes.h"
class CTemplateRecorder
{
public:
	//clockwise
   static DollarRecognizer::Path2D OutputRectange();
   //counterclockwise
   static DollarRecognizer::Path2D OutputRectangeCC();
   //clockwise
   static DollarRecognizer::Path2D OutputCircle();
   //counterclockwise 
    static DollarRecognizer::Path2D OutputCircleCC();
    // implement the "static create()" method manually
	static DollarRecognizer::Path2D OutputTriangle();
	static DollarRecognizer::Path2D OutputTriangleCC();
};

#endif // __TEMPLATE_RECORDER_H__

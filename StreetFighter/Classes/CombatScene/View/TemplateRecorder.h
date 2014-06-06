#ifndef __TEMPLATE_RECORDER_H__
#define __TEMPLATE_RECORDER_H__

#include "cocos2d.h"
#include "../Controller/Recognizer/GeometricRecognizerTypes.h"
class CTemplateRecorder
{
public:
    virtual bool init();  
    // a selector callback
	//clockwise
   DollarRecognizer::Path2D OutputRectange();
   //counterclockwise
   DollarRecognizer::Path2D OutputRectangeCC();
   //clockwise
   DollarRecognizer::Path2D OutputCircle();
   //counterclockwise 
    DollarRecognizer::Path2D OutputCircleCC();
    // implement the "static create()" method manually
};

#endif // __TEMPLATE_RECORDER_H__

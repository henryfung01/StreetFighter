#ifndef __COMBAT_INPUT_HANDLER_H__
#define __COMBAT_INPUT_HANDLER_H__
//whitebai 2014.5.22
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "../Recognizer/GeometricRecognizer.h"
//�������Ļ���touch�����Ŀ��֮������ǰ����Ϊ�˷�ֹ����resize����vector��ɵ�Ч
#define MAX_TOUCH_POINT 128
class CCombatInputHandler
{
public:
	CCombatInputHandler();
	virtual ~CCombatInputHandler();
   void OnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
   bool Init();
private:
	DollarRecognizer::Path2D m_InputPath;
	DollarRecognizer::GeometricRecognizer* m_GemertricRecognizer;
	bool m_bCatchingInput;
};

#endif // __COMBAT_INPUT_HANDLER_H__

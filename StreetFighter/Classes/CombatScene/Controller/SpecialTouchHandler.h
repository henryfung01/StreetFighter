#ifndef __SPECIAL_TOUCH_HANDLER_H__
#define __SPECIAL_TOUCH_HANDLER_H__
//whitebai 2014.5.22
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Recognizer/GeometricRecognizer.h"
class CCombatController;
//�������Ļ���touch�����Ŀ��֮������ǰ����Ϊ�˷�ֹ����resize����vector��ɵ�Ч
#define MAX_TOUCH_POINT 128
class CSpTouchHandler
{
public:
	CSpTouchHandler(CCombatController* pOwner);
	virtual ~CSpTouchHandler();
   void OnTouchEvent(cocos2d::Ref *pSender, cocos2d::ui::TouchEventType type);
   bool Init();
private:
	DollarRecognizer::Path2D m_InputPath;
	DollarRecognizer::GeometricRecognizer* m_GemertricRecognizer;
	bool m_bCatchingInput;
	CCombatController* m_pOwner;
};

#endif // __SPECIAL_TOUCH_HANDLER_H__

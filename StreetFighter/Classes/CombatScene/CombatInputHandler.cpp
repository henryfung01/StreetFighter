#include "CombatInputHandler.h"
USING_NS_CC;
#include "../Recognizer/GeometricRecognizer.h"
using namespace ui;
using namespace DollarRecognizer;
void CCombatInputHandler::OnTouchEvent(Ref *pSender, TouchEventType type)
{
	Widget* pUIWidget = static_cast<Widget*>(pSender);
	switch (type)
	{
	case TOUCH_EVENT_BEGAN:
		{
			m_InputPath.clear();
			Point point = pUIWidget->getTouchStartPos();
			Point2D pathPoint(point.x,point.y);
			m_InputPath.push_back(pathPoint);
			m_bCatchingInput = true;
		}
		break;

	case TOUCH_EVENT_MOVED:
		if(m_bCatchingInput)
		{
			Point point = pUIWidget->getTouchMovePos();
			Point2D pathPoint(point.x,point.y);
			m_InputPath.push_back(pathPoint);
		}
		break;

	case TOUCH_EVENT_ENDED:
		{
			RecognitionResult result = m_GemertricRecognizer->recognize(m_InputPath);
			m_bCatchingInput = false;
		}
		
		break;

	case TOUCH_EVENT_CANCELED:
		m_bCatchingInput = false;
		m_InputPath.clear();
		break;

	default:
		break;
	}
}

CCombatInputHandler::CCombatInputHandler():
m_GemertricRecognizer(NULL),
m_bCatchingInput(false)
{

}

CCombatInputHandler::~CCombatInputHandler()
{

}

bool CCombatInputHandler::Init()
{
	//¼ÓÔØÄ£°å
	m_GemertricRecognizer=new GeometricRecognizer();
	m_GemertricRecognizer->loadTemplates();
	return true;
}

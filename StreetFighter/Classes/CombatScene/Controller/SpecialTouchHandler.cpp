#include "SpecialTouchHandler.h"
USING_NS_CC;
#include "Recognizer/GeometricRecognizer.h"
#include "CombatController.h"
using namespace ui;
using namespace DollarRecognizer;
void CSpTouchHandler::OnTouchEvent(Ref *pSender, TouchEventType type)
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
			if(result.name != "Unknown")
			{
				m_pOwner->OnSpecialInput(result.name.c_str());
			}
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

CSpTouchHandler::CSpTouchHandler(CCombatController* pOwner):
m_GemertricRecognizer(NULL),
m_bCatchingInput(false),
m_pOwner(pOwner)
{

}

CSpTouchHandler::~CSpTouchHandler()
{
	CC_SAFE_DELETE(m_GemertricRecognizer);
}

bool CSpTouchHandler::Init()
{
	//加载模板
	//创建的对象实例会在析构函数释放
	m_GemertricRecognizer=new GeometricRecognizer();
	m_GemertricRecognizer->loadTemplates();
	return true;
}

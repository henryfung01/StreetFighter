#include "TemplateRecorder.h"
#include "SpecialTouchHandler.h"
USING_NS_CC;
#include "Recognizer/GeometricRecognizer.h"
#include "CombatController.h"
#include "../CombatCommonDefine.h"
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
	//����ģ��
	//�����Ķ���ʵ���������������ͷ�
	m_GemertricRecognizer=new GeometricRecognizer();
	m_GemertricRecognizer->SetMaxGesturePoints(MAX_RECONGNIZE_SIZE);
	m_GemertricRecognizer->addTemplate("Rect",CTemplateRecorder::OutputRectange());
	m_GemertricRecognizer->addTemplate("RectCC",CTemplateRecorder::OutputRectangeCC());
	m_GemertricRecognizer->addTemplate("Circle",CTemplateRecorder::OutputCircle());
	m_GemertricRecognizer->addTemplate("CircleCC",CTemplateRecorder::OutputCircleCC());
	m_GemertricRecognizer->addTemplate("Triangle",CTemplateRecorder::OutputTriangle());
	m_GemertricRecognizer->addTemplate("TriangleCC",CTemplateRecorder::OutputTriangleCC());
	m_allGesture.resize(QTEGestureType_Count);
	m_allGesture[QTEGestureType_Rect] = m_GemertricRecognizer->normalizePath(CTemplateRecorder::OutputRectange());
	m_allGesture[QTEGestureType_RectCC] =  m_GemertricRecognizer->normalizePath(CTemplateRecorder::OutputRectangeCC());
	m_allGesture[QTEGestureType_Circle] =  m_GemertricRecognizer->normalizePath(CTemplateRecorder::OutputCircle());
	m_allGesture[QTEGestureType_CircleCC] =  m_GemertricRecognizer->normalizePath(CTemplateRecorder::OutputCircleCC());
	return true;
}

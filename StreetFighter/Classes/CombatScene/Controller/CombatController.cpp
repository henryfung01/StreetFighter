#include "SpecialTouchHandler.h"
#include "CombatController.h"
USING_NS_CC;
#include "Recognizer/GeometricRecognizer.h"
using namespace ui;
using namespace DollarRecognizer;
void CCombatController::OnSpecialTouchEvent(Ref *pSender, TouchEventType type)
{
	m_SpTouchHandler.OnTouchEvent(pSender,type);
}

CCombatController::CCombatController():
m_SpTouchHandler(this)
{

}

CCombatController::~CCombatController()
{

}

bool CCombatController::init()
{
	m_SpTouchHandler.Init();
	return true;
}

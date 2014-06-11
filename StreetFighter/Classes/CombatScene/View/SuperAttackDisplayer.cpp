#include "SuperAttackDisplayer.h"
#include "ui\UIButton.h"
#include "../../Common/CommonDef.h"
#include "../Controller/CombatController.h"
#include "../CombatScene.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "CCDrawNode.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool CSuperAttackDisplayer::init()
{
	m_pDrawNode = cocos2d::DrawNode::create();
	return true;
}

void CSuperAttackDisplayer::DrawTriangle()
{
	Point points[] = { Point(0.0f,0.0f), Point(100.0f,100.0f), Point(100.0f,0.0f) };
	m_pDrawNode->drawPolygon(points, sizeof(points)/sizeof(points[0]), Color4F(1,0,0,0.5), 4, Color4F(0,0,1,1));
}

void CSuperAttackDisplayer::visit( Renderer *renderer, const kmMat4 &parentTransform, bool parentTransformUpdated )
{

}

void CSuperAttackDisplayer::PostInit()
{
	Node* pParent = getParent();
	if(pParent)
	{
		pParent->addChild(m_pDrawNode);
	}
	else
	{
		if(getScene())
		{
			getScene()->addChild(m_pDrawNode);	
		}
	}
	DrawTriangle();
}

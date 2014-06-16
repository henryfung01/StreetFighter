#include "SuperAttackDisplayer.h"
#include "ui\UIButton.h"
#include "../../../Common/CommonDef.h"
#include "../Controller/CombatController.h"
#include "../Scene/CombatScene.h"
#include "editor-support/cocostudio/CCSGUIReader.h"
#include "CCDrawNode.h"
USING_NS_CC;
using namespace ui;

// on "init" you need to initialize your instance
bool CSuperAttackDisplayer::init()
{
	m_pDrawNode = cocos2d::DrawNode::create();
	m_pRunPoints[0] = Sprite::createWithSpriteFrameName("btn-a-0.png");
	m_pRunPoints[1] = Sprite::createWithSpriteFrameName("btn-a-1.png");
	m_pRunPoints[2] = Sprite::createWithSpriteFrameName("btn-a-2.png");
	m_pRunPoints[3] = Sprite::createWithSpriteFrameName("btn-b-2.png");
	m_pRunPoints[4] = Sprite::createWithSpriteFrameName("btn-b-2.png");
	m_pRunPoints[5] = Sprite::createWithSpriteFrameName("btn-b-2.png");
	if(m_pRunPoints[0] && m_pRunPoints[0]->getTexture())
	{
		initWithTexture(m_pRunPoints[0]->getTexture(),0);
		addChild(m_pRunPoints[0]);
	}
	for(int i=1;i<6;++i)
	{
		if(m_pRunPoints[i])
		{
			addChild(m_pRunPoints[i]);
		}
	}
	return true;
}

void CSuperAttackDisplayer::DrawTriangle()
{
	Point points[] = { Point(0.0f,0.0f), Point(100.0f,100.0f), Point(100.0f,0.0f) };
	m_pDrawNode->drawSegment(points[0],points[1],4.0f,Color4F(1,0,0,0.5));
	m_pDrawNode->drawSegment(points[1],points[2],4.0f,Color4F(1,0,0,0.5));
	m_pDrawNode->drawSegment(points[2],points[0],4.0f,Color4F(1,0,0,0.5));
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

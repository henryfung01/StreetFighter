#ifndef __SUPER_ATTACK_DISPLAYER_H__
#define __SUPER_ATTACK_DISPLAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CCSpriteBatchNode.h"
#include "../Controller/Recognizer/GeometricRecognizerTypes.h"
class cocos2d::DrawNode;
//继承batchnode用来批量绘制旋转亮点
class CSuperAttackDisplayer : public cocos2d::SpriteBatchNode
{
public:
    virtual bool init(); 
	virtual void PostInit();
    // implement the "static create()" method manually
    CREATE_FUNC(CSuperAttackDisplayer);
	virtual void DrawTriangle();
	virtual void SetDrawPath(const DollarRecognizer::Path2D* path) { m_DrawingPath = path;}
private:
	cocos2d::DrawNode* m_pDrawNode;
	cocos2d::Sprite* m_pRunPoints[6];
	const DollarRecognizer::Path2D* m_DrawingPath;
};

#endif // __SUPER_ATTACK_DISPLAYER_H__

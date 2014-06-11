#ifndef __SUPER_ATTACK_DISPLAYER_H__
#define __SUPER_ATTACK_DISPLAYER_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "CCSpriteBatchNode.h"
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
	virtual void visit(cocos2d::Renderer *renderer, const kmMat4 &parentTransform, bool parentTransformUpdated);
private:
	cocos2d::DrawNode* m_pDrawNode;
};

#endif // __SUPER_ATTACK_DISPLAYER_H__

#ifndef __COMMON_VIEW_H__
#define __COMMON_VIEW_H__
#include "cocos2d.h"
#include "ui/CocosGUI.h"
class CCommonView : public cocos2d::Node
{    
protected:
	CCommonView();
	cocos2d::Layer* m_pUILayer;
	cocos2d::ui::Widget* GetChildByNameRecursive(const char* childName,int childDepth);
private:
	//递归通过名字寻找控件的函数，可以设置递归层数，一般控件到一定层级就会很复杂，寻找效率低，而程序关注的往往是比较高层级的控件
	//函数结束条件有三个，寻找到控件，递归层级耗尽依然没有找到，全部child都没有找到
	cocos2d::ui::Widget* _GetChildByName(cocos2d::Node*pNode,const char* name,int childDepth);
	cocos2d::ui::Widget* _CastToWidget(cocos2d::Node* pNode);
};

#endif // __COMMON_VIEW_H__

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
	//�ݹ�ͨ������Ѱ�ҿؼ��ĺ������������õݹ������һ��ؼ���һ���㼶�ͻ�ܸ��ӣ�Ѱ��Ч�ʵͣ��������ע�������ǱȽϸ߲㼶�Ŀؼ�
	//��������������������Ѱ�ҵ��ؼ����ݹ�㼶�ľ���Ȼû���ҵ���ȫ��child��û���ҵ�
	cocos2d::ui::Widget* _GetChildByName(cocos2d::Node*pNode,const char* name,int childDepth);
	cocos2d::ui::Widget* _CastToWidget(cocos2d::Node* pNode);
};

#endif // __COMMON_VIEW_H__

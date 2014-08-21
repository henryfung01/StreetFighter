#include "CommonView.h"
#include "CommonDef.h"
USING_NS_CC;
using namespace ui;



Widget* CCommonView::GetChildByNameRecursive( const char* childName,int childDepth )
{
	return _GetChildByName(this,childName,childDepth);
}

CCommonView::CCommonView()
{

}

Widget* CCommonView::_GetChildByName(Node*pNode,const char* name,int childDepth)
{
	//����Ѱ�ұ����child
	if(!pNode || pNode->getChildrenCount() <= 0)
		return nullptr;
	const cocos2d::Vector<Node*>& nodeChilden = pNode->getChildren();
	for (auto& child : nodeChilden)
	{
		if (child)
		{
			Widget* widgetChild = _CastToWidget(child);
			if (widgetChild)
			{
				if (strcmp(widgetChild->getName().c_str(), name) == 0)
				{
					return widgetChild;
				}
			}
		}
	}
	//Ȼ���ÿ��child���ø�Ѱ�ҷ�����ͬʱ�ݹ������һ���������Ϊ0��ֹͣ�ݹ飬ֱ�ӷ���
	childDepth --;
	if(childDepth <= 0)
		return nullptr;
	for (auto& child : nodeChilden)
	{
		if (child)
		{
			Widget* widgetChild = _CastToWidget(child);
			if (widgetChild)
			{
				Widget* pResult = _GetChildByName(widgetChild,name,childDepth);
				if (pResult!= NULL)
				{
					return pResult;
				}
			}
		}
	}
	//���е�child�����ǣ�����NULL��û���ҵ�
	return nullptr;
}

Widget* CCommonView::_CastToWidget( cocos2d::Node* pNode )
{
	CCASSERT(pNode,"node can't be null");
//	if(pNode->getNodeType() == NodeType_Widget)
	{
		return static_cast<Widget*>(pNode);
	}
	return NULL;
}

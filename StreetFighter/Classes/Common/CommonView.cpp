#include "CommonView.h"
#include "CommonDef.h"
USING_NS_CC;
using namespace ui;



Widget* CCommonView::GetChildByNameRecursive( const char* childName,int childDepth )
{
	if(m_pUILayer)
	{
		return _GetChildByName(m_pUILayer,childName,childDepth);
	}
	return nullptr;
	
}

CCommonView::CCommonView():
m_pUILayer(NULL)
{

}

Widget* CCommonView::_GetChildByName(Node*pNode,const char* name,int childDepth)
{
	//首先寻找本层的child
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
				if (strcmp(widgetChild->getName(), name) == 0)
				{
					return widgetChild;
				}
			}
		}
	}
	//然后对每个child调用该寻找方法，同时递归层数减一，如果层数为0，停止递归，直接返回
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
				if (_GetChildByName(widgetChild,name,childDepth) != NULL)
				{
					return widgetChild;
				}
			}
		}
	}
	//所有的child都不是，返回NULL，没有找到
	return nullptr;
}

Widget* CCommonView::_CastToWidget( cocos2d::Node* pNode )
{
	CCASSERT(pNode,"node can't be null");
	if(pNode->getNodeType() == NodeType_Widget)
	{
		return static_cast<Widget*>(pNode);
	}
	return NULL;
}

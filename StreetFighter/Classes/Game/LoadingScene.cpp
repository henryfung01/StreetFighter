#include "LoadingScene.h"
USING_NS_CC;
#include "Common/CommonDef.h"
#include "2d/CCLayer.h"
#include "ccUTF8.h"
bool CLoadingScene::init()
{
	auto layercolor = LayerColor::create(Color4B(0,255,0,255));
	addChild(layercolor);
	const char* configString = cc_utf16_to_utf8((unsigned short*)(L"Ŭ��������"),-1,nullptr,nullptr);
	TTFConfig ttfConfig("fonts/wt021.ttf",32,GlyphCollection::CUSTOM, configString);
	Size layerSize = layercolor->getContentSize();
	const char* label1Text = cc_utf16_to_utf8((unsigned short*)(L"Ŭ"),-1,nullptr,nullptr);
	auto label1 = Label::createWithTTF(ttfConfig,label1Text, TextHAlignment::CENTER, 100);
	label1->setPosition(Point(layerSize.width / 2 - 100, layerSize.height /2));
	const char* label2Text = cc_utf16_to_utf8((unsigned short*)(L"��"),-1,nullptr,nullptr);
	auto label2 = Label::createWithTTF(ttfConfig,label2Text, TextHAlignment::CENTER, 100);
	label2->setPosition(Point(layerSize.width / 2 - 50, layerSize.height /2));
	const char* label3Text = cc_utf16_to_utf8((unsigned short*)(L"��"),-1,nullptr,nullptr);
	auto label3 = Label::createWithTTF(ttfConfig,label3Text, TextHAlignment::CENTER, 100);
	label3->setPosition(Point(layerSize.width / 2 , layerSize.height /2));
	const char* label4Text = cc_utf16_to_utf8((unsigned short*)(L"�d"),-1,nullptr,nullptr);
	auto label4 = Label::createWithTTF(ttfConfig,label4Text, TextHAlignment::CENTER, 100);
	label4->setPosition(Point(layerSize.width / 2 + 50, layerSize.height /2));
	const char* label5Text = cc_utf16_to_utf8((unsigned short*)(L"��"),-1,nullptr,nullptr);
	auto label5 = Label::createWithTTF(ttfConfig,label5Text, TextHAlignment::CENTER, 100);
	label5->setPosition(Point(layerSize.width / 2 + 100, layerSize.height /2));
	layercolor->addChild(label1);
	layercolor->addChild(label2);
	layercolor->addChild(label3);
	layercolor->addChild(label4);
	layercolor->addChild(label5);
	return true;
}

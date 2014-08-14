#ifndef __COMBAT_SCENE_INPUT_LAYER_H__
#define __COMBAT_SCENE_INPUT_LAYER_H__
//whitebai 2014.8.5
#include "cclayer.h"
#define MAXRECORDPOINT 64
class CCombatScene;
class CSceneInputLayer : public cocos2d::Layer
{
public:
	CSceneInputLayer();
	bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(CSceneInputLayer);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
private:
	void _ClearRecords();
	cocos2d::Point m_RecordPoints[MAXRECORDPOINT];
	byte m_iRecordCount;
	bool m_bRecording;
};

#endif // __COMBAT_SCENE_INPUT_LAYER_H__

#ifndef __POS_CONVERTER_H__
#define __POS_CONVERTER_H__
//whitebai 2014.8.10
//convert the grid position to render position
struct EntityPos;
#include "CCGeometry.h"
class CPosConverter
{
public:
	CPosConverter(){}
	virtual ~CPosConverter(){}
	//should implement the interface
	virtual cocos2d::Point TransToRenderPos( const EntityPos& pos,const EntityPos& entitySize ) = 0;
};
#endif // __POS_CONVERTER_H__

#ifndef __PUFFER_H__
#define __PUFFER_H__

#include "cocos2d.h"

class puffer 
{
public:
	puffer(cocos2d::Layer *layer);

private:
	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *pufferguay;
};

#endif // __PUFFER_H__

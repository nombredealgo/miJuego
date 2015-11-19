#include "puffer.h"

USING_NS_CC;

Sprite *puffer::createAnimation(int numeron)
{   
	 
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
	
	auto cacher = SpriteFrameCache::getInstance();
	cacher->addSpriteFramesWithFile("puffer.plist");



	auto someSprite = Sprite::createWithSpriteFrameName("puffer1.png");

	

	if (numeron==1){
			// load all the animation frames into an array
			Vector<SpriteFrame*> frames;
			for (int i = 5; i <= 8; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			}
						// play the animation
				Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
				someSprite->runAction(Animate::create(anim));
				someSprite->setPosition(100, 100);	
	}

	else{

			Vector<SpriteFrame*> frames;
			for (int i = 1; i <= 4; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			 }
			// play the animation
			Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
			someSprite->runAction(Animate::create(anim));
			someSprite->setPosition(100, 100);	
			someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	}
	
	
	
	return someSprite;

	}






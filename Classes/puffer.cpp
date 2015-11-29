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
			for (int i = 6; i <= 7; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			}
						// play the animation
				Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
				someSprite->runAction(Animate::create(anim));
				someSprite->setPosition(200, 100);	
				someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	
	}

	if (numeron==2){
			// load all the animation frames into an array
			Vector<SpriteFrame*> frames;
			for (int i = 21; i <= 28; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			}
						// play the animation
				Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
				someSprite->runAction(Animate::create(anim));
				someSprite->setPosition(200, 100);	
				someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	
	}

	if (numeron ==0){

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
			someSprite->setPosition(200, 100);	
			someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	}
	
	if (numeron==3){

			// load all the animation frames into an array
			Vector<SpriteFrame*> frames;
			for (int i = 18; i <= 20; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			}
						// play the animation
				Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
				someSprite->runAction(Animate::create(anim));
				someSprite->setPosition(200, 100);	
				someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	
	}

	if (numeron==4){

			// load all the animation frames into an array
			Vector<SpriteFrame*> frames;
			for (int i = 10; i <= 12; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			}
						// play the animation
				Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
				someSprite->runAction(Animate::create(anim));
				someSprite->setPosition(200, 100);	
				someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	
	}
	if (numeron==5){

			// load all the animation frames into an array
			Vector<SpriteFrame*> frames;
			for (int i = 14; i <= 15; i++)
			{
				std::stringstream ss;
				ss << "puffer" << i << ".png";
				frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
			}
						// play the animation
				Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
				someSprite->runAction(Animate::create(anim));
				someSprite->setPosition(200, 100);	
				someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	
	}
	
	return someSprite;

	}




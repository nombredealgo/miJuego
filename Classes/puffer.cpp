#include "puffer.h"

USING_NS_CC;

Sprite *puffer::createAnimation(int numeron)
{   
	 
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
	if (numeron == 0){

	auto cacher = SpriteFrameCache::getInstance();
	cacher->addSpriteFramesWithFile("puffer.plist");



	auto someSprite = Sprite::createWithSpriteFrameName("pu01.png");

	// load all the animation frames into an array
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 3; i++)
	{
		std::stringstream ss;
		ss << "pu0" << i << ".png";
		frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
	}
	
	// play the animation
	Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
	someSprite->runAction(Animate::create(anim));
	someSprite->setPosition(100, 100);
	
	
	someSprite->runAction(RepeatForever::create(Animate::create(anim)));

	return someSprite;
	}
	if (numeron==1){

	auto cacher = SpriteFrameCache::getInstance();
	cacher->addSpriteFramesWithFile("patada.plist");



	auto someSprite = Sprite::createWithSpriteFrameName("patada1.png");

	// load all the animation frames into an array
	Vector<SpriteFrame*> frames;
	for (int i = 1; i <= 3; i++)
	{
		std::stringstream ss;
		ss << "patada" << i << ".png";
		frames.pushBack(cacher->getSpriteFrameByName(ss.str()));
	}
	
	// play the animation
	Animation* anim = Animation::createWithSpriteFrames(frames, 0.2f);
	someSprite->runAction(Animate::create(anim));
	someSprite->setPosition(100, 100);
	
	
	someSprite->runAction(RepeatForever::create(Animate::create(anim)));

	return someSprite;
	}
}




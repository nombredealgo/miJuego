#include "puffer.h"

USING_NS_CC;

puffer::puffer(cocos2d::Layer *layer)
{
	visibleSize = Director::getInstance( )->getVisibleSize( );
	origin = Director::getInstance( )->getVisibleOrigin( );

	//pufferguay = Sprite::create("pu01.png");
	//pufferguay->setPosition(Point(visibleSize.width/2 + origin.x,visibleSize.height/2 + origin.y));
	
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

	layer->addChild(someSprite);

	someSprite->runAction(RepeatForever::create(Animate::create(anim)));
	
}


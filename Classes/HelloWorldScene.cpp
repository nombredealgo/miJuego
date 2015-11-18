#include "HelloWorldScene.h"
#include "puffer.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);	

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
		
        return false;
    }

	bool idle = true; 
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
    auto sprite = Sprite::create("escenarioguay.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	
	auto puf1 = puffer::createAnimation(1);
	auto puf2 = puffer::createAnimation(0);

	this->addChild(puf1,0);
	
	 auto eventListener = EventListenerKeyboard::create();



    eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){

        
        switch(keyCode){
           
            case EventKeyboard::KeyCode::KEY_A:
				if (idle != true){
				addChild(puf2,1);
				
				}
                break;
				
            }
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,puf1);
	
			
	return true;
}





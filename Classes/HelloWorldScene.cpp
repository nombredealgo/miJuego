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
	patada2activa = false;
	agachadoactivo = false;
	patadactiva = false;
	puñoactivo = false;
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
    auto sprite = Sprite::create("escenarioguay.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	

	auto idle = puffer::createAnimation(0);


	// run it
	
	this->addChild(idle);
	

	auto eventListener = EventListenerKeyboard::create();

	
     eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        
        switch(keyCode){
           
		case EventKeyboard::KeyCode::KEY_A:
			if (patadactiva == false){
				patadactiva=true;
				idle->removeFromParentAndCleanup(TRUE);
				auto patada = puffer::createAnimation(1);
				addChild(patada);
			}
			break;
		case EventKeyboard::KeyCode::KEY_S:
			if (agachadoactivo == false){
				agachadoactivo = true;
  			    idle->removeFromParentAndCleanup(TRUE);
				auto agachado = puffer::createAnimation(2);
				addChild(agachado);
			}
			break;
		 case EventKeyboard::KeyCode::KEY_D:
			if (puñoactivo == false){
				puñoactivo = true;
				idle->removeFromParentAndCleanup(TRUE);
				auto puñetazo = puffer::createAnimation(3);
				addChild(puñetazo);
			}
			break;
		   case EventKeyboard::KeyCode::KEY_F:
			if (patada2activa == false){
				patada2activa = true;
				idle->removeFromParentAndCleanup(TRUE);
				auto patadaup = puffer::createAnimation(4);
				addChild(patadaup);
			}
			break;
		}
	 };

	 this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);
	




return true;

}





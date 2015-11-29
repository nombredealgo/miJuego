#include "HelloWorldScene.h"
#include "puffer.h"

#define COCOS2D_DEBUG 1
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

	
	contador=0;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
    auto sprite = Sprite::create("escenarioguay.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	
	auto patadavoladora = puffer::createAnimation(5);
	auto patadafinal = puffer::createAnimation(4);
	auto puñetazo = puffer::createAnimation(3);
	auto agachado = puffer::createAnimation(2);
	auto patada = puffer::createAnimation(1);
	auto idle = puffer::createAnimation(0);
	
	this->addChild(idle);
	this->addChild(patada);
	this->addChild(agachado);
	this->addChild(puñetazo);
	this->addChild(patadafinal);
	this->addChild(patadavoladora);

	patadavoladora->setVisible(false);
	patada->setVisible(false);
	agachado->setVisible(false);
	puñetazo->setVisible(false);
	patadafinal->setVisible(false);

	 auto eventListener = EventListenerKeyboard::create();
	
	 this->schedule(schedule_selector(HelloWorld::update),0.9);

     eventListener->onKeyPressed =[=](EventKeyboard::KeyCode keyCode, Event* event){
        
		 switch(keyCode){

          case EventKeyboard::KeyCode::KEY_A:

				if (contador > 10){
					patada->setVisible(true);
					idle->setVisible(false);
				}
				else{

					agachado->setVisible(true);
					idle->setVisible(false);
				}
							 
				break;        
		  
		  case EventKeyboard::KeyCode::KEY_S:

				if (contador > 10){
					puñetazo->setVisible(true);
					idle->setVisible(false);
				}
				break;

		  case EventKeyboard::KeyCode::KEY_D:

				if (contador > 10){
					patadafinal->setVisible(true);
					idle->setVisible(false);
				}
				break;
			
		  case EventKeyboard::KeyCode::KEY_F:

				if (contador > 10){
					patadavoladora->setVisible(true);
					idle->setVisible(false);
				}
				break;
		 }
		
	 };	
		 
	
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener,sprite);
	
	auto solucion = EventListenerKeyboard::create();
	
	    solucion->onKeyReleased =[=](EventKeyboard::KeyCode keyCode, Event* event){
        
                  
          if (keyCode ==  EventKeyboard::KeyCode::KEY_A){
				
				
				patada->setVisible(false);
				idle->setVisible(true);
				agachado->setVisible(false);
				        
						
		 }

		  if (keyCode ==  EventKeyboard::KeyCode::KEY_S){			
				
				
				idle->setVisible(true);
				puñetazo->setVisible(false);
				        
						
		 }
			
		  if (keyCode ==  EventKeyboard::KeyCode::KEY_D){			
				
				
				idle->setVisible(true);
				patadafinal->setVisible(false);
				        
						
		 }
		  if (keyCode ==  EventKeyboard::KeyCode::KEY_F){			
				
				
				idle->setVisible(true);
				patadavoladora->setVisible(false);
				        
						
		 }
	 };	
	
	 
	
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(solucion,sprite);
	


	return true;		
	
	
}

void HelloWorld::update(float dt){		
	
	contador++;
	
	CCLOG("%d",contador);
}
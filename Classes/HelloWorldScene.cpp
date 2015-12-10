#include "HelloWorldScene.h"
#include "puffer.h"
#include "anubis.h"

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
	load = true;
	patada2activa = true;
	agachadoactivo = false;
	patadactiva = true;
	puñoactivo = true;
	patadavolac=true;

	anoobis = anubis::createAnimation(0,true);

	    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	 
    auto sprite = Sprite::create("escenarioguay.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	

	auto idle = puffer::createAnimation(0);
	
	this->schedule(schedule_selector(HelloWorld::update),0.9);
	this->schedule(schedule_selector(HelloWorld::loadchange),0.9);
	this->schedule(schedule_selector(HelloWorld::nomuerto),0.9);
	
	// run it
	
	this->addChild(idle);
	
	this->addChild(anoobis);
	//this->nomuerto(anoobis);

	
	auto eventListener = EventListenerKeyboard::create();

	
     eventListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event){
        
        switch(keyCode){
           
		case EventKeyboard::KeyCode::KEY_A:
			if (patadactiva == false){
				idle->removeFromParentAndCleanup(TRUE);
				auto patada = puffer::createAnimation(1);
				addChild(patada);
				patadactiva=true;
			}
			if (agachadoactivo == false){				
  			    idle->removeFromParentAndCleanup(TRUE);
				auto agachado = puffer::createAnimation(2);
				addChild(agachado);
				agachadoactivo = true;
			}
			break;


		case EventKeyboard::KeyCode::KEY_S:
			if (patadavolac == false){				
				idle->removeFromParentAndCleanup(TRUE);
				auto patadavol = puffer::createAnimation(5);
				addChild(patadavol);
				patadavolac = true;
			}
			break;
		 case EventKeyboard::KeyCode::KEY_D:
			if (puñoactivo == false){
				idle->removeFromParentAndCleanup(TRUE);
				auto puñetazo = puffer::createAnimation(3);
				addChild(puñetazo);
				puñoactivo = true;
			}
			break;
		  case EventKeyboard::KeyCode::KEY_F:
			if (patada2activa == false){				
				idle->removeFromParentAndCleanup(TRUE);
				auto patadaup = puffer::createAnimation(4);
				addChild(patadaup);
				patada2activa = true;
			}
			break;	
		
		}
	 };

	 this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, sprite);
	




return true;

}


void HelloWorld::nomuerto(float dt){
	
	if (contador%3==0){
		random = rand () % 3;
		anoobis ->removeFromParentAndCleanup(true);
		auto anoobismovimiento = anubis::createAnimation(random,load);
		addChild(anoobismovimiento);
	}

}


void HelloWorld::update(float dt){		
	
	contador++;
	CCLOG("%d",contador);

}


void HelloWorld::loadchange(float dt){

	if (contador == 20){
		load = true;
		contador = 0;
		patada2activa = true;
		agachadoactivo = false;
		patadactiva = true;
		puñoactivo = true;
		patadavolac= true;
	}
	if (contador == 10){
		load = false;
		patada2activa = false;
		agachadoactivo = true;
		patadactiva = false;
		puñoactivo = false;
		patadavolac=false;
		}

	CCLOG("%d", load);
}
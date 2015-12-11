#include "vida.h"

USING_NS_CC;

Sprite *vida::createVida(int vida,int posicionx)
{   
	 
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	

	if (vida == 100){

		auto barravida = Sprite::create("vida100.png");
	barravida->setPosition(posicionx, 200);
	return barravida;
	}
	if (vida < 90 && vida > 80){

		auto barravida = Sprite::create("vida90.png");
	 barravida->setPosition(posicionx, 200);
	return barravida;
			
	}
	
	if (vida < 80 && vida > 70){

		auto barravida = Sprite::create("vida80.png");
	    barravida->setPosition(posicionx, 200);
	return barravida;
			
	}

	if (vida < 70 && vida > 60){

		auto barravida = Sprite::create("vida70.png");
	  	barravida->setPosition(posicionx, 200);
	return barravida;
			
	}
	if (vida < 60 && vida > 50){

		auto barravida = Sprite::create("vida60.png");
	  
			
	}
	if (vida < 50 && vida >= 40){

		auto barravida = Sprite::create("vida50.png");
	    	barravida->setPosition(posicionx, 200);
	return barravida;
			
	}
	if (vida < 40 && vida > 30){

		auto barravida = Sprite::create("vida40.png");
	   barravida->setPosition(posicionx, 200);
	return barravida;
			
	}
	if (vida < 30 && vida > 20){

		auto barravida = Sprite::create("vida30.png");
	   barravida->setPosition(posicionx, 200);
	return barravida;
			
	}
	if (vida < 20 && vida > 10){

		auto barravida = Sprite::create("vida20.png");
		barravida->setPosition(posicionx, 200);
		return barravida;
	}
	if (vida < 10 && vida > 0){

		auto barravida = Sprite::create("vida10.png");
	    barravida->setPosition(posicionx, 200);
		return barravida;
			
	}
	if (vida <=0){
		auto barravida = Sprite::create("vida00.png");
	    barravida->setPosition(posicionx, 200);
		return barravida;
	}

	

	}






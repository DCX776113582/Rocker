
#include "DemoScene.h"

Scene* DemoScene::createScene()
{
	auto scene = Scene::create();
	auto layer = DemoScene::create();
	scene->addChild(layer);
	return scene;
}

bool DemoScene::init()
{
	if( !Layer::init() )	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();

	bg = Sprite::create("green.png");
	bg->setPosition(visibleSize.width/2,visibleSize.height/2);
	this->addChild(bg);

	jr = JoyRocker::create(Vec2(visibleSize.width-100,100));
	this->addChild(jr);

	jr->startRocker();


	this->scheduleUpdate();

	return true;
}

void DemoScene::update(float ft)
{

    //判断是否按下摇杆及其类型
	switch( jr->getDirection() )
    {
    case 1:
			bg->setPosition(Vec2(bg->getPosition().x+2,bg->getPosition().y));		//向右走

        break;
    case 2:
		
			
			bg->setPosition(Vec2(bg->getPosition().x, bg->getPosition().y+2));		//向上走
		
		break;
    case 3:
		
			bg->setPosition(Vec2(bg->getPosition().x-2,bg->getPosition().y));		//向左走
		
		break;
    case 4:
		
			bg->setPosition(Vec2(bg->getPosition().x,bg->getPosition().y-2));		//向下走
		
		break;
	case 5:
			bg->setPosition(Vec2(bg->getPosition().x-1,bg->getPosition().y+1));
		;break;
	case 6:
			bg->setPosition(Vec2(bg->getPosition().x+1,bg->getPosition().y+1));
		;break;
	case 7:
			bg->setPosition(Vec2(bg->getPosition().x-1,bg->getPosition().y-1));
		;break;
	case 8:
			bg->setPosition(Vec2(bg->getPosition().x+1,bg->getPosition().y-1));
		;break;
    default:
        
        break;
    }
}
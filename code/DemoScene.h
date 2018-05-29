#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include "cocos2d.h"
#include "JoyRocker.h"

USING_NS_CC;

class DemoScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(DemoScene);

	void update(float ft);

private:
	Size visibleSize;
	JoyRocker* jr;
	Sprite* bg;
};

#endif
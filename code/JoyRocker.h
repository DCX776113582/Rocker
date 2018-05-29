#ifndef __JOY_ROCKER_H__
#define __JOY_ROCKER_H__

#include "cocos2d.h"

USING_NS_CC;



//用于标识摇杆方向
typedef enum{
    rocker_stay = 0,
    rocker_right,
    rocker_up,
    rocker_left,
    rocker_down,
	rocker_leftUp,
	rocker_rightUp,
	rocker_leftDown,
	rocker_rightDown,
}rockerDirecton;

// 标志 摇杆背景与中心
enum
{
	rockerBackGround = 2,
	rockerCenter,
};

class JoyRocker : public Layer
{
public:
	
	//创建摇杆
    static JoyRocker* create(Vec2 pos);
	// 使用摇杆
	void startRocker( );
	// 停止使用摇杆
	void stopRocker( );
	

	// 获取 摇杆 方向
	int getDirection();
	// 获取 人物 朝向
	bool getIsLeft();


	//触屏事件  
    virtual bool TouchBegan(Touch* touch, Event* event);  
    virtual void TouchMoved(Touch* touch, Event* event);  
    virtual void TouchEnded(Touch* touch, Event* event);  

private:

	bool init(Vec2 pos);
    //获取当前摇杆与用户触屏点的角度
    float getRad(Vec2 pos1,Vec2 pos2);
	// 根据角度，返回点坐标
	Vec2 getAnglePosition(float r,float angle);

	// 摇杆 是否可以移动（是否超过摇杆背景）
	bool isCanMove;
    //摇杆 中心的坐标
    Vec2 rockerCenterPos;
    //摇杆背景的半径
    float rockerBGR;
	//摇杆 的半径
	float rockerCenterR;
	//判断控制杆方向，用来判断精灵上、下、左、右、左上、右上、左下、右下 运动
    int rocketDirection;
	// 判断人物是否朝向左面
	bool isLeft;

	EventListenerTouchOneByOne* listener; 
	EventDispatcher* eventDispatcher;
};

#endif
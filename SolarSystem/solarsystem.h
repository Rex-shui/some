#pragma once

#include "stars.h"

#define STARS_NUM 10
enum STARS {
	Sun,		//太阳
	Mercury,	//水星
	Venus,		//金星
	Earth,		//地球
	Moon,		//月球
	Mars,		//火星
	Jupiter,	//木星
	Saturn,		//土星
	Uranus,		//天王星
	Neptune		//海王星
};

#define TIMEPAST 1
#define SELFROTATE 3	//自转速度

class SolarSystem {

public:
	SolarSystem();
	~SolarSystem();

	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key, int x, int y);

private:
	Star *stars[STARS_NUM];

	//定义观察视角的参数
	GLdouble viewX, viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};
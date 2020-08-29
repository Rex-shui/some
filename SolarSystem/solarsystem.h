#pragma once

#include "stars.h"

#define STARS_NUM 10
enum STARS {
	Sun,		//̫��
	Mercury,	//ˮ��
	Venus,		//����
	Earth,		//����
	Moon,		//����
	Mars,		//����
	Jupiter,	//ľ��
	Saturn,		//����
	Uranus,		//������
	Neptune		//������
};

#define TIMEPAST 1
#define SELFROTATE 3	//��ת�ٶ�

class SolarSystem {

public:
	SolarSystem();
	~SolarSystem();

	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key, int x, int y);

private:
	Star *stars[STARS_NUM];

	//����۲��ӽǵĲ���
	GLdouble viewX, viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};
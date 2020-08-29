#pragma once
#include <GL/glut.h>

class Star {
public:
	//绕行的星球，父节点星球
	Star * parentStar;
	//星球的中心与父节点星球中心的距离
	GLfloat distance;
	//星球的颜色
	GLfloat rgbaColor[4];
	//星球的公转、自转速度
	GLfloat speed, selfSpeed;
	//星球的半径
	GLfloat radius;

	//构造一棵星球时必须提供
	//旋转半径、旋转速度、自转速度、绕行星球
	Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parentStar);
	//对一般的星球移动、旋转等活动进行绘制
	void drawStar();
	//提供默认实现，负责调用drawStar()
	virtual void draw() { drawStar(); }
	//参数为每次刷新画面时的时间跨度
	virtual void update(long timeSpan);

protected:
	//自转角度，公转角度
	GLfloat alphaSelf, alpha;
};

class Planet : public Star {
public:
	Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parentStar, GLfloat rgbColor[3]);
	//增加绘制材质
	void drawPlant();
	//继续向子类开放重写功能，虚函数在其继承体系中一直是虚函数，并不需要"virtual"关键字
	virtual void draw() { drawPlant(); drawStar(); }
};

class LightPlanet : public Planet {
public:
	LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parentStar, GLfloat rgbaColor[]);
	//增加光源
	void drawLight();
	virtual void draw() { drawPlant(); drawStar(); drawLight(); }
};
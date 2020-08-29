#pragma once
#include <GL/glut.h>

class Star {
public:
	//���е����򣬸��ڵ�����
	Star * parentStar;
	//����������븸�ڵ��������ĵľ���
	GLfloat distance;
	//�������ɫ
	GLfloat rgbaColor[4];
	//����Ĺ�ת����ת�ٶ�
	GLfloat speed, selfSpeed;
	//����İ뾶
	GLfloat radius;

	//����һ������ʱ�����ṩ
	//��ת�뾶����ת�ٶȡ���ת�ٶȡ���������
	Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parentStar);
	//��һ��������ƶ�����ת�Ȼ���л���
	void drawStar();
	//�ṩĬ��ʵ�֣��������drawStar()
	virtual void draw() { drawStar(); }
	//����Ϊÿ��ˢ�»���ʱ��ʱ����
	virtual void update(long timeSpan);

protected:
	//��ת�Ƕȣ���ת�Ƕ�
	GLfloat alphaSelf, alpha;
};

class Planet : public Star {
public:
	Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parentStar, GLfloat rgbColor[3]);
	//���ӻ��Ʋ���
	void drawPlant();
	//���������࿪����д���ܣ��麯������̳���ϵ��һֱ���麯����������Ҫ"virtual"�ؼ���
	virtual void draw() { drawPlant(); drawStar(); }
};

class LightPlanet : public Planet {
public:
	LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parentStar, GLfloat rgbaColor[]);
	//���ӹ�Դ
	void drawLight();
	virtual void draw() { drawPlant(); drawStar(); drawLight(); }
};
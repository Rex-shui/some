#include "stars.h"
#include <cmath>

#define PI 3.1415926535

Star::Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parent) {
	this->radius = radius;
	this->selfSpeed = selfSpeed;
	this->alphaSelf = this->alpha = 0;
	this->distance = distance;

	for (int i = 0; i < 4; i++)
		this->rgbaColor[i] = 1.0f;

	this->parentStar = parent;
	if (speed > 0)
		this->speed = 360.0f / speed;
	else
		this->speed = 0.0f;
}
void Star::update(long timeSpan)
{
	alpha += timeSpan * speed;	//���½Ƕ�
	alphaSelf += selfSpeed;		//������ת�Ƕ�
}

void Star::drawStar()
{
	//glEnable���ø��ֹ��ܣ���glDisable���Ӧ
	glEnable(GL_LINE_SMOOTH);	//�����߶εľ��
	glEnable(GL_BLEND);			//������ɫ��ϡ�����ʵ�ְ�͸��Ч��

	int n = 1440;

	//����OpenGL��ǰ�ľ��󻷾�
	glPushMatrix();
	{
		//��ת

		//����������Ҿ��벻Ϊ0��̫��������ô��ԭ��ƽ��һ���뾶
		//�ⲿ�����ڴ�������
		if (parentStar != 0 && parentStar->distance > 0) {
			//�����Ƶ�ͼ���� z ����ת alpha
			glRotated(parentStar->alpha, 0, 0, 1);
			// x �᷽����ƽ�� distance, y, z ���򲻱�
			glTranslatef(parentStar->distance, 0.0, 0.0);
		}
		// �������й��
		glBegin(GL_LINES);
		for (int i = 0; i < n; ++i)
			glVertex2f(distance*cos(2 * PI*i / n), distance*sin(2 * PI*i / n));
		glEnd();
		//�� z ����תalpha
		glRotatef(alpha, 0, 0, 1);
		//x �᷽��ƽ�� distance��y��z���򲻱�
		glTranslatef(distance, 0.0, 0.0);

		//��ת
		glRotatef(alphaSelf, 0, 0, 1);

		//����������ɫ
		glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
		glutSolidSphere(radius, 40, 32);	//��Ⱦһ�����壬Ĭ��λ����Ļ����
	}
	//�ָ�����ǰ�ľ��󻷾�
	glPopMatrix();
}

Planet::Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parent, GLfloat rgbColor[3]) :
	Star(radius, distance, speed, selfSpeed, parent) {
	rgbaColor[0] = rgbColor[0];
	rgbaColor[1] = rgbColor[1];
	rgbaColor[2] = rgbColor[2];
	rgbaColor[3] = 1.0f;
}

void Planet::drawPlant() {
	GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
	GLfloat mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };
	GLfloat mat_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
	GLfloat mat_emission[] = { rgbaColor[0], rgbaColor[1], rgbaColor[2], rgbaColor[3] };
	GLfloat mat_shininess = 90.0f;

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

LightPlanet::LightPlanet(GLfloat radius, GLfloat distance, GLfloat speed,
	GLfloat selfSpeed, Star* parent, GLfloat rgbColor[3]) :
	Planet(radius, distance, speed, selfSpeed, parent, rgbColor) {
	;
}

void LightPlanet::drawLight() {

	GLfloat light_position[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position); // ָ����Ź�Դ��λ��
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);  // ��ʾ���ֹ������䵽�ò����ϣ������ܶ�η����׷�������ڻ����еĹ���ǿ��
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);  // �������Ĺ���ǿ��
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); // ���淴���Ĺ���ǿ��

}
//ʹ��GLUT��ͷ�ļ�
#include <GL/glut.h>

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

void myDraw()
{
	//�����GL_COLOR_BUFFER_BIT�����ɫ
	glClear(GL_COLOR_BUFFER_BIT);

	//������Ϊ����ϵԭ��
	glRectf(-0.5, -0.5, 0.5, 0.5);

	//ǿ��ˢ�»���������֤��ͼ���ִ��
	glFlush();
}

int main(int argc, char **argv)
{
	//��glut��ʼ���������������������glutʹ��֮ǰ����һ��
	glutInit(&argc, argv);

	//������ʾ��ʽ��GLUT_RGB��GLUT_INDEXʹ��������ɫ
	//GLUT_SINGLE�����壬GLUT_DOUBLE˫����
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);

	//����ǰ�����Ϣ��������
	//���ڱ������󣬲���������ʾ����Ļ�ϡ���Ҫ����glutMainLoop���ܿ�������
	glutCreateWindow("һ���򵥵�OpenGL����");

	//�ص�����
	glutDisplayFunc(myDraw);

	//����һ����Ϣѭ��
	glutMainLoop();

	return 0;
}

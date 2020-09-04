#include <GL/glut.h>
#include <math.h>

#define PI 3.141526535

void draw()
{
	glClearColor(0.7, 0.7, 0.7, 0.5);	//设置背景颜色
	glClear(GL_COLOR_BUFFER_BIT);		//清空缓存更新背景颜色

	glBegin(GL_POLYGON);
	//GL_POINTS			绘制点
	//GL_LINES			每两点绘制一个线段，N个点，N/2 条线段
	//GL_LINE_LOOP		两点间依次连线，N个点，N 条线段，首尾相连
	//GL_LINE_STRIP		两点间依次连线，N个点，N-1 条线段
	//GL_TRIANGLES		每三个点为一个三角形，N个点，N/3 个三角形
	//GL_TRIANGLE_STRIP
	//GL_QUADS			每四个点为一个四边形，N个点，N/4 个四边形
	//GL_QUAD_STRIP
	//GL_POLYGON		一个凸多边形

	//设置当前颜色
	glColor3f(1.0, 1.0, 1.0);
	int n = 360;
	for (int i = 0; i < 360; i++) {
		glVertex2f(0.5*cos(2 * PI*i / n), 0.5*sin(2 * PI*i / n));
		if (i == 180) {
			glColor3f(0.0, 0.0, 0.0);
		}
	}
	glEnd();

	//刷新缓冲区，显示图片
	glFlush();
}


int main(int argc, char**argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("画一个凸多边形");

	glutDisplayFunc(draw);

	glutMainLoop();

	return 0;
}
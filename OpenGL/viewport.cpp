#include <GL/glut.h>

static int WIDTH;
static int HEIGHT;

void onDisplay()
{
	glClearColor(0.7, 0.7, 0.7, 0.0);

	//画分割线
	glViewport(0, 0, WIDTH, HEIGHT);
	glBegin(GL_LINES);
	glColor3d(255, 0, 0);
	glVertex2f(-1.0, 0.0);
	glVertex2f(1.0, 0.0);
	glVertex2f(0.0, 1.0);
	glVertex2f(0.0, -1.0);
	glEnd();

	//右上角
	glViewport(WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2);
	glBegin(GL_QUADS);
	glColor3d(255, 255, 0);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();

	glutSwapBuffers();

}

void reShape(int w, int h)
{
	WIDTH = w;
	HEIGHT = h;
	//改变显示区域，起始位置为客户端左下角，然后宽高
	glViewport(0, 0, w, h);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("视口");

	glutDisplayFunc(onDisplay);
	glutReshapeFunc(reShape);

	glutMainLoop();
}
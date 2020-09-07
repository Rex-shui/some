#include <GL/glut.h>
#include <stdlib.h>

static float offsetX = 0;
static float offsetY = 0;

void onDisplay()
{
	glClearColor(0.7, 0.7, 0.7, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glViewport(offsetX, offsetY, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

	glBegin(GL_QUADS);
	glColor3d(255, 255, 0);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();

	glutSwapBuffers();

}

void onKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':offsetY += 5; break;
	case 's':offsetY -= 5; break;
	case 'a':offsetX -= 5; break;
	case 'd':offsetX += 5; break;
	case 'q':exit(0); break;
	default:
		break;
	}
	onDisplay();
}

void reShape(int w, int h)
{
	glViewport(0, 0, w, h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("键盘响应");

	glutDisplayFunc(onDisplay);
	glutReshapeFunc(reShape);

	glutKeyboardFunc(onKeyboard);

	glutMainLoop();
}
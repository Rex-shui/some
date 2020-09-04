#include <GL/glut.h>

//八个顶点的坐标
static const GLfloat vertex_list[][3] = {
	-0.5, -0.5, -0.5,
	 0.5, -0.5, -0.5,
	-0.5,  0.5, -0.5,
	 0.5,  0.5, -0.5,
	-0.5, -0.5,  0.5,
	 0.5, -0.5,  0.5,
	-0.5,  0.5,  0.5,
	 0.5,  0.5,  0.5
};
//八个顶点的编号，用于连线调用
static const GLint index_list[][2] = {
	0, 1, 2, 3, 4, 5, 6, 7,
	0, 2, 1, 3, 4, 6, 5, 7,
	0, 4, 1, 5, 7, 3, 2, 6
};

void drawCube()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	//8个顶点12条线
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 2; j++) {
			glVertex3fv(vertex_list[index_list[i][j]]);
		}
	}

	glEnd();
}

void onDisplay()
{
	glClearColor(0.7, 0.7, 0.7, 0.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	//GL_MODELVIEW		模型视图
	//GL_PROJECTION		投影
	//GL_TEXTURE

	//设置当前矩阵为单位矩阵
	glLoadIdentity();

	//存储当前矩阵
	//界面发生改变时，glutDisplayFunc循环调用该函数
	//若不保存当前矩阵再恢复或是重置当前矩阵为单位矩阵（glLoadIdentity）
	//该图形会一直向右偏移0.2，以及随x轴、y轴旋转
	glPushMatrix();

	//沿x轴平移0.2
	glTranslatef(0.2, 0, 0);

	//旋转
	glRotatef(3, 0, 1, 0);
	glRotatef(3, 1, 0, 0);

	drawCube();

	glPopMatrix();

	glFlush();
}


int main(int argc, char**argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("画一个立方体");

	glutDisplayFunc(onDisplay);

	glutMainLoop();

	return 0;
}
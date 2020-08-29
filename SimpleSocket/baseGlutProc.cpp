//使用GLUT的头文件
#include <GL/glut.h>

#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

void myDraw()
{
	//清除，GL_COLOR_BUFFER_BIT清除颜色
	glClear(GL_COLOR_BUFFER_BIT);

	//以中心为坐标系原点
	glRectf(-0.5, -0.5, 0.5, 0.5);

	//强制刷新缓冲区，保证绘图命令被执行
	glFlush();
}

int main(int argc, char **argv)
{
	//对glut初始化，这个函数必须在其他glut使用之前调用一次
	glutInit(&argc, argv);

	//设置显示方式，GLUT_RGB，GLUT_INDEX使用索引颜色
	//GLUT_SINGLE单缓冲，GLUT_DOUBLE双缓冲
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);

	//根据前面的信息创建窗口
	//窗口被创建后，并不立即显示到屏幕上。需要调用glutMainLoop才能看到窗口
	glutCreateWindow("一个简单的OpenGL程序");

	//回调函数
	glutDisplayFunc(myDraw);

	//进行一个消息循环
	glutMainLoop();

	return 0;
}

#define EXPORTBUILD

#include "OpenGLDll.h"

#include <Windows.h>
#include <cstdlib>
#include <gl/GL.h>
#include <gl\GLU.h>
#include <openglxy\glut.h>

int add(int x, int y) {
	return x + y;
}


const GLfloat factor = 0.1f;
void myDisplay3(void)
{
	GLfloat x;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);         // 以上两个点可以画x轴
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);         // 以上两个点可以画y轴
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x<1.0f / factor; x += 0.01f)
	{
		glVertex2f(x*factor, sin(x)*factor);
	}
	glEnd();

	glFlush();
}

int TestOpenGLDll() {
	std::cout << "openglTest3!" << std::endl;
	int result = -1;
	int pargc = 1;
	char *pargv = "openglTest3";
	char** vargc = &pargv;
	glutInit(&pargc, vargc);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("第3个OpenGL程序");
	glutDisplayFunc(&myDisplay3);
	glutMainLoop();

	result = 1;

	return result;
}

OpenGLDll::OpenGLDll(void) {}
OpenGLDll::~OpenGLDll(void) {}

//#include "stdafx.h"

#include <iostream>
#include <stdio.h>
#include <time.h>

#include <openglxy\glut.h>

// 太阳、地球和月亮  
// 假设每个月都是12天  
// 一年12个月，共是360天  
static int day = 200; // day的变化：从0到359  

double CalFrequency()
{
	static int count;
	static double save;
	static clock_t last, current;
	double timegap;

	++count;
	if (count <= 50)
		return save;
	count = 0;
	last = current;
	current = clock();
	timegap = (current - last) / (double)CLK_TCK;
	save = 50.0 / timegap;
	return save;
}

void myDisplay(void)
{
	double FPS = CalFrequency();
	printf("FPS = %f\n", FPS);

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75, 1, 1, 400000000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, -200000000, 200000000, 0, 0, 0, 0, 0, 1);

	// 绘制红色的“太阳”  
	glColor3f(1.0f, 0.0f, 0.0f);
	glutSolidSphere(69600000, 20, 20);
	// 绘制蓝色的“地球”  
	glColor3f(0.0f, 0.0f, 1.0f);
	glRotatef(day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(150000000, 0.0f, 0.0f);
	glutSolidSphere(15945000, 20, 20);
	// 绘制黄色的“月亮”  
	glColor3f(1.0f, 1.0f, 0.0f);
	glRotatef(day / 30.0*360.0 - day / 360.0*360.0, 0.0f, 0.0f, -1.0f);
	glTranslatef(38000000, 0.0f, 0.0f);
	glutSolidSphere(4345000, 20, 20);

	glFlush();
	glutSwapBuffers();
}

void myIdle(void)
{
	++day;
	if (day >= 360)
		day = 0;
	myDisplay();
}

void openglTest1() {

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("太阳，地球和月亮");
	glutDisplayFunc(&myDisplay);
	glutIdleFunc(&myIdle);
	glutMainLoop();
}

void myDisplay2(){

	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}

void openglTest2() {
	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("第一个OpenGL程序");
	glutDisplayFunc(&myDisplay2);
	glutMainLoop();
}

int main(int argc, char *argv[])
{
	std::cout << "Hello VS, this is the main function!" << std::endl;
	
	glutInit(&argc, argv);
	
	//openglTest1();
	openglTest2();


	return 0;
}

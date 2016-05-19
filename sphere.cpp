// sphere.cpp : Defines the entry point for the console application.
//


/*#include <GL/glut.h>
#include <stdlib.h>*/

#include "stdafx.h"
#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include <ctime>
#include<vector>
using namespace std;


static int earthyear = 0,  jupiteryear = 0 ,  jupiterday = 0  , earthday = 0 , sunday = 0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glRotatef((GLfloat)sunday, 0.0, 1.0, 0.0);
	glutWireSphere(1.0, 20, 16);   /* draw sun */
	glPopMatrix();
	glPushMatrix();
    glRotatef((GLfloat)earthyear, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)earthday, 0.0, 1.0, 0.0);
	glutWireSphere(0.2, 10, 8);    /* draw smaller planet */
	glPopMatrix();
	glPushMatrix();
	glRotatef((GLfloat)jupiteryear, 0.0, 1.0, 0.0);
	glTranslatef(3.0, 0.0, 0.0);
	glRotatef((GLfloat)jupiterday, 0.0, 1.0, 0.0);
	glutWireSphere(0.3, 13, 11);    /* draw smaller planet */
	glPopMatrix();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}




void update(int val)
{
	earthday = (earthday + 10) % 360;
	sunday = (sunday + 1) % 360;
	jupiterday = (jupiterday + 7) % 360;
	earthyear = (earthyear + 3) % 360;
	jupiteryear = (jupiteryear + 1) % 360;
	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}
/*void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'd':
		earthday = (earthday + 10) % 360;
		glutPostRedisplay();
		break;
	case 'D':
		earthday = (earthday - 10) % 360;
		glutPostRedisplay();
		break;
	case 's':
		sunday = (sunday + 10) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		sunday = (sunday - 10) % 360;
		glutPostRedisplay();
		break;
	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;
	case 'Y':
		year = (year - 5) % 360;
		glutPostRedisplay();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(20, update, 0);
	/*glutKeyboardFunc(keyboard);*/
	glutMainLoop();
	return 0;
}
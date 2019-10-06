/*******************************************************
 * Homework 2: OpenGL                                  *
 * CS 148 (Summer 2016), Stanford University           *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#if __APPLE__
#include <GLUT/glut.h>
#else
#include "GL/glut.h"
#endif

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0,1,4,1 };
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	float rotateTheta = 0;
	float x = 0;
	float y = 0;
	
	for (int i = 0; i < 10; i++)
	{
		glPushMatrix(); //Save Vector

		float theta = 2.0f * 3.14 * float(i) / float(10); //Get Angle, divide into 10 parts

		//Set x and y coordinates
		float x = cos(theta);
		float y = sin(theta);

		
		
		glTranslatef(x, y, 0); //Move teapot to x,y,0
		glRotatef(rotateTheta, 0, 0, 1); //Rotate teapot on the Z axis
		glutSolidTeapot(0.25f); //Draw teapot
		glPopMatrix(); //Reset Vector
		
		rotateTheta += 35; //Increment rotation angle by 35 for the next rotation
	}


	glFlush(); 

}

void problem2() {
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	//Set Initial Value
	float scaleY = 1.1;
	float transX = -1.7;
	float transY = 0.0;
	glPushMatrix(); //Save Vector

	glTranslatef(transX, 0, 0);
	for (int i = 0; i < 15; i++) //15 Steps, scale on Y axis then translate on x,y
	{
		glutSolidCube(0.25f);
		glScalef(1.0f, scaleY, 1.0f);
		glTranslatef(0.25f, 0.012, 0);
		
	}
	glPopMatrix();
	

	glFlush();
	
}

void problem3() {
	
	glPushMatrix(); //Save Vector
	glTranslatef(-2.5, -1, 0); //Translate Origin to desired teapot location

	int row = 6;
	glColorMaterial(GL_FRONT, GL_AMBIENT);
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	//Build from bottom to the top
	for (int i = 6; i > 0; i--)
	{
		for (int k = 0; k < row; k++) //Place # of teapots depending on the current row
		{
			glPushMatrix();
			glTranslatef(k, 0, 0);
			glutSolidTeapot(0.25f);
			glPopMatrix();
		}
		glTranslatef(0.5, 0.5, 0); //After a row of teapots are placed, translate x,y by 0.5
		row--; //Decrease number of teapots to be placed
	}

	glPopMatrix(); //Return to Origin

	glFlush();


}

void problem4() {
	//Ramiel Mid-Transform Recreation
	
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_NORMALIZE);
	glPushMatrix();
	
	glTranslatef(-0.25, 0, 0);
	glColor4f(0, 0, 255, 50);
	float x = -3.0f;
	//Draw Left and Right Triangles
	for (int i = 1; i <= 2; i++)
	{
		if (i % 2 == 0)
		{
			x = 3.0f;
		}
		//Left Triangle
		glBegin(GL_TRIANGLES);
		//Left
		glVertex3f(0, 0, 0);
		glVertex3f(x, 0.5f, 0.5f);
		glVertex3f(x, -0.5f, 0.5f);

		//Right
		glVertex3f(0, 0, 0);
		glVertex3f(x, 0.5f, -0.5f);
		glVertex3f(x, -0.5f, -0.5f);

		//Top
		glVertex3f(0, 0, 0);
		glVertex3f(x, 0.5f, 0.5f);
		glVertex3f(x, 0.5f, -0.5f);


		//Bottom
		glVertex3f(0, 0, 0);
		glVertex3f(x, -0.5f, 0.5f);
		glVertex3f(x, -0.5f, -0.5f);
		glEnd();

		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.25, 0, 0);
	}

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, 0.25f, 0);

	float y = 3.0f;
	//Draw Top and Bottom Triangles
	for (int i = 1; i <= 2; i++)
	{
		if (i % 2 == 0)
		{
			y = -3.0f;
		}
		glBegin(GL_TRIANGLES);
		//Left
		glVertex3f(0, 0, 0);
		glVertex3f(-0.5f, y, 0.5f);
		glVertex3f(-0.5f, y, -0.5f);

		//Right
		glVertex3f(0, 0, 0);
		glVertex3f(0.5f, y, 0.5f);
		glVertex3f(0.5f, y, -0.5f);

		//Front
		glVertex3f(0, 0, 0);
		glVertex3f(-0.5f, y, 0.5f);
		glVertex3f(0.5f, y, 0.5f);

		//Back
		glVertex3f(0, 0, 0);
		glVertex3f(-0.5f, y, -0.5f);
		glVertex3f(0.5f, y, -0.5f);
		glEnd();
		glPopMatrix();
		glPushMatrix();

		glTranslatef(0, -0.25f, 0);
	}
	glPopMatrix();

	


	float transZ = 3.0f;
	float transZ2 = 1.75f;
	float tmpz = 1.25f;
	//Front and Back Part
	for (int i = 1; i <= 2; i++)
	{
		glPushMatrix();
		if (i % 2 == 0)
		{
			transZ *= -1;
			transZ2 *= -1;
			tmpz *= -1;
		}

		glScalef(0.25, 0.25, 1);
		glTranslatef(0, 0, tmpz);
		glutSolidOctahedron();

		glPopMatrix();
		glPushMatrix();
		glTranslatef(0, 0, transZ);
		glScalef(0.75, 0.75, 0.75);
		glRotatef(35, 0, 0, 1);
		glutSolidOctahedron();
		glTranslatef(0, 0, transZ2);
		glScalef(0.75, 0.75, 0.75);
		glRotatef(35, 0, 0, 1);
		glutSolidOctahedron();
		glPopMatrix();
	}

	glPushMatrix();

	//Draw Left Outer Part
	glTranslatef(-3.75f, 0, 0);
	glScalef(0.1, 0.5, 0.5);
	glutSolidOctahedron();
	glTranslatef(-1.5f, 0, 0);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();

	glTranslatef(-1.5f, 0, 0);
	glColor4f(255, 0, 0, 50);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(-4.4f, 0, 0);
	glutSolidSphere(0.05f, 50, 50);

	glPopMatrix();
	glPushMatrix();

	glColor4f(0, 0, 255, 50);

	glTranslatef(-5, 0, 0);
	glScalef(0.1, 1.0, 1.0);
	glutSolidOctahedron();
	glTranslatef(-3.0f, 0, 0);
	glScalef(1.25, 0.5, 0.5);
	glRotatef(45, 1, 0, 0);
	glutSolidOctahedron();

	glTranslatef(-3.0f, 0, 0);
	glScalef(0.75, 0.25, 0.25);
	glRotatef(45, 1, 0, 0);
	glutSolidOctahedron();

	glPopMatrix();
	glPushMatrix();

	//Draw Right Outer Part
	glTranslatef(3.75f, 0, 0);
	glScalef(0.1, 0.5, 0.5);
	glutSolidOctahedron();
	glTranslatef(1.5f, 0, 0);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();

	glTranslatef(1.5f, 0, 0);
	glColor4f(255, 0, 0, 50);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(4.4f, 0, 0);
	glutSolidSphere(0.05f, 50, 50);

	glPopMatrix();
	glPushMatrix();

	glColor4f(0, 0, 255, 50);

	glTranslatef(5, 0, 0);
	glScalef(0.1, 1.0, 1.0);
	glutSolidOctahedron();
	glTranslatef(3.0f, 0, 0);
	glScalef(1.25, 0.5, 0.5);
	glRotatef(45, 1, 0, 0);
	glutSolidOctahedron();

	glTranslatef(3.0f, 0, 0);
	glScalef(0.75, 0.25, 0.25);
	glRotatef(45, 1, 0, 0);
	glutSolidOctahedron();

	glPopMatrix();
	glPushMatrix();

	//Draw Bottom Outer Part
	glTranslatef(0, -3.75f, 0);
	glScalef(0.5, 0.1, 0.5);
	glutSolidOctahedron();
	glTranslatef(0, -1.5, 0);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();

	glTranslatef(0, -1.5f, 0);
	glColor4f(255, 0, 0, 50);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, -4.4f, 0);
	glutSolidSphere(0.05f, 50, 50);

	glPopMatrix();
	glPushMatrix();

	glColor4f(0, 0, 255, 50);

	glTranslatef(0, -5, 0);
	glScalef(1.0, 0.1, 1.0);
	glutSolidOctahedron();

	glTranslatef(0, -3.0f, 0);
	glScalef(1.25, 0.5, 1.25);
	glRotatef(45, 0, 1, 0);
	glutSolidOctahedron();

	glTranslatef(0, -3.0f, 0);
	glScalef(0.15f, 1.5f, 0.15f);
	glRotatef(45, 0, 1, 0);
	glutSolidOctahedron();
	
	glPopMatrix();
	glPushMatrix();

	//Draw Top Outer Part
	glTranslatef(0, 3.75f, 0);
	glScalef(0.5, 0.1, 0.5);
	glutSolidOctahedron();
	glTranslatef(0, 1.5, 0);
	glScalef(0.75, 0.75, 0.75);
	glutSolidOctahedron();

	glTranslatef(0, 1.5f, 0);
	glColor4f(255, 0, 0, 50);

	glPopMatrix();
	glPushMatrix();

	glTranslatef(0, 4.4f, 0);
	glutSolidSphere(0.05f, 50, 50);

	glPopMatrix();
	glPushMatrix();

	glColor4f(0, 0, 255, 50);

	glTranslatef(0, 5, 0);
	glScalef(1.0, 0.1, 1.0);
	glutSolidOctahedron();

	glTranslatef(0, 3.0f, 0);
	glScalef(1.25, 0.5, 1.25);
	glRotatef(45, 0, 1, 0);
	glutSolidOctahedron();

	
	glTranslatef(0, 3.0f, 0);
	glScalef(0.15f, 1.5f, 0.15f);
	glRotatef(45, 0, 1, 0);
	glutSolidOctahedron();

	glPopMatrix();

	glFlush();

}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}

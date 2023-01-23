#include "project.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857

void drawLeg() {
	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glTranslatef(2, 0, -2);
	glRotatef(20, 1, 0, 1);
	glScalef(0.5, 5, 0.5);	
	glutSolidCube(1);
	glPopMatrix();
}

void drawX_Leg() {
	glColor3f(0.6, 0.3, 0);
	glPushMatrix();
	glTranslatef(2, 0, -0.5);
	glRotatef(15, 0, 0, 1);
	glRotatef(42, 1, 0, 0);
	glScalef(0.5, 6.2, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0.5);
	glRotatef(15, 0, 0, 1);
	glRotatef(-42, 1, 0, 0);
	glScalef(0.5, 6.2, 0.5);
	glutSolidCube(1);
	glPopMatrix();
}

void drawLatterPart() {
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.1, 0);
	glTranslatef(0, -3.5, 0);
	glScalef(7, 1, 7);
	glRotatef(45, 0, 0, 1);
	glutSolidDodecahedron();
	glPopMatrix();

	glPushMatrix();	
	for (int i = 0; i <= 360; i += 90) {
		glRotatef(i, 0, 1, 0);
		drawLeg();
		drawX_Leg();
	}
	glPopMatrix();	

	glPopMatrix();
}

void topStage() {
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(0, 2.35, 0);
	glScalef(4.5, 0.25, 4.5);
	glutSolidCube(1);
	glPopMatrix();
}

void drawCylinder(GLfloat radius, GLfloat height){
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -(height / 2));	
	//glRotatef(180, 1, 0, 0);

	/** Draw the tube */
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on top of cylinder */
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();

	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, 0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();
	glPopMatrix();
}

void drawCrainArmSide(float crainWidth) {
	//float length = 6;

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);

	glPushMatrix();
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(-0.3, 0.3, 0);
	glVertex3f(-0.1, 0.1, crainWidth);

	glVertex3f(0.3, 0.3, 0);
	glVertex3f(0.1, 0.1, crainWidth);
	glEnd();
	glLineWidth(1);
	glPopMatrix();

	glPopMatrix();
}

void drawCrainArm(float crainArm, float crainWidth) {
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glPushMatrix();
	glTranslatef(0, 3.5, 1.7);
	glRotatef(crainArm - 40, 1, 0, 0);
	glPushMatrix();
	for (float i = 0; i <= 350; i += 90) {
		glRotatef(i, 0, 0, 1);
		drawCrainArmSide(crainWidth);
	}
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(-0.1, 0.1, crainWidth);
	glVertex3f(0.1, 0.1, crainWidth);
	glVertex3f(0.1, -0.1, crainWidth);
	glVertex3f(-0.1, -0.1, crainWidth);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void drawControlRoomWindowsSide() {
	glPushMatrix();

	// window wall
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -0.8, 1.5);
	glVertex3f(1.5, -0.8, 1.5);
	glVertex3f(1.5, 0.8, 1.5);
	glVertex3f(-1.5, 0.8, 1.5);
	glEnd();
	glPopMatrix();

	glColor3f(0.1, 0.1, 0.1);
	//left window
	glPushMatrix();	
	glTranslatef(0, 0, 1.5);
	glScalef(2.4, 1.2, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	// roof
	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glTranslatef(0, 0.88, 0);
	glScalef(4, 0.16, 4);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawControlRoomWindows() {
	glPushMatrix();
	for (int i = 0; i <= 360; i += 90) {
		glRotatef(i, 0, 1, 0);
		drawControlRoomWindowsSide();
	}
	glPopMatrix();
}

void drawOperatingRoom(float crainArm, float crainWidth) {
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, 2.7, 0);
	drawCylinder(1.5, 0.6);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glTranslatef(0, 3.7, 0);
	glScalef(2, 0.7, 2);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5.2, 0);
	drawControlRoomWindows();
	glPopMatrix();

	drawCrainArm(crainArm, crainWidth);

	glPopMatrix();
}



void drawCrain(float crainY, float crainArm, float crainWidth) {
	glPushMatrix();
	glScalef(0.6, 0.6, 0.6);	
	glPushMatrix();
	drawLatterPart();
	topStage();

	glPushMatrix();
	glRotatef(crainY, 0, 1, 0);
	drawOperatingRoom(crainArm, crainWidth);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}
#include<windows.h>
#include<Gl/freeglut.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
float xr, yr = 0;
float y = 200;
float i = 200;
float n = 200;
float b = 200;




void ucgen_1_ciz() {

	glBegin(GL_TRIANGLES);
	glColor3f(0.7, 0.2, 0.9);
	glVertex2f(75, y + 450);
	glVertex2f(118.5, y + 362.5);
	glVertex2f(161.5, y + 450);
	glEnd();
}

void ucgen_2_ciz() {


	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 1.5);
	glVertex2f(200, i + 450);
	glVertex2f(243.5, i + 362.5);
	glVertex2f(286.5, i + 450);
	glEnd();
}

void ucgen_3_ciz() {


	glBegin(GL_TRIANGLES);
	glColor3f(1.7, 0.9, 0.4);
	glVertex2f(250, n + 450);
	glVertex2f(293.5, n + 362.5);
	glVertex2f(337, n + 450);
	glEnd();
}

void ucgen_4_ciz() {


	glBegin(GL_TRIANGLES);
	glColor3f(0.6, 0.3, 0.1);
	glVertex2f(300, b + 350);
	glVertex2f(343.5, b + 262.5);
	glVertex2f(387, b + 350);

	glEnd();
}

void kare_ciz() {
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(100 + xr, 50 + yr);
	glVertex2f(158 + xr, 50 + yr);
	glVertex2f(158 + xr, 108 + yr);
	glVertex2f(100 + xr, 108 + yr);
	glEnd();

}

void gorunum() {
	glClear(GL_COLOR_BUFFER_BIT);

	kare_ciz();
	ucgen_4_ciz();
	ucgen_3_ciz();
	ucgen_2_ciz();
	ucgen_1_ciz();

	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}

void Timer(int timer) {
	y -= rand() % 10;
	i -= rand() % 5;
	n -= rand() % 7;
	b -= rand() % 4;
	glutTimerFunc(10, Timer, 0);

	if (y <= -600)
		y = 200;

	if (i <= -600)
		i = 300;

	if (n <= -600)
		n = 220;

	if (b <= -600)
		b = 350;

	glutPostRedisplay();
}




void specialKey(int key, int x, int y) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		xr = xr + 10;
		cout << xr << endl;
		glutPostRedisplay();
		break;
	case GLUT_KEY_LEFT:
		xr = xr - 10;
		cout << xr << endl;
		glutPostRedisplay();
		break;
	}
}


int main(int argc, char**argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(466, 700);
	glutInitWindowPosition(600, 50);
	glutCreateWindow("Yon Tuslarýyla Hareket");
	glutDisplayFunc(gorunum);
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0.0, 400, 0.0, 400);
	glutSpecialFunc(specialKey);
	Timer(0);
	glutTimerFunc(1000, Timer, 0);
	glutMainLoop();
	return 0;

}

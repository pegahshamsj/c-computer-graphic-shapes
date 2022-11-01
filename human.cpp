#include <GL/glut.h>

int Height=400, Width=400;

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.0, -0.25);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.25, 0.0);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.25, 0.0);
	glVertex2f(0.0, -0.25);
	glVertex2f(0.25, -0.75);
	glVertex2f(0.0, -0.25);
	glVertex2f(-0.25, -0.75);
	glEnd();
	glColor3f(1, 0.7, 0);
	glBegin(GL_QUADS);
	glVertex2f(0.25, 0.75);
	glVertex2f(-0.25, 0.75);
	glVertex2f(-0.25, 0.5);
	glVertex2f(0.25, 0.5);
	glEnd();
	glColor3f(1,1,0.5);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2f(0.12, 0.65);
	glVertex2f(-0.12, 0.65);
	glEnd();
	glColor3f(1,0,0.5);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(-0.12, 0.55);
	glVertex2f(0.12, 0.55);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Hello OpenGL World");
	glutDisplayFunc(display);
	glutMainLoop();
}

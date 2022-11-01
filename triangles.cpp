#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(10);
	glLineWidth(5);
	//glShadeModel(GL_FLAT);
	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(0.75,0.0);
	glVertex2f(0.0,0.9);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(-0.75,0.7);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-0.5,-0.5);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(-0.75,-0.8);
	glColor3f(1.0,0.0,1.0);
	glVertex2f(0.0,-0.9);
	glVertex2f(-0.7,-0.9);
	glVertex2f(0.6,-0.4);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(600,200);
	glutInitWindowSize(400,400);
	glutCreateWindow("Program No.2");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

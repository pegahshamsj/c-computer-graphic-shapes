#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(40);
	glLineWidth(8);
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(0.5,0.5);
	glColor3f(0.0,0.0,1.0); 
	glVertex2f(-0.5,-0.7);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(-0.5,0.7);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(0.5,-0.7);
	glEnd();

	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(400,400);
	glutCreateWindow("Program No.1");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

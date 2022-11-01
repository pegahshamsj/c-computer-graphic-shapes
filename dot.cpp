#include <GL/glut.h>
#include <math.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_FLAT);
	glColor3f(1.0,1.0,1.0);
	float size=5.0;
	float frac=0.2;
	float angle=0.0;
	float r=0.5;	
	glPointSize(size);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0,0.0);
	for(;angle<=6.283;angle+=frac){	
		glVertex2f(r*cos(angle),r*sin(angle));
	}
	glVertex2f(0.5,0.0);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(500,300);
	glutInitWindowSize(400,400);
	glutCreateWindow("Program No.2");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

#include <GL/glut.h>
#include <math.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_FLAT);
	glColor3f(0.2,0.7,0.4);
	float size=3.0;
	float frac=0.0001;
	float x=-0.7;	
	glPointSize(size);
	glBegin(GL_POINTS);
	for (;x<=0.7;x+=frac){	
		glVertex2f(x,sqrt(0.49-x*x));
		glVertex2f(x,-sqrt(0.49-x*x));
	}
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

#include <GL/glut.h>
#include <math.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel(GL_FLAT);
	int n=300;
	float x=0.0;
	float frac=6.283/n;
	float c=0.0;
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(0.0,0.0);
		for(int i=1;i<=n+1;i++){
			glColor3f(c,0.0,0.0);
			glVertex2f(cos(x),sin(x));
			x = x+frac;
			c=c+1.0/n;
		}
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(700,200);
	glutInitWindowSize(400,400);
	glutCreateWindow("Program No.2");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

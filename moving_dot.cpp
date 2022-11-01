#include <GL/glut.h>
#include<iostream>
using namespace std;

GLfloat tx=0;
GLfloat ty=0;
GLint i=0;
GLfloat A[2][100];

void mouse(int button, int state, int x, int y){
	if (button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
		tx= (x-300.0)/300.0;
		ty= (300.0-y)/300.0;
		i++;
        A[0][i]=0;
        A[1][i]=ty;
		glutPostRedisplay();
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(20.0);
    glColor3f(1,0,1);
    glBegin(GL_POINTS);
	glVertex2f(A[0][i],A[1][i]);
	cout<<i;
    glEnd();
    glutSwapBuffers();
    }

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(700,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Animation");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

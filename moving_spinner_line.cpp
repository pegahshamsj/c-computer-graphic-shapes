#include <GL/glut.h>
#include<iostream>
using namespace std;
GLfloat a=0.0;
int Height=400, Width=400;
GLfloat d=1.0;
GLint f=0;

void fi(void){
	if(f==1){
		//if(a>=0)a=0;
		if(a<360)
    		a=a-0.9;
		//else a=0.0;
		cout<<a<<endl;
		if(d<1)
    		d=d+0.004;	
    	else f=0;
    }
	if(f==0){
    	if(a<360)
    		a=a+0.9;
    	else a=0.0;
		if(d>-1.0)
    		d=d-0.004;
		else f=1;
	}
glutPostRedisplay();
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(0.4,0.74,0.23);
	glLoadIdentity();
	glTranslatef(d,0.0,0.0);
	glRotatef(a,0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(0.3, 0.75);
	glVertex2f(-0.3, -0.75);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Hello OpenGL World");
	glutDisplayFunc(display);
	glutIdleFunc(fi);
	glutMainLoop();
}

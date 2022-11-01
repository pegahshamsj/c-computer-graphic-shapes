#include <GL/glut.h>
#include <stdlib.h>

GLfloat tx=0.0;
GLfloat ty=0.0;
GLfloat r=1.0;
GLfloat g=1.0;
GLfloat b=1.0;
GLfloat angle = 50.0;

void idle(void){
	if(angle < 360)
		angle += tx-ty;
	else
		angle = 0;
	glutPostRedisplay();
};

void motion2(int x, int y){
	b=0.0;
	tx= (x-300.0)/300.0;
	ty= (300.0-y)/300.0;
	glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(r,g,b);
	glLoadIdentity();
	glRotated(angle,1.0,1.0,0);
	glutWireCube(0.8);
   	// glutWireSphere(0.5,4,20);
	//glutWireCone(0.5,0.5,120,2);
   	// glutWireTorus(0.2,0.4,20,50);
    //glutWireTeapot(0.5);
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(700,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Animation");glutIdleFunc(idle);
	glutDisplayFunc(display);
	//glutMotionFunc(motion2);
	glutPassiveMotionFunc(motion2);
    
    glutMainLoop();
	return 0;
}

#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

GLfloat angle = 50.0;
GLfloat tx=0.0;
GLfloat ty=0.0;
GLfloat r=1.0;
GLfloat g=1.0;
GLfloat b=1.0;
GLfloat c=1.0;
GLfloat a=1.0;
GLfloat d=1.0;
GLfloat e=1.0;
GLfloat f=1.0;
GLfloat h=1.0;
GLfloat n=1.0;
GLfloat m=1.0;
GLfloat p=1.0;

void idle(void){
	if(angle < 360)
		angle += 0.2;
	else
		angle = 0;
	glutPostRedisplay();
};

void keyboard(unsigned char key, int x, int y){
	switch(key){
		case 'V': 
			if((x<200)&&(y<200)){
				r=0.0;g=1.0;b=1.0;
			}
		break;
		case 'P': 
			if((x<200)&&(y<200)){
				r=1.0;g=0.4;b=1.0;
			}
		break;
		case 'L':
			if((x<200)&&(y>200) ){
				a=1.0;c=0.5;d=0.0;
			}
		break;
        case 'J':
			if((x<200)&&(y>200)){
				a=0;c=0.6;d=1;
			}
		break;
		case 'R':
		    if((x>200)&&(y<200)){
				e=0.3;f=1.0;h=0.0;
			}
		break;
		case 'M':
		    if((x>200)&&(y<200)){
				e=1;f=1;h=0.6;
				}
		break;
		case 'B':
            if((x>200)&&(y>200)){
				m=0;n=0.89;p=0.66;
			}
		break;
		case 'Z':
            if((x>200)&&(y>200)){
				m=1;n=0;p=0;
			}
		break;
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glColor3f(r,g,b);
    glLoadIdentity();
    glRotated(30.0,1,1,0);
	glTranslatef(-0.5,0.5,0.0);
	glRotatef(0.0,0.0,0.0,1.0);
	glutSolidCube(0.4);
	glColor3f(e,f,h);
	glLoadIdentity();
	glRotated(30.0,1,1,0);
	glTranslatef(0.5,0.5,0.0);
	glutWireSphere(0.3,40,50);
	glColor3f(a,c,d);
	glLoadIdentity();
	glRotated(30.0,1,1,0);
	glTranslatef(-0.5,-0.5,0.0);
	glScaled(0.5,0.5,0.0);
	glutWireTorus(0.3,0.4,20,30);
	glColor3f(m,n,p);
	glLoadIdentity();
	glRotated(30.0,1,1,0);
    glTranslatef(0.5,-0.5,0.0);
	glutWireTeapot(0.3);
	glLoadIdentity();
	glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(100, 150);
	glutCreateWindow("Animation");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}

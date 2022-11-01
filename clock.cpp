#include <GL/glut.h>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include<iostream>
#include <math.h>

float angle1 = 0;
float angle2 = 0;
float angle3 = 0;

float a = 0.0;
float b = 0.0;
float c = 0.0;

float x = -1.0;
float y = 0.3;
int w=0;
int z=0;
float tx = 0;
float ty = 0;
float h=0;
float m=0;
float s=0;
void idle(){
	if(angle1<360) angle1+=6;
	else angle1 = 0;
	
	if(angle2<360*60) {
		angle2+=6;
	}
	else {
		angle2 = 0;		
		a=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0)));
		b=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0)));
		c=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0)));
	}

	if(angle3<360*3600) {
		angle3+=6;
		if (w ==1){
			w=0;
			a=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0)));
			b=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0)));
			c=0.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0)));
		}
	}
	else angle3 = 0;
	
	if(x<=1){
		x+=0.0000463;
		y = -(x*x)+0.8;
		if(z==1){
			x=tx;
			y=-(x*x)+0.8;
			z=0;
			angle1 = -((-1-x)/0.0000463)*6;
			angle2 = -((-1-x)/0.0000463)*6;
			angle3 = -((-1-x)/0.0000463)*6;
		}	
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){ 
	if (button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
    		
			tx = (x-300.0)/300.0;
			ty = (300.0-y)/300.0;
        	z=1;
        	glutPostRedisplay();
        
	}
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	glColor3f(1.0, 1.0,1.0);
	glTranslatef(0.0 , -0.4 , 0.0);
	glRotatef(-10 , -1.0 ,1.0 , 0.0);
	glutSolidCube (0.6);
	glPopMatrix();
	
	glLoadIdentity();
	glLineWidth(2);
	glColor3f(0.0, 0.0,1.0);
	glTranslatef(0.0 , -0.4 , 0.0);
	glRotatef(-10 , -1.0 ,1.0 , 0.0);
	glRotatef(-angle1 , 0.0 ,0.0 , 1.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,0.28);
	glEnd();
	glPopMatrix();
	
	glLoadIdentity();
	glColor3f(0.0, 1.0,0.0);
	glLineWidth(4);
	glTranslatef(0.0 , -0.4 , 0.0);
	glRotatef(-10 , -1.0 ,1.0 , 0.0);
	glRotatef(-angle2/60 , 0.0 ,0.0 , 1.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,0.25);
	glEnd();
	glPopMatrix();
	
	glLoadIdentity();
	glColor3f(1.0, 0.0,0.0);
	glLineWidth(6);
	glTranslatef(0.0 , -0.4 , 0.0);
	glRotatef(-10 , -1.0 ,1.0 , 0.0);
	glRotatef(-angle3/3600*5 , 0.0 ,0.0 , 1.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex2f(-0.17,-0.1);
	glEnd();
	
	glLoadIdentity();
	glColor3f(1.0,0.6,0.0);
    glTranslatef(x,y , 0.0);
	glutSolidSphere(0.08,100,100);
	
	glClearColor(a, b, c, 1.0);
	glutSwapBuffers();
}

void key(unsigned char k,int x,int y){
	switch(k){
		case 'h':
				angle3 += 21600;
				w = 1;
				glutPostRedisplay();
				break;
		case 'm':
				angle2 += 360;
				glutPostRedisplay();	
            break;
        case 's':
				angle1 += 6;
				glutPostRedisplay();	
            break;
	}
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(700,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Animation");
	glutDisplayFunc(display);
	glutIdleFunc(idle);	
	glutKeyboardFunc(key);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}

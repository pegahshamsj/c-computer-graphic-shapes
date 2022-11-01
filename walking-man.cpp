#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;

int Height = 400 , Width = 400;
float x = 0;
float y = 0;
float z = 0;
float yy = 0;
float xx = 0;
float angle1 = 0;
float angle2 = 0;
float angle3 = -30;
float angle4 = -45;
float angle5 = 0;
float angle6 = 0;
int n = 0;
int m = 0;
int l = 0;
int p = 0;
int d = 0;
void idle(void){
	if(x>20) exit(0);
	x+=0.0001;
	if(angle1>=0 &&angle1<=30&&n==0){
		angle1+=0.03;
	}
	if(angle1>30&&n==0){
		n=1;
		angle1-=0.03;
	}
	if(angle1>=0 &&angle1<=30&&n==1){
		angle1-=0.03;
	}
	if(angle1<=0&&n==1){
		n=0;
		angle1+=0.03;
	}
	if(angle6>=0 &&angle6<=20&&d==0){
		angle6+=0.02;
	}
	if(angle6>20&&d==0){
		d=1;
		angle6-=0.02;
	}
	if(angle6>=0 &&angle6<=20&&d==1){
		angle6-=0.02;
	}
	if(angle6<=0&&d==1){
		d=0;
		angle6+=0.02;
	}
	if(angle2>=0 &&angle2<=30&&n==0){
		angle2+=0.03;
		y+=0.00012;
	}
	if(angle2>30&&n==0){
		n=1;
		angle2-=0.03;
		y-=0.00012;
	}
	if(angle2>=0 &&angle2<=30&&n==1){
		angle2-=0.03;
		y-=0.00012;
	}
	if(angle2<=0&&n==1){
		n=0;
		angle2+=0.03;
		y+=0.00012;
	}
	if(angle3<=0 &&angle3>=-30&&m==0){
		angle3-=0.03;
		yy+=0.00015;
	}
	if(angle3<-30&&m==0){
		m=1;
		angle3+=0.03;
		yy-=0.00015;
	}
	if(angle3<=0 &&angle3>=-30&&m==1){
		angle3+=0.03;
		yy-=0.00015;
	}
	if(angle3>=0&&m==1){
		m=0;
		angle3-=0.03;
		yy+=0.00015;
	}
	if(angle4<=0 &&angle4>=-45&&l==0){
		angle4+=0.045;
		xx+=0.00009;
		
	}
	if(angle4>=0&&l==0){
		l=1;
		angle4-=0.045;
		xx-=0.00009;
	}
	if(angle4<=0 &&angle4>=-45&&l==1){
		angle4-=0.045;
		xx-=0.00009;
	}
	if(angle4<=-45&&l==1){
		l=0;
		angle4+=0.045;
		xx+=0.00009;
	}
	if(angle5>=0 &&angle5<=30&&p==0){
		angle5+=0.03;
		z-=0.00009;
	}
	if(angle5>30&&p==0){
		p=1;
		angle5-=0.03;
		z+=0.00009;
	}
	if(angle5>=0 &&angle5<=30&&p==1){
		angle5-=0.03;
		z+=0.00009;
	}
	if(angle5<=0&&p==1){
		p=0;
		angle5+=0.03;
		z-=0.00009;
	}
	glutPostRedisplay();
};

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(40.0f);
	glColor3f(0.9, 0.67, 0.0);
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glBegin(GL_LINES);
	glVertex2f(-0.8 , 0.5);
	glVertex2f(-0.8 , -0.25);
	glEnd();
	glColor3f(0.7, 0.7, 0.7);
	//rightarm
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.8 , 0.5 , 0.0);
	glRotatef(angle1 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(-0.07 , -0.25);
	glEnd();
	//righthand
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.87 , 0.25 , 0.0);
	glTranslatef(y , 0.0 , 0.0);
	glRotatef(2*angle2 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(0.07 , -0.25);
	glEnd();
	//leftarm
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.8 , 0.5 , 0.0);
	glRotatef(-angle1 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(0.1 , -0.27);
	glEnd();
	//lefhand
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.7 , 0.24 , 0.0);
	glTranslatef(yy , 0.0 , 0.0);
	glRotatef(-2*angle3 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(0.07 , -0.25);
	glEnd();
	glColor3f(0.29, 0.67, 0.04);
	//rightthigh
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.8 , -0.25 , 0.0);
	glRotatef(angle6 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(-0.05 , -0.26);
	glEnd(); 
	//rightfoot
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.85 , -0.5 , 0.0);
	glTranslatef(xx , 0.0 , 0.0);
	glRotatef(2*angle4 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(0.05, -0.28);
	glEnd();
	//leftthigh
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.8 , -0.25 , 0.0);
	glRotatef(-angle6 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0 , 0.0);
	glVertex2f(0.05 , -0.26);
	glEnd();
	//leftfoot
	glLoadIdentity();
	glTranslatef(x , 0.0 , 0.0);
	glTranslatef(-0.75, -0.5 , 0.0);
	glTranslatef(z , 0.0 , 0.0);
	glRotatef(-2*angle5 , 0.0 , 0.0 , 1);
	glBegin(GL_LINES);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.05, -0.28);
	glEnd();
	glColor3f(1.0,1.0,1.0);
	float size=5.0;
	float frac=0.2;
	float angle=0.0;
	float r=0.2;	
	glPointSize(size);
	glLoadIdentity();
	glTranslatef(x,0,0.0);
	glTranslatef(-0.8, 0.7, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0,0.0);
	for (;angle<=2*3.15;angle+=frac){	
		glVertex2f(r*cos(angle),r*sin(angle));
	}
	glEnd();
	glColor3f(0.0,0.0,0.0);
	float size1=5.0;
	float frac1=0.2;
	float angle1=0.0;
	float r1=0.03;	
	glPointSize(size1);
	glLoadIdentity();
	glTranslatef(x,0,0.0);
	glTranslatef(-0.75, 0.8, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0.0,0.0);
	for (;angle1<=2*3.15;angle1+=frac1){	
		glVertex2f(r1*cos(angle1),r1*sin(angle1));
	}
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv){ 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Walking man");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
} 

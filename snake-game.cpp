#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int up = 1;
int down = -1;
int right = 2;
int left = -2;
int sl = 2;
int currentDirection = right;
float X[500]={0 , -0.05};
float Y[500]={0 , 0};
float x = -0.5;
float y = -0.5;
bool food = true;
int i = 0 , j = 0;
int c = 0;
int a , b;

void idle(){
	c++;
	if(c%100 == 0){
		for(i = sl-1;i>0;i--){
		X[i] = X[i-1];
		Y[i] = Y[i-1];
	}
	c = 0;
	if(currentDirection == up) Y[0]+= 0.05;
	else if(currentDirection == down) Y[0]-= 0.05;
	else if(currentDirection == right) X[0] += 0.05;
	else if(currentDirection == left) X[0]-= 0.05;
	}
	if(X[0] >= 1.05 || Y[0] >= 1.05 || X[0] <= -1.05 || Y[0] <= -1.05){
		std::cout<<"GAME OVER";
		exit(0);
	}
	srand ((unsigned int)time(NULL));
	if(food){
		aaa:
		a = x;
		b = y;
		x = -0.9 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.8)));
		y = -0.9 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.8)));
		if((X[0]+0.05 >= x && Y[0]+0.05 >= y && X[0]+0.05 <= x+0.05 && Y[0]+0.05 <= y+0.05) || (X[0] <= x+0.05 && Y[0]+0.05 >= y && X[0] >= x && Y[0]+0.05 <= y+0.05)
	||(X[0]+0.05 >= x && Y[0] <= y+0.05 && X[0]+0.05 <= x+0.05 && Y[0] >= y)||(X[0] <= x+0.05 && Y[0] <= y+0.05 && X[0] >= x && Y[0] >= y)){
		goto aaa;
	}
		food = false;
	}
	if((X[0]+0.05 >= x && Y[0]+0.05 >= y && X[0]+0.05 <= x+0.05 && Y[0]+0.05 <= y+0.05) || (X[0] <= x+0.05 && Y[0]+0.05 >= y && X[0] >= x && Y[0]+0.05 <= y+0.05)
	||(X[0]+0.05 >= x && Y[0] <= y+0.05 && X[0]+0.05 <= x+0.05 && Y[0] >= y)||(X[0] <= x+0.05 && Y[0] <= y+0.05 && X[0] >= x && Y[0] >= y)){
		sl++;
		food = true;
	}
	for(i = 3 ; i < sl ; i++)
		if((X[0]+0.05 >= X[i] && Y[0]+0.05 >= Y[i] && X[0]+0.05 <= X[i]+0.05 && Y[0]+0.05 <= Y[i]+0.05) || (X[0] <= X[i]+0.05 && Y[0]+0.05 >= Y[i] && X[0] >= X[i] && Y[0]+0.05 <= Y[i]+0.05)
	||(X[0]+0.05 >= X[i] && Y[0] <= Y[i]+0.05 && X[0]+0.05 <= X[i]+0.05 && Y[0] >= Y[i])||(X[0] <= X[i]+0.05 && Y[0] <= Y[i]+0.05 && X[0] >= X[i] && Y[0] >= Y[i]) ){
			std::cout<<"GAME OVER";
			exit(0);
		}
	glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	//border
	glLineWidth(20.0);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1.0 , -1.0);
	glVertex2f(-1.0 , 1.0);
	glVertex2f(1.0 , 1.0);
	glVertex2f(1.0 , -1.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glRectd(x , y , x + 0.05 , y + 0.05);
	//snake

	for(i = 0 ; i < sl ; i++){
		glColor3f(1.0, 0.0, 0.0);
		glRectd(X[i] , Y[i] , X[i] + 0.05 , Y[i] + 0.05);
	}

	glutSwapBuffers();
}

void special(int key , int x , int y){
	switch(key){
		case GLUT_KEY_UP:
			if(currentDirection != down)
				currentDirection = up;
			glutPostRedisplay();
		break;
		case GLUT_KEY_DOWN:
			if(currentDirection != up)
				currentDirection = down;
			glutPostRedisplay();
		break;
		case GLUT_KEY_RIGHT:
			if(currentDirection != left)
				currentDirection = right;
			glutPostRedisplay();
		break;
		case GLUT_KEY_LEFT:
			if(currentDirection != right)
				currentDirection = left;
			glutPostRedisplay();
		break;
	}
}

int main(int argc , char **argv){
	glutInit(&argc , argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(500 , 500);
	glutCreateWindow("snake game");
	glutDisplayFunc(display);
	glutSpecialFunc(special);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

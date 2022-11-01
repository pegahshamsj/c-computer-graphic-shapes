#include <stdlib.h>
#include <GL/glut.h>
int Height=600, Width=600;

void drowBitmapText(char *string,float x,float y,float z){
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*c);
}

void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,1);
	drowBitmapText("Hello OpenGL World",0.0,0.5,0.0);
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Hello OpenGL World");
	glutDisplayFunc(display);
	glutMainLoop();
}

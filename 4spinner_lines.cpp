#include <GL/glut.h>

GLfloat angle = 0.0;
GLfloat x=0.5;
GLfloat y=0.5;

void idle(void){
	if(angle < 360)
		angle += 1.0;
	else
		angle = 0;
	glutPostRedisplay();
};

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(x, y, 0.0);
	glRotatef(angle,0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(0.3,-0.3);
	glVertex2f(-0.3,0.3);
	glEnd();
	glPopMatrix();
	glLoadIdentity();
	glTranslatef(-x, y, 0.0);
	glRotatef(2*angle,0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(0.3,-0.3);
	glVertex2f(-0.3,0.3);
	glEnd();
	glPopMatrix();
	glLoadIdentity();
	glTranslatef(-x, -y, 0.0);
	glRotatef(4*angle,0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(0.3,-0.3);
	glVertex2f(-0.3,0.3);
	glEnd();
	glPopMatrix();
	glLoadIdentity();
	glTranslatef(x, -y, 0.0);
	glRotatef(-4*angle,0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(0.3,-0.3);
	glVertex2f(-0.3,0.3);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Animation");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

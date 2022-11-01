#include <GL/glut.h>
#include <GL/gl.h>

GLfloat angle = 0.0;
GLfloat c=0.0;

void idle(void){
	if(angle < 360)
		angle += 0.2;
	else
		angle = 0;
	c+=0.001;
	glutPostRedisplay();
};

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, c, c);
	glTranslatef(0.5 , 0.5 , 0.0);
	glRotated(-angle,0.0,0.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5,0.0);
	glVertex2f(0.0,0.7);
	glVertex2f(-0.3,-0.3);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(700,100);
	glutInitWindowSize(400,400);
	glutCreateWindow("Animation");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}

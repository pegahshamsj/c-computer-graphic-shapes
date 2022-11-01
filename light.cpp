#include <GL/glut.h>

GLfloat angle = 50.0;
float a=-1.0;
float b=-1.0;
float f=-1.0;
float d=0.0;
int c=0;
int n=0;

void init(void){
   GLfloat mat_diffuse[] 	= {0.0, 1.0, 1.0, 1.0};
   GLfloat mat_shininess[] 	= {50};
   GLfloat light_position[] = {-0.7, 1.3, 0.0, 1.0};
   GLfloat light_diffuse[] 	= {1.0, 1.0, 1.0, 1.0};
   GLfloat light_dir[] 		= {a, b, 0.0};
   
   GLfloat light_position1[] = {1.0, 1.0, 0.0, 1.0};
   GLfloat light_diffuse1[]  = {1.0, 1.0, 1.0, 1.0};
   GLfloat light_dir1[]    	 = {f, d, 0.0};
   
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 60.0);
   glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);
   
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
   glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
   glLightf (GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
   glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir1);
   
   
   glEnable(GL_LIGHTING);
   glEnable(GL_DEPTH_TEST);
   glutPostRedisplay();
}

void idle(void){
	if(a<=1.0 && c==0){
		a+=0.005;
	}
	if(a>1.0){
		c=1;
	}
	if(a>=-1.0 && c==1){
		a-=0.005;
	}
	if(a<-1.0){
		c=0;
	}
	
	if(d>=-2.0 && n==0){
		d-=0.005;
	}
	if(d<-2.0){
		n=1;
	}
	if(d<=0.0 && n==1){
		d+=0.005;
	}
	if(d>0.0){
		n=0;
	}
	init();
	glutPostRedisplay();
};

void key(unsigned char k,int x,int y){
	switch(k){
		case 'z':
				glEnable(GL_LIGHT0);
				glutPostRedisplay();
				break;
		case 'x':
				glDisable(GL_LIGHT0);
				glutPostRedisplay();
            break;
        case 'c':
				glEnable(GL_LIGHT1);
				glutPostRedisplay();
            break;
        case 'v':
				glDisable(GL_LIGHT1);
				glutPostRedisplay();
            break;
	}
}

void display(){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.5 , 0.0 , 0.0);
	glutSolidTeapot (0.2);
	glLoadIdentity();
	glTranslatef(-0.5 , 0.0 , 0.0);
	glutSolidTeapot (0.2);
	glLoadIdentity();
	glTranslatef(0.0 , -1.1 , 0.0);
	glRotatef(-10 , 1.0 ,1.0 , 0.0);
	glutSolidCube (1.5);
	
	glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(700,100);
	glutInitWindowSize(600,600);
	glutCreateWindow("Animation");
	glutDisplayFunc(display);
	init ();
	glutIdleFunc(idle);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}

#include <GL/glut.h>

GLfloat r=1.0;
GLfloat g=0.0;
GLfloat b=0.0;

void init(void){
   GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50 };
   GLfloat light_position[] = { 1.0, 0.5, -0.7, 0.0 };
   GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
   GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void display(void){
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glutSolidTeapot (0.4);
   glFlush ();
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;
}

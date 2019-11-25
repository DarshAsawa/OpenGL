#include <GL/glut.h>
#include <stdlib.h>

void display(void)
{
    glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(10.0, 150.0);
	glVertex2f(30.0, 190.0);
	glVertex2f(50.0,150.0);
	glEnd();
	glFlush();
}


void mouse(int button,int state,int x,int y){
if(button== GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	for(int i=0;i<=540;i++){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(10.0+i, 150.0);
	glVertex2f(30.0+i, 190.0);
	glVertex2f(50.0+i,150.0);
	glEnd();
	glFlush();
}
}
glutSwapBuffers();
}

void myInit (void) 
{   
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glColor3f(0.0, 1.0, 0.0); 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    gluOrtho2D(0,600,0,400); 
} 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(600,400);
    glutCreateWindow("Triangle");
	myInit();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();

    return EXIT_SUCCESS;
}

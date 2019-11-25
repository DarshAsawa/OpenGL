
#include<stdio.h> 
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
int r;
void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON); 
	float x=-200, y=0, i;
	
	for ( i = 0; i <=360; i += 0.001) 
	{ 
	    glVertex2i(x+r*cos(i), y+r*sin(i)); 
	} 
	glEnd(); 
	glFlush(); 
} 

void mouse(int button,int state,int x,int y){
if(button== GLUT_LEFT_BUTTON && state == GLUT_DOWN){
	
	for(int j=1;j<200;j++){
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_POLYGON); 
	float x=-200, y=0, i; 
	for ( i = 0; i < (2 * pi); i += 0.001) 
	{ 	
		//moving circle in x direction.
		//incrementing values of x coordinate by j.
		glVertex2i(x+r*cos(i)+j, y+r*sin(i)); 
	} 
	glEnd(); 
	glFlush(); 
}
}

glutSwapBuffers();
}


void myInit (void) 
{ 
	glClearColor(1.0, 1.0, 1.0,1.0);
	glColor3f(0.0, 1.0, 0.0); 
	//glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300, 300, -300, 300); 
} 



int main (int argc, char** argv) 
{ 
	printf("Enter the radius: ");
	scanf("%d",&r);
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

	glutInitWindowSize(600, 600); 
	glutInitWindowPosition(300, 0); 
	
	glutCreateWindow("Moving Circle"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMouseFunc(mouse);
	glutMainLoop(); 
} 


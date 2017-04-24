#include "stdafx.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

void display() 
{
	GLint x[10],y[10],x1[10],y1[10],i,j,n,R;
	glClear(GL_COLOR_BUFFER_BIT);

n=5;R=200;
glBegin(GL_LINE_LOOP);
for(i=0;i<n;i++)
{
 x[i]=R*cos(2*3.14*i/n);
 y[i]=R*sin(2*3.14*i/n);
 glVertex2i(x[i],y[i]);
}
glEnd();
glFlush();

n=5;R=25;
for(j=0;j<n;j++)
{
 x1[j]=R*cos(2*3.14*j/n);
 y1[j]=R*sin(2*3.14*j/n);
 glVertex2i(-x1[j],-y1[j]);
}
glColor3f(1.0,0.0,0.0); 
i=2;
n=5;
glBegin(GL_LINES);
	for(j=0;j<n;j++)
{
	glVertex2i(x[i],y[i]);
	glVertex2i(-x1[j],-y1[j]);
	i=i+1;
	if(i==n) 
	{
	i=0;
	glVertex2i(x[i],y[i]);
	glVertex2i(-x1[j],-y1[j]);
	}
	else 
		{
		glVertex2i(x[i],y[i]);
		glVertex2i(-x1[j],-y1[j]);
		}
}
	
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
glutInitWindowSize(640,480); 
glutInitWindowPosition(100,150);
glutCreateWindow("Figura");
glClearColor(1.0, 1.0, 1.0, 0.0);  
glColor3f(0.0,1.0,0.0); 
glPointSize(4.0);
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(-640, 640.0, -480, 480.0);
glutDisplayFunc(display); 
glutMainLoop(); 
return 0;
}

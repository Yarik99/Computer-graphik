#include "stdafx.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

float 
X = 0, 
Y = 0, 
Sx = 1, 
Sy = 1, 
A = 0; 

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

/*void Keyboard(unsigned char key, int x, int y) { //перемещение,поворот и масштабирование с помощью мышки
glMatrixMode(GL_MODELVIEW); 
glLoadIdentity(); 
switch (key) { 
case 'd': //масштабирование вправо на 0.1
Sx+=0.1; 
break; 

case 'a': //масштабирование влево на 0.1
Sx-=0.1; 
break; 

case 'w': //масштабирование вверх на 0.1
Sy+=0.1; 
break; 

case 's': //масштабирование вниз на 0.1
Sy-=0.1; 
break; 

case '2': //передвижение вниз на 1
Y-=1; 
break; 

case '8': //передвижение вверх на 1
Y+=3;
X+=3;
break; 

case '4': //передвижение влево на 1
X-=1; 
break; 

/*case '6': //передвижение вправо на 1
X+=1; 
break; 

case 'e': //поворот влево на 15 градусов
A+=15; 
glRotatef(A,0.0f,0.0f,1.0f); 
break; 

case 'r': //поворот вправо на 15 градусов
A-=15; 
glRotatef(A,0.0f,0.0f,1.0f); 
break; 
} 
glScaled(Sx,Sy,0); 
glTranslated(X,Y,0); 
display(); 
} */


void myMouse(int button, int state, int x, int y) //перемещение с помощью мышки
{
	glMatrixMode(GL_MODELVIEW); 
glLoadIdentity();
if (button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{ X-=3;}
 else
{ if (button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
{X+=3;
}
}
glScaled(Sx,Sy,0); 
glTranslated(X,Y,0); 
display();
}

int main(int argc, char** argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(640, 480); 
glutInitWindowPosition(0, 0); 
glutCreateWindow("Primer"); 
glClearColor(1.0, 1.0, 1.0, 0.0); 
glColor3f(0.0, 0.0, 0.0); 
glPointSize(1.0); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(-640.0, 640.0, -480.0, 480.0); 
glutDisplayFunc(display); 
/*glutKeyboardFunc(Keyboard); */
glutMouseFunc(myMouse);
glutMainLoop(); 
return 0; 
}

#include "stdafx.h"
#include <math.h>
#include <glut.h>
#include <string.h>

float 
X = 0, 
Y = 0, 
Sx = 1, 
Sy = 1, 
A = 0; 

void display() 
{
	GLfloat x,y,min_y,max_y,i;
	int j;

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_STRIP);
	glColor3f(1.0f,0.0f,0.0f);
	for (x=0.5;x<10.0;x=x+0.1) 
	{
		y=cos(x)/(1.0+exp(-x));
					
		glVertex2f(x,y);
		printf("\nx=%f y=%f",x,y);
	}
	glEnd();
	glFlush();

	glColor3f(1.0, 0.0, 0.0); //оси
	glBegin(GL_LINES); 
	glVertex2f(-10.0, 0.0); //ось X
	glVertex2f(10.0, 0.0); 
	glVertex2f(1.0,-10.0); //ось Y
	glVertex2f(1.0,10.0);

	

	

	for(i=-10.0;i<=10.0;i=i+0.5)//черточки Х
		{
			glVertex2f(i,-0.05);
			glVertex2f(i,0.05);
		}
	for(i=-10.0;i<=10.0;i=i+0.1)//черточки Y
		{
			glVertex2f(0.8,i);
			glVertex2f(1.2,i);
		}
	glEnd();
	glFlush();

	glColor3f(0.0f, 0.0f, 0.0f); 
char text[10]; 
for (i=-10.0;i<=10.0;i+=0.1)//подписи координат Y
{ 
if (i==0) continue; 
glRasterPos2f(1.1,i); 
sprintf_s(text,"%2.1f",i); 
for (j=0;j<strlen(text);j++) 
	{ 
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, text[j]); 
	} 

} 
for (i=-10.0;i<=10.0;i+=0.5) //подписи координат Х
{ 
glRasterPos2f(i,-0.1); 
sprintf_s(text,"%2.1f",i); 
for (j=0;j<strlen(text);j++) 
	{ 
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,text[j]); 
	} 
} 
glRasterPos2f(0.6,0.91);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'Y');//надпись Y 
glRasterPos2f(9.7,0.06);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'X');//надпись Х

glBegin(GL_LINES);
glColor3f(1.0,0.0,0.0);

glVertex2f(10.0,0.0);//стрелка Х
glVertex2f(9.7,-0.05);
glVertex2f(10.0,0.0);
glVertex2f(9.7,0.05);

glVertex2f(1.0,1.0);//стрелка Y
glVertex2f(1.2,0.92);
glVertex2f(1.0,1.0);
glVertex2f(0.8,0.92);

glEnd();
glFlush();

	
	/*glEnd();
	glFlush();*/
}



void setWindowMir (float left,float right,float *min_y,float *max_y)
{
	float x,y;

	for (x=0.5;x<10.0;x=x+0.1) 
	{
		
			y=cos(x)/(1.0+exp(-x));
			if(y<=*min_y) *min_y=y;
			if(y>*max_y) *max_y=y;
			
	}
	printf("\nmin_y=%f max_y=%f",*min_y,*max_y);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(left,right,*min_y,*max_y);
}

void setViewEkr(int left,int right,int bottom,int top)
{
glViewport(left,bottom,right-left,top-bottom); 
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0f,0.0f,0.0f);
glPointSize(4.0);
}

void Start() 
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.5,10,-1,1,-1,1);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(0.1);
}

void Keyboard(unsigned char key, int x, int y) { 
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

case '8': //передвижение вниз на 1
Y-=1; 
break; 

case '2': //передвижение вверх на 1
Y+=1; 
break; 

case '6': //передвижение вправо на 1
X-=1; 
break; 

case '4': //передвижение влево на 1
X+=1; 
break; 
} 
glScaled(Sx,Sy,0); 
glTranslated(X,Y,0); 
display(); 
} 

int main(int argc, char** argv) 
{
	float min_y,max_y;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphik");
	Start();
	setWindowMir(0.5,10.0,&min_y,&max_y);
	setViewEkr(0,640,0,480);
	glutKeyboardFunc(Keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

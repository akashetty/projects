#include<stdio.h>
//#include<iostream>
#include<math.h>
#include<GL/glut.h>
#define c (3.141/180)

GLfloat x,/*tr,t,r=.032,*/i=-45;
int j;
void myInit()
{
 glClearColor(0,0,1,1);
 glColor3f(1,1,1);
 glPointSize(5);
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
 while(i<=135)
 {
 x=c*i;
 glColor3f(0,1,0);
 glBegin(GL_QUADS);
 glVertex2f(-.9+x,-.05+sin(8*x));
 glVertex2f(-1+x,-.1+sin(8*x));
 glVertex2f(-1+x,.1+sin(8*x));
 glVertex2f(-.9+x,.05+sin(8*x));
 glEnd();

 glBegin(GL_POLYGON);
 glVertex2f(-.9+x,.05+sin(8*x));
 glVertex2f(-.8+x,.15+sin(8*x));
 glVertex2f(-.7+x,.12+sin(8*x));
 glVertex2f(-.6+x,0+sin(8*x));
 glVertex2f(-.7+x,-.12+sin(8*x));
 glVertex2f(-.8+x,-.15+sin(8*x));
 glVertex2f(-.9+x,-.05+sin(8*x));
 glEnd();

 glColor3f(0,0,0);
 glBegin(GL_LINE_STRIP);
 glVertex2f(-.75+x,.08+sin(8*x));
 glVertex2f(-.8+x,.04+sin(8*x));
 glVertex2f(-.75+x,0+sin(8*x));
 glEnd();

 glFlush();
 glClear(GL_COLOR_BUFFER_BIT);
for(j=0;j<1000000;j++);
 i+=1;
 }
}
int main(int argc,char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(500,500);
 glutCreateWindow("fish");
 glutDisplayFunc(display);
 myInit();
 glutMainLoop();
}


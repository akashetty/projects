#include<GL/glut.h>
#include<stdio.h>
int top=8, bottom=4, left=1, right=2;
void cohen(float x1,float y11,float x2,float y2);
int outcode(int x, int y);
float xmin,xmax,yvmin,yvmax, ymin, ymax, xvmin, xvmax,x1,y11,x2,y2;
void display();
void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	printf("Enter xmin,xmax,ymin,ymax\n");
	scanf("%f%f%f%f",&xmin,&xmax,&ymin,&ymax);
	printf("Enter xvmin,xvmax,yvmin,yvmax\n");
	scanf("%f%f%f%f",&xvmin,&xvmax,&yvmin,&yvmax);
	printf("Enter x1,y1 and x2,y2\n");
	scanf("%f%f%f%f", &x1,&y11,&x2,&y2);
	glutCreateWindow("CS");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
void display(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(1,1,0);
	glRectf(xmin,ymin,xmax,ymax);
	glColor3f(0,1,1);
	glBegin(GL_LINES);
		glVertex2f(x1,y11);
		glVertex2f(x2,y2);
	glEnd();
	cohen(x1,y11,x2,y2);
	glFlush();
}
int outcode(int x, int y){
	int r=0;
	if(y>ymax)
		r=r|top;
	else if(y<ymin)
		r=r|bottom;
	if(x>xmax)
		r=r|right;
	else if(x<xmin)
		r=r|left;
	return r;
}
void cohen(float x1,float y11,float x2,float y2){
	int o1,o2,o3;
	int accept=0,stop=0;
	float x3,y3,x4,y4,x,y,sx,sy;
	x=x1;
	y=y11;
	while(!stop){
		o1=outcode(x1,y11);
		o2=outcode(x2,y2);
		if(o1==0 && o2==0){
			accept=1;
			stop=1;
		}
		else if(o1&o2){
			accept=0;
			stop=1;
		}
		else{
			o3=((o1==0)?o2:o1);
			if(o3&top){
				y=ymax;
				x=x1+((x2-x1)/(y2-y11))*(ymax-y11);
			}
			else if(o3&bottom){
				y=ymin;
				x=x1+((x2-x1)/(y2-y11))*(ymin-y11);
			}
			else if(o3&right){
				x=xmax;
				y=y11+((y2-y11)/(x2-x1))*(xmax-x1);
			}
			else{
				x=xmin;
				y=y11+((y2-y11)/(x2-x1))*(xmin-x1);
			}
			if(o3==o1){
				x1=x;
				y11=y;
			}
			else{
				x2=x;
				y2=y;
			}
		}

	}
	if(accept){
		glColor3f(1,0,0);
		glRectf(xvmin,yvmin,xvmax,yvmax);
		sx=(xvmax-xvmin)/(xmax-xmin);
		sy=(yvmax-yvmin)/(ymax-ymin);
		x3=xvmin+(x1-xmin)*sx;
		y3=yvmin+(y11-ymin)*sy;
		x4=xvmin+(x2-xmin)*sx;
		y4=yvmin+(y2-ymin)*sy;
		glColor3f(0,1,0);
		glBegin(GL_LINES);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glEnd();
		
	}
}

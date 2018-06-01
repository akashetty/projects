#include<stdio.h>
#include<GL/glut.h>
float x1,y11,x2,y2;
void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
}
void plot(int x, int y){
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
	
}
void bresenham(){
	int dx,dy,pk,x,y;
	int xinc, yinc,i;
	dx=x2-x1;
	dy=y2-y11;
	x=x1;
	y=y11;
	plot(x,y);
	if(dx>0)
		xinc=1;
	else
		xinc=-1;
	if(dy>0)
		yinc=1;
	else
		yinc=-1;
	if(abs(dx)>abs(dy)){
		pk=2*abs(dy)-abs(dx);
		for(i=0;i<(abs(dx)-1);i++){
			if(pk>0){
				y=y+yinc;
				pk=pk+2*abs(dy)-2*abs(dx);
			}
			else{
				y=y;
				pk=pk+2*abs(dy);
			}
			x=x+xinc;
			plot(x,y);
		}
	}
	else{
		pk=2*abs(dx)-abs(dy);
		for(i=0;i<=abs(dy)-1;i++){
			if(pk>0){
				x=x+xinc;
				pk=pk+2*abs(dx)-2*abs(dy);
			}
			else{
				x=x;
				pk=pk+2*abs(dx);
			}
			y=y+yinc;
			plot(x,y);
		}
		
	}
}
void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	bresenham();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	printf("Enter coordinates of first point:\n");
	scanf("%f%f", &x1, &y11);
	printf("Enter coordinates of second point:\n");
	scanf("%f%f", &x2, &y2);
	glutCreateWindow("Bresenham");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

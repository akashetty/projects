#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
float v[3][2] = {{20,40}, {10,20}, {30,20}};
float v1[3][2] = {{-20,40}, {-10,20}, {-30,20}};
int a;
char s1[] = "Rotation wrt origin";
char s2[] = "Rotation wrt fixed point";
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-80,80,-80,80);
	glMatrixMode(GL_MODELVIEW);
}
void drawTriangle(float *a, float *b, float *c){
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}
void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	glColor3f(1,1,0);
	glRasterPos2f(-70,5);
	for(int i=0;i<strlen(s1);i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s1[i]);
	
	glRasterPos2f(-20,50);
	for(int i=0;i<strlen(s2);i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s2[i]);
		
	glColor3f(1,0,0);
	drawTriangle(v[0], v[1], v[2]);
	glPushMatrix();
		glColor3f(0,1,0);
		glTranslatef(10,20,0);
		glRotatef(a,0,0,1);
		glTranslatef(-10,-20,0);
		drawTriangle(v[0], v[1], v[2]);
	glPopMatrix();
	
	glColor3f(0.1,0.5,0);
	drawTriangle(v1[0], v1[1], v1[2]);
	glPushMatrix();
		glColor3f(0.6,1,0.5);
		glRotatef(a,0,0,1);
		drawTriangle(v[0], v[1], v[2]);
	glPopMatrix();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	printf("Enter the angle of Rotation:\n");
	scanf("%d", &a);
	glutCreateWindow("Rotate triangle");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

  


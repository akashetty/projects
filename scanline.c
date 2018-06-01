#include<GL/glut.h>
#include<stdio.h>
float v[100][2];
int n,a,b;
void edgeDetect(float x1, float y1, float x2, float y2, int *le, int *re) {
	int temp;
	float mx,x;
	if((y2-y1) < 0 ) {
		temp = y1;
		y1 = y2;
		y2 = temp;
		temp = x1;
		x1 = x2;
		x2 = temp;
	}
	if((y2-y1) != 0)
		mx = (x2-x1)/(y2-y1);
	else
		mx = x2-x1;
	x = x1;
	for(int i=y1;i<=y2;i++) {
		if(x<(float)le[i])
			le[i] = (int)x;
		if(x>(float)re[i])
			re[i] = (int)x;
		x = x + mx;
	}
}
void drawPixels(int p, int q) {
	glBegin(GL_POINTS);
	glVertex2i(p,q);
	glEnd();
	glFlush();
}
void scanfill() {
	int i;
	int le[500], re[500];
	for(int i=0;i<500;i++) {
		le[i] = 500;
		re[i] = 0;
	}
	for(i=0;i<n-1;i++) {
		edgeDetect(v[i][0], v[i][1], v[i+1][0], v[i+1][1], le, re);
	}
	edgeDetect(v[i][0], v[i][1], v[0][0], v[0][1], le, re);
	for(i=0;i<500;i++) {
		if(le[i] <= re[i]) {
			for(int j=(int)le[i];j<=(int)re[i];j++)
				drawPixels(j, i);
		}
	}
}
void display() {
	//glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<n;i++){
			glVertex2f(v[i][0], v[i][1]);
		}
	glEnd();
	scanfill();
	glFlush();
}
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}
void sub(int id){
	if(id==1)
		glColor3f(1,1,0);
	if(id==2)
		glColor3f(1,0,0);
	glutPostRedisplay();
}
void sub1(int id){
	if(id==1)
		glClearColor(0.6,0.6,1,0);
	if(id==2)
		glClearColor(1,0.4,0.6,0);
	glutPostRedisplay();
}
void menu(int id){
	if(id==a)
		sub(id);
	if(id==b)
		sub1(id);
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	printf("Enter the number of vertices of polygon:\n");
	scanf("%d", &n);
	printf("Enter the vertices:\n");
	for(int i=0;i<n;i++)
		scanf("%f%f", &v[i][0], &v[i][1]);
	glutCreateWindow("Filling a polygon");
	init();
	glutDisplayFunc(display);
	a = glutCreateMenu(sub);
	glutAddMenuEntry("yellow",1);
	glutAddMenuEntry("red",2);
	b = glutCreateMenu(sub1);
	glutAddMenuEntry("blue",1);
	glutAddMenuEntry("pink",2);
	glutCreateMenu(menu);
	glutAddSubMenu("Foreground color",a);
	glutAddSubMenu("Background color",b);
	glutAttachMenu(GLUT_RIGHT_BUTTON);		
	glutMainLoop();
}

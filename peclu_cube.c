#include<GL/glut.h>
#include<stdio.h>
void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-20,20,-20,20,20,220);
	glMatrixMode(GL_MODELVIEW);
}

float copx=20,copy=20,copz=30;
float v[8][3] = {{-10,-10,10}, {-10,10,10}, {10,10,10}, {10,-10,10}, {10,-10,-10}, {10,10,-10}, {-10,10,-10}, {-10,-10,-10}};

void draw_cube_face(float *a, float *b, float *c, float *d) {
	glBegin(GL_QUADS);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
		glVertex3fv(d);
	glEnd();
}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	printf("%f %f %f\n", copx, copy, copz);
	gluLookAt(copx,copy,copz,0,0,0,0,1,0);
	glColor3f(0.3, 0.6, 0.8);
	draw_cube_face(v[0], v[1], v[2], v[3]);
	glColor3f(0.4, 0.7, 0.9);
	draw_cube_face(v[3], v[2], v[5], v[4]);
	glColor3f(0.8, 0.6, 0.3);
	draw_cube_face(v[4], v[5], v[6], v[7]);
	glColor3f(0.9, 0.7, 0.4);
	draw_cube_face(v[1], v[2], v[5], v[6]);
	glColor3f(0.2, 0.4, 0.6);
	draw_cube_face(v[7], v[6], v[1], v[0]);
	glColor3f(0.6, 0.4, 0.2);
	draw_cube_face(v[0], v[3], v[4], v[7]);
	glFlush();
}

void move(unsigned char k, int x, int y) {
	if(k == 'x')
		copx+=1;
	if(k == 'X')
		copx--;
	if(k == 'y')
		copy++;
	if(k == 'Y')
		copy--;
	if(k == 'z')
		copz++;
	if(k == 'Z')
		copz--;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Perspective viewing cube");
	glutKeyboardFunc(move);
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

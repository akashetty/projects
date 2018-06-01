#include<GL/glut.h>
#include<stdio.h>
void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20,20,-20,20,-20,20);
	glMatrixMode(GL_MODELVIEW);
}

float v[8][3] = {{-10,-10,10}, {-10,10,10}, {10,10,10}, {10,-10,10}, {10,-10,-10}, {10,10,-10}, {-10,10,-10}, {-10,-10,-10}};
float a=1;

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
	glRotatef(-a,-a,a,1);
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

void spin() {
	if(a>360)
		a = 0;
	else
		a = a + 0.05;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Cube");
	glutInitDisplayMode(GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	init();
	glutDisplayFunc(display);
	glutIdleFunc(spin);
	glutMainLoop();
}

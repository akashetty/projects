#include<GL/glut.h>
void init() {
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20,20,-20,20,-20,20);
	glMatrixMode(GL_MODELVIEW);
}
void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float amb[3] = {0.1,0.3,0.5}, dif[3] = {0.5,0.7,0.1}, spe[3] = {0.5,0.1,0.7}, pos[4] = {20,10,10,0}, col[3] = {0.5,0.5,0.5}, col1[3] = {0.2,0.4,0.7};
	glLightfv(GL_LIGHT5, GL_AMBIENT, amb);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, dif);
	glLightfv(GL_LIGHT5, GL_SPECULAR, spe);
	glLightfv(GL_LIGHT5, GL_POSITION, pos);
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, col1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, col1);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, col1);
	
	glLoadIdentity();
	//glPushMatrix();
	//glRotatef(30,1,1,1);
	glPushMatrix();
		glTranslatef(-4,5,12);
		glRotatef(30,1,1,1);
		glutSolidTeapot(5);
	glPopMatrix();

	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, col);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, col);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, col);

	glPushMatrix();
		glTranslatef(-2,1,1);	
		glRotatef(30,1,1,1);
		glScalef(5,0.6,5);
		glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-14,-8,-15);
		glRotatef(20,1,1,1);
		glScalef(0.6,3,0.5);
		glutSolidCube(5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-7,-12,12);
		glRotatef(20,1,1,1);
		glScalef(0.6,3,0.5);
		glutSolidCube(5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(7,-4.2,-15);
		glRotatef(20,1,1,1);
		glScalef(0.6,3,0.5);
		glutSolidCube(5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(13,-6.5,5);
		glRotatef(20,1,1,1);
		glScalef(0.6,3,0.5);
		glutSolidCube(5);
	//glPopMatrix();

	
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("teapot");
	glutInitDisplayMode(GLUT_DEPTH);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT5);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

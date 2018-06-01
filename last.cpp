#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

int solid= 1,flag = 1;
GLUquadricObj *qobj;
float x=0,y=0,r=0,n=0;
int flag1 = 0;
char MP[]="Mini project on";
char Heading[]="Missile Launch";
char start[]="Press Enter to start";
char submittedby[]="Submitted by:";
char guidance[]="Under the Guidance of:";
char yourname[]="Akash Shetty";
char partnername[]="Arjun Suvarna";
char yournumber[]="4SF15CS006";
char partnernumber[]="4SF15CS020";
char teacher1name[]="Mrs.Sadhana";
char text1j[]={"Asst. Professor, Dept of CSE"};
char teacher2name[]="Mr.Shailesh Shetty S";
char text2j[]={"Asst. Professor, Dept of CSE"};
char college[]={"Sahyadri college of Engineering and Management"};
int m;

char message[] = {"In a nuclear war there would no victors,"};
char message2[] = {"ONLY VICTIMS"};
char message3[] = {"So stop this for survival of mankind"};

char rock[] = {"Press s to launch the missile"};

GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };				
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat light_position[] = { 2.5, 2.5, 2.5, 0.0 };

GLfloat mat_ambient1[] = { 0.6, 0.4, 0.2, 1.0 };	//land			
GLfloat mat_specular1[] = { 0.9, 0.7, 0.7, 1.0 };
GLfloat mat_shininess1[] = { 50.0 };
GLfloat model_ambient1[] = { 0.7, 0.4, 0.2, 1.0 };
GLfloat light_position1[] = { 2.5,2.5,2.5,0};

GLfloat mat_ambient2[] = { 0, 0, 1, 1.0 };		//sea		
GLfloat mat_specular2[] = {0.6, 0.6, 1.0, 1.0 };
GLfloat mat_shininess2[] = { 50.0 };
GLfloat model_ambient2[] = { 0, 0, 1, 1.0 };
GLfloat light_position2[] = {2.5, 2.5, 2.5,0.0};

GLfloat mat_ambient3[] = { 0.1, 0.1, 0.1, 1.0 };	//stand		
GLfloat mat_specular3[] = {1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess3[] = { 50.0 };
GLfloat model_ambient3[] = { 0.7, 0.2, 0.2, 1.0 };
GLfloat light_position3[] = {2.5, 2.5, 2.5,0.0};

GLfloat mat_ambient4[] = { 0.1, 0.1, 0.1, 1.0 };	//mountain	
GLfloat mat_specular4[] = {0.8, 0.3, 0.1, 1.0 };
GLfloat mat_shininess4[] = { 50.0 };
GLfloat model_ambient4[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat light_position4[] = {2.5, 2.5, 2.5,0.0};

GLfloat mat_ambient5[] = { 1.0, 0.7, 0.1, 1.0 };	//windows	
GLfloat mat_specular5[] = {1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess5[] = { 50.0 };
GLfloat model_ambient5[] = { 1.0, 0.7, 0.1, 1.0 };
GLfloat light_position5[] = {2.5, 2.5, 2.5,0.0};

GLfloat mat_ambient6[] = { 0.0, 0.0, 0.0, 1.0 };		//text	
GLfloat mat_specular6[] = {0.0, 0.0, 0.0, 1.0 };
GLfloat mat_shininess6[] = { 50.0 };
GLfloat model_ambient6[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_position6[] = {2.5, 2.5, 2.5,0.0};

void draw_sphere(float size)
{
	qobj=gluNewQuadric();
    	if(solid)
     		gluQuadricDrawStyle(qobj, GLU_FILL);  
    	else
      		gluQuadricDrawStyle(qobj, GLU_LINE);
 gluQuadricNormals(qobj, GLU_SMOOTH);
    	gluSphere(qobj,size,20,15);
	gluDeleteQuadric(qobj);
}

void draw_cylinder(float base_rad,float top_rad,float height)
{
	qobj=gluNewQuadric();
    	if(solid)
     		gluQuadricDrawStyle(qobj, GLU_FILL);  
    	else
      		gluQuadricDrawStyle(qobj, GLU_LINE);
    	gluQuadricNormals(qobj, GLU_SMOOTH);
    	gluCylinder(qobj,base_rad,top_rad,height,10,10);
    	gluDeleteQuadric(qobj);
}

void drawdisk()
{
	qobj=gluNewQuadric();
    	if(solid)
     		gluQuadricDrawStyle(qobj, GLU_FILL);  
    	else
      		gluQuadricDrawStyle(qobj, GLU_LINE);
    	gluQuadricNormals(qobj, GLU_SMOOTH);
    	gluDisk(qobj,0.01,1.5,10,10);
    	gluDeleteQuadric(qobj);
}

void draw_cube(float size)
{
 	 if(solid)
     		glutSolidCube(size);
    	else
      		glutWireCube(size);
}

void printlastpage()
{
	glClearColor(0.7,0.4,0.1,0.0);
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient6);			
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular6);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess6);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient6);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position6);
			glRasterPos3f(-1.6,1.1,0);
			for(m=0;message[m]!='\0';m++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, message[m]);

			glRasterPos3f(-.7,0.2,0);			
			for(m=0;message2[m]!='\0';m++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, message2[m]); 
			
            
			glRasterPos3f(-1.4,-0.8,0); 
			for(m=0;message3[m]!='\0';m++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message3[m]); 
			
			glFlush();
		glutSwapBuffers();

}

void printfirstpage()
{
	glClearColor(1.0,0.0,0.0,1.0);
	glColor3f(0,0,0);
	//Edit this for positioning College Name
	glRasterPos3f(-2,2.1,0);
	for(m=0;college[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, college[m]);

	//Edit this for positioning Mini project on
	glRasterPos3f(-.5,1.6,0);			
	for(m=0;MP[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, MP[m]); 
	            
	glRasterPos3f(-.6,1,0); 
	//Edit this for positioning heading or project name
	for(m=0;Heading[m]!='\0';m++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Heading[m]); 

	//glColor3f(1.0,0.0,0.0);
	//Edit this for positioning "Press key to start"	        
	glRasterPos3f(-.8,-2.2,0);//Bottom left
	for(m=0;start[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, start[m]); 
	
	//glColor3f(0.0,0.0,0.0);
	//Edit this for positioning Submitted By
	glRasterPos3f(-2.3,0,0);
	for(m=0;submittedby[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, submittedby[m]); 

	//glColor3f(0.0,0.0,0.0);
	//Edit this for positioning Guidance
	glRasterPos3f(.4,0,0);
	for(m=0;guidance[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, guidance[m]); 

	//glColor3f(1.0,0.0,0.0);
	//Edit this for positioning YourName			
	glRasterPos3f(-2,-.3,0);
	for(m=0;yourname[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, yourname[m]); 
	
	glRasterPos3f(-2,-.6,0);
	//Edit this for positioning Yournumber
	for(m=0;yournumber[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, yournumber[m]);
	
	glRasterPos3f(-2,-1,0);
	//Edit this for positioning PartnerName
	for(m=0;partnername[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18,partnername[m]);

	glRasterPos3f(-2,-1.3,0);
	//Edit this for positioning PartnerNumber
	for(m=0;partnernumber[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18,partnernumber[m]);
					
	glRasterPos3f(.7,-.3,0);
	//Just Change Position 
	for(m=0;teacher1name[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, teacher1name[m]); 
		
	glRasterPos3f(.7,-.6,0);
	//Change Position
	for(m=0;text1j[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, text1j[m]); 
	
	glRasterPos3f(.7,-1,0);
	//Change Position
	for(m=0;teacher2name[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, teacher2name[m]); 						
			
	glRasterPos3f(.7,-1.3,0);
	//Change Position
	for(m=0;text2j[m]!='\0';m++)
	glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, text2j[m]); 
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h)
{
 	glViewport(0,0,w,h);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	if (w <= h)
		glOrtho(-2.5, 2.5,-2.5*(GLfloat)h/(GLfloat)w,2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
 	else
	   	glOrtho(-2.5*(GLfloat)w/(GLfloat)h,2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
 	glMatrixMode(GL_MODELVIEW);
}

void bomb(){
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);			
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glColor3f(0.1,2,0.1);
	glPushMatrix();
	glTranslatef(0.0,0.7,0.0);	
	glRotatef(90,1.0,0.0,0.0);
	glColor3f(0.5,0.5,0.5);
	glutPostRedisplay();				
	draw_sphere(0.12);
	glPopMatrix();
}

void toppart(){
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);			
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glColor3f(0.7,0.2,0.2); 	//top part of missile
	glPushMatrix();
	glTranslatef(0.0,1.5,0.0);	
	glRotatef(90,1.0,0.0,0.0);
	glColor3f(0.5,0.5,0.5);
	glutPostRedisplay();				
	draw_cylinder(0,.18,1);
	glPopMatrix();
	
	glColor3f(0,0,0);		//wings
	glBegin(GL_POLYGON);
	glVertex3f(-.17,0.5,0.0);
	glVertex3f(-.35,0.4,0.0);
	glVertex3f(-.35,0.5,0.0);
	glVertex3f(-.12,0.8,0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(.17,0.5,0.0);
	glVertex3f(.35,0.4,0.0);
	glVertex3f(.35,0.5,0.0);
	glVertex3f(.12,0.8,0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0.5,0.17);
	glVertex3f(0,0.4,0.35);
	glVertex3f(0,0.5,0.35);
	glVertex3f(0,0.8,0.12);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0.5,-0.17);
	glVertex3f(0,0.4,-0.35);
	glVertex3f(0,0.5,-0.35);
	glVertex3f(0,0.8,-0.12);
	glEnd();
}

void downpart(){

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);			
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
		
	glColor3f(0.7,0.2,0.2);		//fueltank
	glPushMatrix();
	glTranslatef(0.0,0.5,0.0);	
	glRotatef(90,1.0,0.0,0.0);
	glColor3f(0.5,0.5,1);
	glutPostRedisplay();				
	draw_cylinder(.18,0.18,1.5);
	glPopMatrix();
	
	glColor3f(0.4,0.4,0.4);		//wings
	glBegin(GL_POLYGON);		
	glVertex3f(.17,-1.0,0.0);
	glVertex3f(.26,-1.2,0.0);
	glVertex3f(.40,-1.2,0.0);
	glVertex3f(.40,-0.9,0.0);
	glVertex3f(.17,-0.7,0.0);
	glEnd();
	
	glBegin(GL_POLYGON);		
	glVertex3f(-.17,-1.0,0.0);
	glVertex3f(-.26,-1.2,0.0);
	glVertex3f(-.40,-1.2,0.0);
	glVertex3f(-.40,-0.9,0.0);
	glVertex3f(-.17,-0.7,0.0);
	glEnd();
	
	glBegin(GL_POLYGON);		
	glVertex3f(0,-1.0,.17);
	glVertex3f(0,-1.2,.26);
	glVertex3f(0,-1.2,.40);
	glVertex3f(0,-0.9,.40);
	glVertex3f(0,-0.7,.17);
	glEnd();
	
	glBegin(GL_POLYGON);		
	glVertex3f(0,-1.0,-.17);
	glVertex3f(0,-1.2,-.26);
	glVertex3f(0,-1.2,-.40);
	glVertex3f(0,-0.9,-.40);
	glVertex3f(0,-0.7,-.17);
	glEnd();
}

void flames1(){
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient5);	//flames
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular5);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess5);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient5);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position5);
	
	glPushMatrix();
		glTranslatef(0.0,0.5,0.0);
		glRotatef(90,1.0,0.0,0.0);
		glColor3f(0.5,0.5,1);		
		draw_cylinder(.06,0.23,0.3);
	glPopMatrix();
}

void flames(){
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient5);	//flames
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular5);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess5);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient5);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position5);
	
	glPushMatrix();
		glTranslatef(0.0,-1.0,0.0);
		glRotatef(90,1.0,0.0,0.0);
		glColor3f(0.5,0.5,1);		
		draw_cylinder(.06,0.25,0.5);
	glPopMatrix();
}

void scene5back(){

	glClearColor(0.6,0.6,1,0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);			//sea		
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient2);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
	glBegin(GL_POLYGON);
	glVertex3f(-2.5,-2.5,2.5);
	glVertex3f(-2.5,-1.5,-2.5);
	glVertex3f(-.5,-1.5,-2.5);
	glVertex3f(-.3,-2.5,2.5);
	glEnd();
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);	//land			
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient1);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glBegin(GL_POLYGON);
	glVertex3f(-.3,-2.5,2.5);
	glVertex3f(-.5,-1.5,-2.5);
	glVertex3f(2.5,-1.5,-2.5);
	glVertex3f(2.5,-2.5,2.5);
	glEnd();
}

void building(){
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient3);	//building
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular3);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess3);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient3);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
	glPushMatrix();
	glScaled(1.2,3.2,0.8);
	glRotatef(8,1.0,-1.0,0.0);	                             
	glTranslatef(1.0,0.0,0.0);				
	draw_cube(1.0);
	glPopMatrix();
	
	glPointSize(40);	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient5);	//windows
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular5);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess5);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient5);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position5);
	glColor3f(1,0.7,0);
	glBegin(GL_POINTS);
	glVertex3f(0.8,1.2,0.8);
	glVertex3f(1.4,1.2,0.8);
	glVertex3f(0.8,0.6,0.8);
	glVertex3f(1.4,0.6,0.8);
	glVertex3f(0.8,0.0,0.8);
	glVertex3f(1.4,0.0,0.8);
	glVertex3f(0.8,-0.6,0.8);
	glVertex3f(1.4,-0.6,0.8);
	glVertex3f(0.8,-1.2,0.8);
	glVertex3f(1.4,-1.2,0.8);
	glEnd();
}

void sea(){
	glClearColor(0.6,0.6,1,0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);	//sea		
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient2);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
	
	glColor3f(0.9,0.4,0.2);
	glBegin(GL_POLYGON);
	glVertex3f(2.5,-2.5,2.5);
	glVertex3f(-2.5,-2.5,2.5);
	glVertex3f(-2.5,-0.7,-2.5);
	glVertex3f(2.5,-0.7,-2.5);
	glEnd();
}

void mountains(){
	glClearColor(0.6,0.6,1,0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient4);	//mountain	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular4);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess4);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient4);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position4);
	
        glBegin(GL_POLYGON);
        glVertex3f(-2.8,-2.5,-1.5);
        glVertex3f(-1.7,-1.2,-1.5);
        glVertex3f(-1.4,-0.2,-1.5);
        glVertex3f(-0.8,0.7,-1.5);
        glVertex3f(-0.7,1.2,-1.5);
        glVertex3f(0,0.5,-1.5);
        glVertex3f(0.3,-0.4,-1.5);
        glVertex3f(0.6,-1.2,-1.5);
        glVertex3f(1.0,-2.5,-1.5);
        glEnd();
        
        glBegin(GL_POLYGON);
        glVertex3f(0.0,-2.5,-2.0);
        glVertex3f(0.6,0.0,-2.0);
        glVertex3f(1.7,0.2,-2.0);
        glVertex3f(1.9,1.2,-2.0);
        glVertex3f(2.7,1.4,-2.0);
        glVertex3f(2.7,-2.5,-2.0);
        glEnd();
}

void setup(){
	glClearColor(0.6,0.6,1,0.0);
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);	//land			
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient1);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glColor3f(0.9,0.4,0.2);
	glBegin(GL_POLYGON);
	glVertex3f(2.5,-2.5,2.5);
	glVertex3f(-2.5,-2.5,2.5);
	glVertex3f(-2.5,-1.2,-2.5);
	glVertex3f(2.5,-1.2,-2.5);
	glEnd();
	
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);	//sea		
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient2);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
	glColor3f(0.9,0.4,0.2);
	glBegin(GL_POLYGON);
	glVertex3f(2.5,-1.2,-1.5);
	glVertex3f(-2.5,-1.2,-1.5);
	glVertex3f(-2.5,-0.7,-2.5);
	glVertex3f(2.5,-0.7,-2.5);
	glEnd();
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient3);	//stand	
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular3);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess3);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient3);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
	glPushMatrix();
	glScaled(1.4,1.8,0.8);
	glRotatef(8,1.0,-1.0,0.0);	                             
	glTranslatef(0.0,-1.0,0.0);				
	draw_cube(1.0);
	glPopMatrix();
}

void scene5(){
	x=0;
	while(x<1){
	scene5back();
	building();
	glPushMatrix();
		glRotatef(90,-1,0,-1);
		glTranslatef(-1.5+x,-3+(3*x),0);
		bomb();
		toppart();
		flames1();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
	x+=0.01;
	}
	r=0;
	while(r<5){
		scene5back();
		building();
		glPushMatrix();
		glTranslatef(1.0,0.0,0.8);
	
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient5);	//explode
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular5);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess5);
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient5);
		glLightfv(GL_LIGHT0, GL_POSITION, light_position5);
	
		draw_sphere(r);
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		r+=0.05;
	}
	glFlush();
	printlastpage();	
}

void scene4(){
	x=0;
	while(x<0.5){
		sea();
		if (flag1 == 1)
			flag1 = 0;
		else if(flag1 == 0)
			flag1= 1;
		glPushMatrix();
			glRotatef(90,-1,0,-1);
			glTranslatef(-2.5+x,0+(3*x),0);
			bomb();
			toppart();
			downpart();
			flames();
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		x+=0.01;
	}
	y=x;
	while(x<7){
		sea();
		if (flag1 == 1)
			flag1 = 0;
		else if(flag1 == 0)
			flag1 = 1;
		glPushMatrix();
			glRotatef(90,-1,0,-1);
			glTranslatef(-2.5+y,0+(3*y),0);
			bomb();
			toppart();
			flames1();
		glPopMatrix();
		glPushMatrix();
			glRotatef(90,-1,0,-1);
			glTranslatef(-2.5+x,0,0);
			downpart();
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		x+=0.05;
		y+=0.01;
	}
	scene5();
}

void scene3(){
	x=0;
        while(x<12){
		mountains();
		glPushMatrix();
		glRotatef(90,-1.5,-1.2,-0.4);
		glTranslatef(-2+x,-1.5+(0.07*x),.5);
		bomb();
		toppart();
		downpart();
		flames();
		glPopMatrix();
		glFlush();
		glutSwapBuffers();
		x+=0.05;
	}
	scene4();
}

void scene2(){
	while(x<5){
		setup();
		glPushMatrix();
		glTranslatef(0,x,0);
		bomb();
		toppart();
		downpart();
		flames();
		glPopMatrix();
		x+=.08;
		glFlush();
		glutSwapBuffers();
	}
	glFlush();
	glutSwapBuffers();
	scene3();
}

void scene1(){
		setup();
		glColor3f(1,0,0);
		glRasterPos3f(-2,2.1,0);
		for(m=0;rock[m]!='\0';m++)
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, rock[m]);	
		bomb();
		toppart();
		downpart();
		glFlush();
		glutSwapBuffers();
}

void display(void){
	if(flag == 1){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);//Clear screen
		printfirstpage();
		glFlush();
		glutSwapBuffers();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) 
	{
		case 13: if(flag==1){
				 flag=0;
				 scene1();
			}
			break;	 
		case 's' : scene2();
			break;
			
		case 'm' : printlastpage();
			break;
		case 27 :	
			exit(0);break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
 	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); 	
 	glutInitWindowSize(600,600);	
 	glutInitWindowPosition(0,0);
 	glutCreateWindow("Missile Launch");
 	init();
 	glutDisplayFunc(display);
 	glutReshapeFunc(reshape);
 	glutKeyboardFunc(keyboard);			
 	glutMainLoop();
}


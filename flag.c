#include<GL/glut.h>
#include <stdio.h>
void display();
void init();
void animate();
void mymenu(int id);
float c1[4][4][3] = {{{-8,5,0},{-2,5,0},{2,4,0},{8,4,0}},
                {{-8,6,0},{-2,6,0},{2,5,0},{8,5,0}},
                {{-8,7,0},{-2,7,0},{2,6,0},{8,6,0}},
                {{-8,8,0},{-2,8,0},{2,7,0},{8,7,0}}};
                
float c2[4][4][3] = {{{-8,2,0},{-2,2,0},{2,1,0},{8,1,0}},
                {{-8,3,0},{-2,3,0},{2,2,0},{8,2,0}},
                {{-8,4,0},{-2,4,0},{2,3,0},{8,3,0}},
                {{-8,5,0},{-2,5,0},{2,4,0},{8,4,0}}};
                
float c3[4][4][3] = {{{-8,-1,0},{-2,-1,0},{2,-2,0},{8,-2,0}},
                {{-8,0,0},{-2,0,0},{2,-1,0},{8,-1,0}},
                {{-8,1,0},{-2,1,0},{2,0,0},{8,0,0}},
                {{-8,2,0},{-2,2,0},{2,1,0},{8,1,0}}};
float a= 1;
float i;
void main(int argc, char **argv)
{
        glutInit(&argc,argv);
        glutCreateWindow("Flag");
        glutCreateMenu(mymenu);
        glutAddMenuEntry("ON",1);
        glutAddMenuEntry("OFF",2);
        glutAttachMenu(GLUT_LEFT_BUTTON);
        glutInitDisplayMode(GLUT_DEPTH);
        glEnable(GL_DEPTH_TEST);
        init();
        glutDisplayFunc(display);
        //glutIdleFunc(animate);
        glutMainLoop();
}

void init(){
        glMatrixMode(GL_PROJECTION);   
        glLoadIdentity();
        glOrtho(-20,20,-20,20,-20,20);
        glMatrixMode(GL_MODELVIEW);
        
        
}
void mymenu(int id){
        if(id == 1)
                glutIdleFunc(animate);
        if(id == 2)
                glutIdleFunc(0);
                
        glutPostRedisplay();       
}

void animate(){
        a=a+1;
        if(a>=90)
             a=0;
        glutPostRedisplay();   
        
}
void display(){
        glClearColor(0.114,0.123,0.175,0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        /*glBegin(GL_LINE_STRIP);
       
        for(i=0;i<100;i++){
                glEvalCoord1f(i/100);
        }*/
        glPushMatrix();
        glTranslatef(-8,-5,0);
        if(a>140)
                glRotatef(140-a,0,1,0);
        else
                glRotatef(a,0,1,0);
        glTranslatef(8,5,0);
        glColor3d(.8,.5,0);
        glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,3*4,4,&c1[0][0][0]);
        glEnable(GL_MAP2_VERTEX_3);
        glMapGrid2f(100,0,1,100,0,1);
        glEvalMesh2(GL_LINE,0,100,0,100);
        glEnd();
        
        glColor3d(1,1,1);
        glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,3*4,4,&c2[0][0][0]);
        glEnable(GL_MAP2_VERTEX_3);
        glMapGrid2f(100,0,1,100,0,1);
        glEvalMesh2(GL_LINE,0,100,0,100);
        glEnd();
        
         glColor3d(0,1,0);
        glMap2f(GL_MAP2_VERTEX_3,0,1,3,4,0,1,3*4,4,&c3[0][0][0]);
        glEnable(GL_MAP2_VERTEX_3);
        glMapGrid2f(100,0,1,100,0,1);
        glEvalMesh2(GL_LINE,0,100,0,100);
        glEnd();
        
        glPopMatrix();
        glColor3d(.8,.8,.8);
        glBegin(GL_POLYGON);
                glVertex3f(-8,9,0);
                glVertex3f(-9,9,0);
                glVertex3f(-9,-9,0);
                glVertex3f(-8,-9,0);
        glEnd();
        glFlush();
}



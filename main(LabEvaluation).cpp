#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

void square(float a,float b,float c,float d){
    glBegin(GL_QUADS);
    glVertex2f(a,b);
    glVertex2f(c,b);
    glVertex2f(c,d);
    glVertex2f(a,d);
    glEnd();
}
void tri(float a,float b,float c,float d,float e){
    glBegin(GL_TRIANGLES);
    glVertex2f(a,b);
    glVertex2f(c,b);
    glVertex2f(d,e);
    glEnd();
}
void circle(float a,float b,float d){
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(a, b, 0.0f);
    glPushMatrix();
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++){
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=d;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x,y);
    }
    glPopMatrix();
    glEnd();
}
void lshape(){
    glBegin(GL_POLYGON);
		glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
		glVertex2f(-0.15f, -0.3f);
		glVertex2f(0.25f, -0.3f);
		glVertex2f(0.25f, -0.2f);
		glVertex2f(0.0f, -0.2f);
		glVertex2f(0.0f, 0.2f);
		glVertex2f(-0.15f, 0.2f);
	glEnd();
}
void circleshape(){
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, 0.0f);
    glPushMatrix();
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    circle(0.4,-0.1,0.18);
    glEnd();
    glPopAttrib();
}
void barshape(){
    glColor4f(1.0f, 0.5f, 0.0f, 0.0f);
    square(-0.9,-0.5,0.9,-0.4);
}
void squareshape(){
    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    square(-0.4,-0.3,-0.25,0.2);
}
void triangleshape(){
    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    tri(-0.9,-0.4,0.9,0.0,0.8);
}


void display(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, 0.0f);
    glPushMatrix();

    barshape();

    triangleshape();

    squareshape();

    lshape();

    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, 0.0f);
    glPushMatrix();

    circleshape();

    glPopAttrib();
    glEnd();
    glFlush ();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize (1000, 1000);
    glutCreateWindow ("Lab Evaluation");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

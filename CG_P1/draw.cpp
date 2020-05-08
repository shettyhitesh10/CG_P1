#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;
int pntX1, pntY1, r;

int start_x = 0;
int start_y = 0;

int started = 0;//flag that sigifies the start of shading (used in mouse and myDisplay)


void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    // glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


int prev_x = 0;
int prev_y = 0;
int flag = 0;

void display(void)
{

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
    glVertex2i(prev_x, prev_y);
    glVertex2i(start_x, start_y);
    glEnd();
    prev_x = start_x;
    prev_y = start_y;
   
    //floodFill(200, 200, oldColor, newColor);
    glFlush();
}

void mouse_dynamic(int mousex, int mousey)
{

    start_x = mousex;
    start_y = 480 - mousey;

    if (flag == 0) {
        prev_x = start_x;
        prev_y = start_y;
        flag = 1;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DrawingBook Project");
    glutDisplayFunc(display);
    glutMotionFunc(mouse_dynamic);
    myInit();
    glutMainLoop();
    return 0;
}
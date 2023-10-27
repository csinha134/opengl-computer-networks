
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>

#include <OpenGl/glu.h>
#include<iostream>
#include<cmath>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>

//void midpointCircle(int xc, int yc, int radius)
//{
//    int x = radius, y = 0;
//    int radiusError = 1 - x;
//
//    while (x >= y)
//    {
//        glBegin(GL_POINTS);
//        glVertex2i(xc + x, yc + y);
//        glVertex2i(xc - x, yc + y);
//        glVertex2i(xc + x, yc - y);
//        glVertex2i(xc - x, yc - y);
//        glVertex2i(xc + y, yc + x);
//        glVertex2i(xc - y, yc + x);
//        glVertex2i(xc + y, yc - x);
//        glVertex2i(xc - y, yc - x);
//        glEnd();
//
//        y++;
//
//        if (radiusError < 0)
//        {
//            radiusError += 2 * y + 1;
//        }
//        else
//        {
//            x--;
//            radiusError += 2 * (y - x) + 1;
//        }
//    }
//}

void midPoint(int xc,int yc,int radius){
    int x=0,y=radius;
    int d=1-radius;
    while(x<y){
        glBegin(GL_POINTS);
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc+y,yc+x);
        glVertex2i(xc+x,yc-y);
        glVertex2i(xc+y,yc-x);
        glVertex2i(xc-x,yc-y);
        glVertex2i(xc-y,yc-x);
        glVertex2i(xc-x,yc+y);
        glVertex2i(xc-y,yc+x);
        glEnd();
        x++;
        if(d>=0){
            y=y-1;
            d=d+2*(x-y)+5;
        }
        else {
            d=d+2*x+3;
        }
    }
}

void bresenhamCircle(int xc, int yc, int radius)
{
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
        glEnd();

        x++;

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            y--;
            d = d + 4 * (x - y) + 10;
        }
    }
}

void rectangle()
{
//  glClear(GL_COLOR_BUFFER_BIT);
  
    glBegin(GL_LINE_LOOP);
    glVertex2f(400,10);
    glVertex2f(400,470);
    glVertex2f(100,470);
    glVertex2f(100,10);
    glEnd();
    glFlush();
    
}

void display()
{
    glPointSize(3.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    bresenhamCircle(250, 100, 40);
    glColor3f(1.0, 1.0, 0.0);
    bresenhamCircle(250, 250, 40);
    glColor3f(0.0, 1.0, 0.0);
    midPoint(250,400,40);
    glColor3f(0, 0, 0);
    rectangle();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


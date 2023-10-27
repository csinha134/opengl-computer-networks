//
//  main.cpp
//
//  Created by Chayan Sinha on 24/02/23.
//
#define GL_SILENCE_DEPRECATION
#include<OpenGL/glu.h>
#include<GLUT/GLUT.h>
#include<OpenGL/gl.h>
#include<iostream>
using namespace std;
#include<cmath>

void ddaLine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xinc = float(dx) / float(steps);
    float yinc = float(dy) / float(steps);
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(round(x), round(y));
        x += xinc;
        y += yinc;
    }
}

void bresenham(int x1,int x2 ,int y1,int y2){
    int dx=x2-x1;
    int dy=y2-y1;
    
    int p=2*dy-dx;
    int twody=2*dy;
    int twoMinusdx=2*(dy-dx);
    
    int x=x1,y=y1;
    glVertex2i(x,y);
    
    while(x<x2){
        
        if(p<0){
            p+=twody;
        }
        else{
            y++;
            p+=twoMinusdx;
        }
        x++;
        glVertex2i(x,y);
    }
}

void display()
{
    glPointSize(2.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    int x1 = 10, y1 = 20, x2 = 100, y2 = 120;
//    ddaLine(x1, y1, x2, y2);
    bresenham(x1 ,x2, y1, y2);
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA Line Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}









































































//void ddaLine(int x1, int y1, int x2, int y2)
//{
//    int dx = x2 - x1;
//    int dy = y2 - y1;
//
//    int steps = max(abs(dx), abs(dy));
//
//    float xinc = float(dx) / float(steps);
//    float yinc = float(dy) / float(steps);
//    float x = x1;
//    float y = y1;
//    for (int i = 0; i <= steps; i++)
//    {
//        glVertex2f(round(x), round(y));
//        x += xinc;
//        y += yinc;
//    }
//}
//
//void bresenham(int x1,int x2 ,int y1,int y2){
//    int dx=x2-x1;
//    int dy=y2-y1;
//
//    int p=2*dy-dx;
//    int twody=2*dy;
//    int twoMinusdx=2*(dy-dx);
//
//    int x=x1,y=y1;
//    glVertex2i(x,y);
//
//    while(x<x2){
//
//        if(p<0){
//            p+=twody;
//        }
//        else{
//            y++;
//            p+=twoMinusdx;
//        }
//        x++;
//        glVertex2i(x,y);
//    }
//}

//void midPoint(int xc,int yc,int radius){
//    int x=0,y=radius;
//    int d=1-radius;
//    while(x<y){
//        glBegin(GL_POINTS);
//        glVertex2i(xc+x,yc+y);
//        glVertex2i(xc+y,yc+x);
//        glVertex2i(xc+x,yc-y);
//        glVertex2i(xc+y,yc-x);
//        glVertex2i(xc-x,yc-y);
//        glVertex2i(xc-y,yc-x);
//        glVertex2i(xc-x,yc+y);
//        glVertex2i(xc-y,yc+x);
//        glEnd();
//        x++;
//        if(d>=0){
//            y=y-1;
//            d=d+2*(x-y)+5;
//        }
//        else {
//            d=d+2*x+3;
//        }
//    }
//}
//
//void bresenhamCircle(int xc, int yc, int radius)
//{
//    int x = 0, y = radius;
//    int d = 3 - 2 * radius;
//
//    while (x <= y)
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
//        x++;
//
//        if (d < 0)
//        {
//            d = d + 4 * x + 6;
//        }
//        else
//        {
//            y--;
//            d = d + 4 * (x - y) + 10;
//        }
//    }
//}

//void ellipseMidPoint(int xi,int yi,int rx,int ry) {
//    int x = 0, y = ry;
//    int p1 = (ry * ry) + (rx * rx * 0.25) - (ry * rx * rx);
//    int dx = 2 * x * (ry * ry);
//    int dy = 2 * y * (rx * rx);
//    while (dy > dx) {
//        glVertex2i(x + xi, y + yi);
//        glVertex2i(x + xi, -y + yi);
//        glVertex2i(-x + xi, -y + yi);
//        glVertex2i(-x + xi, y + yi);
//        if (p1 < 0) {
//            x++;
//            dx = 2 * x * (ry * ry);
//            p1 += dx + (ry * ry);
//        }
//        else {
//            x++;
//            y--;
//            dx = 2 * x * (ry * ry);
//            dy = 2 * y * (rx * rx);
//            p1 += dx + (ry * ry) - dy;
//        }
//    }
//    int p2 = (ry * ry * (x + 0.5) * (x + 0.5)) + (rx * rx * (y - 1) * (y - 1)) - (rx * rx * ry * ry);
//    while (y > 0) {
//        glVertex2i(x + xi, y + yi);
//        glVertex2i(x + xi, -y + yi);
//        glVertex2i(-x + xi, -y + yi);
//        glVertex2i(-x + xi, y + yi);
//        if (p2 > 0) {
//            y--;
//            dy = 2 * y * (rx * rx);
//            p2 += (rx * rx) - dy;
//        }
//        else {
//            y--;
//            x++;
//            dy -= 2 * (rx * rx);
//            dx += 2 * (ry * ry);
//            p2 += dx + (rx * rx) - dy;
//        }
//    }
//}


//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(100,100);
//    glutCreateWindow("DDA Line Algorithm");
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}
//void display()
//{
//    glPointSize(2.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(1, 0, 0);
//    glBegin(GL_POINTS);
//    int x1 = 10, y1 = 20, x2 = 100, y2 = 120;
////    ddaLine(x1, y1, x2, y2);
//    bresenham(x1 ,x2, y1, y2);
//    glEnd();
//    glFlush();
//}

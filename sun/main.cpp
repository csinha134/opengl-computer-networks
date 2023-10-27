//
//  main.cpp
//  sun
//
//  Created by Chayan Sinha on 23/02/23.
//

#define GL_SILENCE_DEPRECATION
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<GLUT/glut.h>
#include<iostream>
using namespace std;
#include<cmath>

void bresenham(int xc,int yc,int radius){
    int x=0, y=radius;
    glBegin(GL_LINES);
    glVertex2i(250,radius+250);
    glVertex2i(310,400);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(321,319);
    glVertex2i(310,400);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(321,319);
    glVertex2i(400,300);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(350,250);
    glVertex2i(400,300);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(350,250);
    glVertex2i(380,200);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(321,181);
    glVertex2i(380,200);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(321,181);
    glVertex2i(285,100);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(250,150);
    glVertex2i(285,100);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(250,150);
    glVertex2i(200,100);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(179,181);
    glVertex2i(200,100);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(179,181);
    glVertex2i(100,180);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(150,250);
    glVertex2i(100,180);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(150,250);
    glVertex2i(100,280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(179,319);
    glVertex2i(100,280);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(179,319);
    glVertex2i(200,400);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(250,350);
    glVertex2i(200,400);
    glEnd();
    

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
        cout<<250+x<<" "<<250+y<<endl;
    }
}

void display(){
    glPointSize(3.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    bresenham(250, 250, 100);
    glFlush();
}

int main(int argc,char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Circle Drawing Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

#include <OpenGL/gl.h>
#include <OpenGl/glu.h>

#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
//#include<bits/stdc++>

#define GL_SILENCE_DEPRECATION
void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glPointSize(12.0);
  glBegin(GL_QUADS);
    glVertex2f(100,10);
    glVertex2f(100,60);
    glVertex2f(150,60);
    glVertex2f(150,10);
    
  glEnd();
  glFlush();
}

void init()
{
  glClearColor(0,0,0,0);
  glColor3f(1.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0,200,0,150);
}
int main(int argc,char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Rectangle using QUADS");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}


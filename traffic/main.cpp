//
//  main.cpp
//  traffic
//
//  Created by Chayan Sinha on 23/02/23.
//
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

const int segments = 100; // number of segments to draw the circle

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   // Draw pole
   glColor3f(0.5f, 0.5f, 0.5f);
   glBegin(GL_POLYGON);
   glVertex2f(-0.05f, -1.0f);
   glVertex2f(0.05f, -1.0f);
   glVertex2f(0.05f, 1.0f);
   glVertex2f(-0.05f, 1.0f);
   glEnd();

   // Draw red light
   glColor3f(1.0f, 0.0f, 0.0f);
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(0.0f, 0.0f);
   for(int i = 0; i <= segments; i++) {
      glVertex2f(0.5f * cos(i * 2.0 * M_PI / segments), 0.5f * sin(i * 2.0 * M_PI / segments));
   }
   glEnd();

   // Draw yellow light
   glColor3f(1.0f, 1.0f, 0.0f);
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(0.0f, -0.6f);
   for(int i = 0; i <= segments; i++) {
      glVertex2f(0.5f * cos(i * 2.0 * M_PI / segments), -0.6f + 0.5f * sin(i * 2.0 * M_PI / segments));
   }
   glEnd();

   // Draw green light
   glColor3f(0.0f, 1.0f, 0.0f);
   glBegin(GL_TRIANGLE_FAN);
   glVertex2f(0.0f, -1.2f);
   for(int i = 0; i <= segments; i++) {
      glVertex2f(0.5f * cos(i * 2.0 * M_PI / segments), -1.2f + 0.5f * sin(i * 2.0 * M_PI / segments));
   }
   glEnd();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow("Circular Traffic Light");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}




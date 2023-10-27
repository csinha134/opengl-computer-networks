//
//  main.cpp
//  f2
//
//  Created by Chayan Sinha on 16/01/23.
//
//
//  demo.cpp
//  CG
//
//  Created by Chayan Sinha on 16/01/23.
//

//
//  main.cpp
//  CG
//
//  Created by Chayan Sinha on 16/01/23.
//

#include <OpenGL/gl.h>

#include <OpenGl/glu.h>

#include <GLUT/glut.h>

#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>




static float yPosition = 0;
static float zPosition = 0;
float topLeftX = 0.5;
float topLeftY = 0.75;
float topRightX = 0.75;
float topRightY = 0.75;
float bottomRightX = 0.75;
float bottomRightY = 0.5;
float bottomLeftX = 0.5;
float bottomLeftY = 0.5;
float xPos = 0.75;
float yPos = 0.75;
float zPos = 0;
float startXPos = 0.75;
float startYPos = 0.75;
int yDirection = 0; //1-up, 0-down
int xDirection = 0; //1-right, 0-left, 3- STOPPED


//the init function is used to initialize things that only need to be execute once
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glEnable(GL_DEPTH_TEST);
    //glShadeModel (GL_SMOOTH);
}

void setWindow(double left, double right, double bottom, double top)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

void setViewport(int left, int right, int bottom, int top)
{
    glViewport(left, bottom, right-left, top-bottom);
}

//function for drawing, called whenever there needs to be a redraw
void display(void)
{
    //color buffer gets cleared everytime a new frame is drawn
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setWindow(-9.0, 9.0, -1.0, 1.0);            // set the window
    
    glColor3f(1,0,0);

    glTranslated(xPos, yPos, zPos);
    glRotatef(yPosition, 0, 1, 0);
    glRotatef(zPosition, 0, 0, 1);

    glutWireCube(.25);

    
    glutSwapBuffers();
    
    if (xDirection==0){ //if moving left
        xPos-=0.0005;    //move in a negative direction along the xaxis
        yPos = (startYPos*xPos/startXPos);
    }
    else if (xDirection==1){
        xPos+=0.0005;    //otherwise move in the positive direction
        yPos = (startYPos*xPos/startXPos);
    }
    else if (xDirection==3){
        
        //ROTATE
        yPosition=yPosition+0.5;
        if (yPosition>180)
            xDirection==1;

        zPosition=zPosition+0.5;
        if (zPosition>180)
            xDirection==1;
        
    }
     
    
    if (xDirection==0 && xPos > 0.0) {
        xDirection=0;
    }
    
    if (xDirection==0 && xPos < 0.0) {
        xDirection=1;
    }
    
    if (xDirection==1 && xPos < startXPos) {
        xDirection=1;
    }
    
    if (xDirection==1 && xPos > startYPos) {
        xDirection=0;
    }
    
    if (xDirection==0 && xPos==0.0 && yPos==0.0) {
        xDirection=3;
    }
    
    glutPostRedisplay();
    
    
}
//called when window is resized, w and h are the new width and height
void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/ (GLfloat) h, 1.0, 20.0);
    glMatrixMode (GL_MODELVIEW);
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);  //double pixel buffer that holds RGB

    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0,0);
    
    glutCreateWindow(argv[0]);

    init();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //glutKeyboardFunc(keyboard);
    //glutIdleFunc(animate);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}


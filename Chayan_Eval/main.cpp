////  Chayan Sinha
////  created at 8:34am 24/02/2023
//
////For line - using bresenham algorithm
//
//
//#define GL_SILENCE_DEPRECATION
//#include<iostream>
//#include<OpenGL/gl.h>
//#include<OpenGL/glu.h>
//#include<GLUT/glut.h>
//#include<cmath>
//using namespace std;
//
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
//
//
//void display() {
//    //glClear(GL_COLOR_BUFFER_BIT); already mentioned in main program
//    glColor3f(1.0, 1.0,0.0);
//    glPointSize(2.0);
//    glBegin(GL_POINTS);
//    //int rx = 40, ry = 50, xi = 200, yi = 250;
//    ellipseMidPoint(180,250,30,100);
//    glEnd();
//    glColor3f(1.0,1.0,0.0);
//    glPointSize(2.0);
//    glBegin(GL_POINTS);
//    ellipseMidPoint(350, 250, 15, 50);
//    glEnd();
//    glColor3f(1.0,1.0,1.0);
//    glPointSize(2.0);
//    glBegin(GL_POINTS);
//    bresenham(180,350,150,200);
//    glEnd();
//    glColor3f(1.0,0.0,1.0);
//    glPointSize(2.0);
//    glBegin(GL_POINTS);
//    bresenham(350,180,300,350);
//    glEnd();
//    glColor3f(1.0,0.0,1.0);
//    glPointSize(2.0);
//    glBegin(GL_LINES);
//    glVertex2i(180,350);
//    glVertex2i(350, 300);
//    glEnd();
//    glColor3f(1.0, 1.0, 0);
//    glPointSize(3.0);
//    glBegin(GL_LINES);
//    glVertex2i(265,250);
//    glVertex2i(265,175);
//    glEnd();
//    glColor3f(1.0, 1.0, 0);
//    glPointSize(5.0);
//    glBegin(GL_LINES);
//    glVertex2i(265,250);
//    glVertex2i(265,325);
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Frustum");
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glClear(GL_COLOR_BUFFER_BIT);
//    gluOrtho2D(0, 500, 0, 500);
//    glMatrixMode(GL_PROJECTION);
//    glViewport(0, 0, 500, 500);
//    glutDisplayFunc(display);
//    glutMainLoop();
//    return 0;
//}


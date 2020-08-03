//
//  main.cpp
//  helloGL
//
//  Created by Remi Higuchi on 2020/05/12.
//  MY FIRST OPENGL CODE
//  Copyright © 2020 Remi Higuchi. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#include <math.h>
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

void display(){
    glClearColor(0,0,0, 1.0);   // background color
    glClear(GL_COLOR_BUFFER_BIT);       // setup background color
    
    
    glBegin(GL_POLYGON);
    glColor3f(00, 1.0, 0.8);
    glVertex2f(0, 0);
    glVertex2f(0, -0.4);
    glVertex2f(-0.4, -0.4);
    glVertex2f(-0.4, 0);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.6, 1.0, 0.8);
    glVertex2f(0, 0);
    glVertex2f(-0.4, 0);
    glVertex2f(-0.2, 0.2);
    glVertex2f(0.2, 0.2);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.1, 0.9, 0.8);
    glVertex2f(0, 0);
    glVertex2f(0, -0.4);
    glVertex2f(0.2, -0.2);
    glVertex2f(0.2, 0.2);
    glEnd();
    
    
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);              //initiralize glut
    glutInitDisplayMode(GLUT_SINGLE);   //single buffer
    glutInitWindowSize(500, 500);       //set window width and height
    glutCreateWindow("OpenGL01");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

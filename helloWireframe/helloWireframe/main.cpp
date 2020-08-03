//
//  main.cpp
//  helloWireframe
//
//  Created by Remi Higuchi on 2020/05/22.
//  Copyright © 2020 Remi Higuchi. All rights reserved.
//
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)width/height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
}

void display(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0 ,1.0, 1.0);
    glutWireTeapot(1.0);
    glFlush();
}

int main(int argc, char * argv[]) {
    
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("HelloWireframe");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}

//
//  main.cpp
//  affine
//
//  Created by Remi Higuchi on 2020/05/29.
//  Copyright © 2020 Remi Higuchi. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

void setup(){
    float lightPosition[4] = {5.25, 2.0, 0.25, 1.0};
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    float ambient[4] = {0.3, 0.5, 0.0, 1.0};
    float diffuse[4] = {1.0, 1.0, 0.3, 1.0};
    float specular[4] = {1.0, 1.0, 1.0, 1.0};
    float shininess[1] = {20.0f};glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width/height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);glLoadIdentity();
    gluLookAt(0.0, 3.0, 13.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
}

void display(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //1
    glutSolidTeapot(1);
    //2
    glPushMatrix();
        glTranslatef(3,0,0);
        glutSolidTeapot(1);
    glPopMatrix();
    //3
    glPushMatrix();
        glRotatef(135.0, 0.0,1.0,0.0);
        glTranslatef(3,0,0);
        glutSolidTeapot(1);
    glPopMatrix();
    
    glFlush();
}



int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("affine transformation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    setup();
    glutMainLoop();
    return 0;
}


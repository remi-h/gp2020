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

float lightposition[4] = {4.25, 2.0, 3.25, 1.0};
float teapotAmbient[4] = {0.3, 0.5, 0.0, 1.0};
float teapotDiffuse[4] = {1.0, 1.0, 0.3, 1.0};
float teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0};
float teapotShininess[1] = {20.0};

float lightposition2[4] = {2.25, 1.0, 0.25, 1.0};
float teapotAmbient2[4] = {0.3, 0.5, 0.0, 1.0};
float teapotDiffuse2[4] = {1.0, 1.0, 0.3, 1.0};
float teapotSpecular2[4] = {1.0, 0.0, 1.0, 1.0};
float teapotShininess2[1] = {5.0};

float lightposition3[4] = {2.25, 4.0, 2.25, 1.0};
float teapotAmbient3[4] = {0.3, 0.5, 0.0, 1.0};
float teapotDiffuse3[4] = {0.2, 1.0, 0.3, 1.0};
float teapotSpecular3[4] = {1.0, 0.0, 1.0, 1.0};
float teapotShininess3[1] = {5.0};


void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, (double)width/height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(4.0, 3.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glutSolidDodecahedron();
    //glutSolidSphere(1.0, 64, 64);
    //glutSolidTeapot(1.0);
    //glColor3f(1.0 ,1.0, 1.0);
    //glutWireTeapot(1.0);
    glutSolidDodecahedron();
    glFlush();
}

void setup(){
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHTING);
    
    //GL_LIGHT0
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess);
    
    //GL_LIGHT1
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightposition2);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular2);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess2);
    
    //GL_LIGHT2
    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_POSITION, lightposition3);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient3);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse3);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular3);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess3);
}

int main(int argc, char * argv[]) {
    
    glutInit(&argc,argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("HelloWireframe");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    
    setup();
    
    glutMainLoop();
    
    return 0;
}

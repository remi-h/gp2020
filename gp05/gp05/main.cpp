//
//  main.cpp
//  kadai04
//
//  Created by Remi Higuchi on 2020/06/07.
//  Copyright © 2020 Remi Higuchi. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

float rotation = 0.0;

void reshape(int width, int height){
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width/height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 13.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
}

void setup(){
    float lightPosition[4] = {5.25, 2.0, 0.25, 1.0};
    float ambient[4] = {0.3, 0.5, 0.0, 1.0};
    float diffuse[4] = {1.0, 1.0, 0.3, 1.0};
    float specular[4] = {1.0, 1.0, 1.0, 1.0};
    float shininess[1] = {20.0};
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void display(void){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int x = 7;
    int y = 7;
    int z = 7;
    
    glPushMatrix();
    glRotatef(rotation, 0,1,0);
    glTranslatef(-float(x-1)/2.0, -float(y-1)/2.0, -float(z-1)/2.0);
    
    for(int k=0; k<z; k++){
        for(int j=0; j<y; j++){
            for(int i=0; i<x; i++){
                glPushMatrix();
                glTranslatef(i, j, k);
                glRotatef(rotation, 0,1,0);
                glutSolidCube(0.5);
                glPopMatrix();
            }
        }
    }
    
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void idle(){
    rotation += 1.0;
    glutPostRedisplay();
    
    if(rotation > 360){
        rotation = 0;
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("forCube");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    setup();
    glutMainLoop();
    return 0;
}

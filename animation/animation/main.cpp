//
//  main.cpp
//  animation
//
//  Created by Remi Higuchi on 2020/05/29.
//  Copyright © 2020 Remi Higuchi. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

float rotation = 0.0;
float translation = 0.0;

void setup(){
    float lightPosition[4] = {5.25, 2.0, 0.25, 1.0};
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    float ambient[4] = {0.3, 0.5, 0.0, 1.0};
    float diffuse[4] = {1.0, 1.0, 0.3, 1.0};
    float specular[4] = {1.0, 1.0, 1.0, 1.0};
    float shininess[1] = {20.0f};
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
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

void idle(void){
    rotation += 3;
    if(rotation >= 360) rotation = 0;
    
    translation += 0.1;
   
    glutPostRedisplay();
}

void display(){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef(rotation, 1.0, 0, 0);
    glTranslatef(translation, 0.0, 0.0);
    glutSolidTorus(1.0, 2.0, 80, 80);
    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        glutIdleFunc(idle);
    }
    else{
        glutIdleFunc(0);
    }
}
    
void key(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
            exit(0);
            break;
        case 'c':
            rotation = 0;
            translation = 0;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutCreateWindow("hello animation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    
    setup();
    
    glutMainLoop();
    return 0;
}

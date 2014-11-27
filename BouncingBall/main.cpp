#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "glut.h"


void SetupLights()
{
    GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
    GLfloat mat_diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
    GLfloat mat_shininess[] = { 50 };
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    //set the light source properties
    GLfloat lightIntensity[] = { 0.7f, 0.7f, 1, 1.0f };
    GLfloat light_position[] = { -7.0f, 6.0f, 3.0f, 0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
}




void displayWire(void){
    // Setup light
    //SetupLights();
    //set the camera
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    gluPerspective(60, 800 / 600, 0.001, 100);
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();
    gluLookAt(2, 3, 5, 0, 0, 0, 0.0, 1.0, 0.0); //start drawing
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    
    //Cube2
    glPushMatrix();
    glScaled(1, 1, 2);
    glColor3f(0.0, 0.0, 0.0);
    glTranslated(0.0, 0, 1.0);
    glutSolidCube(1);
    glPopMatrix();
    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(1.0, 0.0, 0.0);
//    glTranslated(5.0, -1.0, 1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.0, 0.0, 1.0);
//    glTranslated(5.0, -2.0, 1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(1.0, 0.0, 0.0);
//    glTranslated(5.0, -3, 1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2//////////////
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.3, 1, 0.7);
//    glTranslated(5.0, 0, 2.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.7, 0, 0.3);
//    glTranslated(5.0, -1.0, 2.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.3, 1, 0.7);
//    glTranslated(5.0, -2.0, 2.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.7, 0, 0.3);
//    glTranslated(5.0, -3, 2.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    /////
//    
//    //Cube2
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0, 0, 0);
//    glTranslated(5.0, 0, 3.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.7, 0.7, 0.7);
//    glTranslated(5.0, -1.0, 3.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0, 0, 0);
//    glTranslated(5.0, -2.0, 3.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.7, 0.7, 0.7);
//    glTranslated(5.0, -3, 3.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2//////////////
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.6, 0.1, 0.3);
//    glTranslated(5.0, 0, 4.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.5, 0.5, 0.5);
//    glTranslated(5.0, -1.0, 4.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.6, 0.1, 0.3);
//    glTranslated(5.0, -2.0, 4.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2
//    glPushMatrix();
//    glScaled(1, 1, 2);
//    glColor3f(0.5, 0.5, 0.5);
//    glTranslated(5.0, -3, 4.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    
//    
//    
//    ///////////////////////////////////////////////
//    
//    //Cube2
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 1.0);
//    glTranslated(-5.0, 0, -1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glColor3f(1.0, 0.0, 0.0);
//    glTranslated(-5.0, -1.0, -1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube1
//    glPushMatrix();
//    glColor3f(0.0, 0.0, 1.0);
//    glTranslated(-5.0, -2.0, -1.0);
//    glutSolidCube(1);
//    glPopMatrix();
//    
//    //Cube2
//    glPushMatrix();
//    glColor3f(1.0, 0.0, 0.0);
//    glTranslated(-5.0, -3, -1.0);
//    glutSolidCube(1);
//    glPopMatrix();
    
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Bouncing Ball");
    glutDisplayFunc(displayWire);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_NORMALIZE);
    glClearColor(1.0,1.0,1.0,0.0);
    glutMainLoop();
    return 0;
}

















#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "glut.h"

int rightXOffset = 5;
double colorsArray[7][4];
double zLookAt = 110;
double gameColors[4000][4];
int startIndex = 0;
double sphereTranslateX = 0;
double sphereTranslateY = 0;
double sphereTranslateZ = 70;


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
    //glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(60, 800 / 600, 0.001, 10000);
    gluLookAt(0, 0, zLookAt, 0, 0, 0, 0.0, 1.0, 0.0); //start drawing
    
    
    for (int i = -1; i < 10 ; i++) {
        for (int j=-3; j<1; j++) {
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(10.0, j, i);
            glutSolidCube(1);
            glPopMatrix();
        }

    }
    
    for (int i = 0; i < 40 ; i++) { //LEFT WALL
        for (int j=-10; j<10; j++) {
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(-10.0, j, i);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }
    
    for (int i = 0; i < 40 ; i++) { //TOP WALL
        for (int j=-10; j<10; j++) {
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(j, 10, i);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }
    
    for (int i = 0; i < 40 ; i++) { //BOTTOM WALL
        for (int j=-10; j<10; j++) {
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(j, -10, i);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }
    
    for (int i = -20; i < 20 ; i++) { //FRONT WALL
        for (int j=-10; j<10; j++) {
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(j, i , 0);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }
    


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
//    
//    int r = 0 ;
//   
//    for (int j=0; j>-4; j--) {
//        for (int i =10; i>-2; i--) {
//            glPushMatrix();
//            if (r) {
//                glColor3f(r, 0, 0);
//                r=0;
//            }else{
//                glColor3f(0,r,0);
//                r=1;
//            }
//            glTranslated(-5.0, j, i);
//            glutSolidCube(1);
//            glPopMatrix();
//        }
//        r=(r==0)?1:0;
//    }
//    
//    for (int i =5; i>-5; i--) {
//        for (int j=0; j>-4; j--) {
//            glPushMatrix();
//            if (r) {
//                glColor3f(r, 0, 0);
//                r=0;
//            }else{
//                glColor3f(0,r,0);
//                r=1;
//            }
//            glTranslated(i , j, -2);
//            glutSolidCube(1);
//            glPopMatrix();
//        }
//        r=(r==0)?1:0;
//    }
    
    
    
    
    
    glutSwapBuffers();
    //glFlush();
}

void animate(int x)
{
    zLookAt += 1;
    glutPostRedisplay();
    
}

void animateIdle()
{
    if (zLookAt > 0.05) {
        zLookAt -= 0.05;
        sphereTranslateX -=0.0005;
        sphereTranslateY -=0.0;
        sphereTranslateZ -=0.05;
    }
    
    startIndex = 0;
    glutPostRedisplay();
    
}

int main(int argc, char** argv)
{
    for (int i = 0; i < 7 ; i++) {
        switch (i) {
            case 0: //Red
                colorsArray[i][0] = 1.0;
                colorsArray[i][1] = 0.0;
                colorsArray[i][2] = 0.0;
                colorsArray[i][3] = 10.0;
                break;
                
            case 1: //Orange
                colorsArray[i][0] = 1.0;
                colorsArray[i][1] = 0.55;
                colorsArray[i][2] = 0.0;
                colorsArray[i][3] = 20.0;
                break;
                
            case 2: //Yellow
                colorsArray[i][0] = 1.0;
                colorsArray[i][1] = 1.0;
                colorsArray[i][2] = 0.0;
                colorsArray[i][3] = 30.0;
                break;
                
            case 3: //Lime
                colorsArray[i][0] = 0.0;
                colorsArray[i][1] = 1.0;
                colorsArray[i][2] = 0.0;
                colorsArray[i][3] = 40.0;
                break;
                
            case 4: //Dodger Blue
                colorsArray[i][0] = 0.12;
                colorsArray[i][1] = 0.56;
                colorsArray[i][2] = 1.0;
                colorsArray[i][3] = 50.0;
                break;
                
            case 5: //Purple
                colorsArray[i][0] = 0.5;
                colorsArray[i][1] = 0.0;
                colorsArray[i][2] = 0.5;
                colorsArray[i][3] = -10.0;
                break;
                
            case 6: //Slate Gray
                colorsArray[i][0] = 0.43;
                colorsArray[i][1] = 0.5;
                colorsArray[i][2] = 0.56;
                colorsArray[i][3] = -20.0;
                break;
                
            default:
                break;
        }

    }
    
    for (int i = 0; i < 4000; i++) {
        int x = rand()%7;
        gameColors[i][0] = colorsArray[x][0];
        gameColors[i][1] = colorsArray[x][1];
        gameColors[i][2] = colorsArray[x][2];
        gameColors[i][3] = colorsArray[x][3];
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300, 150);
    glutCreateWindow("Bouncing Ball");
    glutDisplayFunc(displayWire);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glutIdleFunc(animateIdle);
 //   glutTimerFunc(0.001, animate, 1);
    glClearColor(1.0,1.0,1.0,0.0);
    glutMainLoop();
    return 0;
}

















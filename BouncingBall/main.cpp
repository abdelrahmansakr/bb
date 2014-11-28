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
double sphereTranslateX = 2;
double sphereTranslateY = 1;
double sphereTranslateZ = 97;
int decrementX = 1;
int decrementY = 1;
int decrementZ = 1;
int sphereColor=1;
double rightWall[40][20];
double leftWall[40][20];
double topWall[40][20];
double bottomWall[40][20];

int rightWallIndex[40][20];
int leftWallIndex[40][20];
int topWallIndex[40][20];
int bottomWallIndex[40][20];

double score=0;
int keyPress =0;
int leftPress=0;
int rightPress=0;
int upPress=0;
int downPress=0;
bool start=false;
int color=0;
int indexToBeRemoved = 0;

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

void print(int x, int y, int z, char *string, float r, float g , float b, int font)
{
    glColor3f(r, g, b);
	int len, i;
	glRasterPos3d(x, y, z);
	len = (int) strlen(string);
	for (i = 0; i < len; i++)
	{
        if(font == 0){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
        }
        else if (font == 1){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,string[i]);
        }
        else if (font == 2){
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string[i]);
        }
	}
}

void print3d(int x, int y, char *string)

{
    
    //Assume we are in MODEL_VIEW already
    
	glPushMatrix ();
    
	glLoadIdentity ();
    
	glMatrixMode(GL_PROJECTION);
    
	glPushMatrix ();
    
	glLoadIdentity();
    
    
    
	GLint viewport [4];
    
	glGetIntegerv (GL_VIEWPORT, viewport);
    
	gluOrtho2D (0,viewport[2], viewport[3], 0);
    
	
    
	glDepthFunc (GL_ALWAYS);
    
	glColor3f (0,0,0);
    
	glRasterPos3f(x, y, 110);
    
    int len, i;
    len = (int) strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
    
	glDepthFunc (GL_LESS);
    
	glPopMatrix ();
    
	glMatrixMode(GL_MODELVIEW);
    
	glPopMatrix ();
    
}




void displayWire(void){
    
    // Setup light
    //SetupLights();
    //set the camera
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    char * scoreString[50];
    sprintf((char *)scoreString,"SCORE = %f",score);
   // print(-10,10,110,(char *)scoreString,0.2,0.6,0.97,0);
    print3d(-10, 10, (char *)scoreString);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluPerspective(60, 800 / 600, 0.001, 10000);
    gluLookAt(0, 0, zLookAt, 0, 0, 0, 0.0, 1.0, 0.0); //start drawing

    
    glPushMatrix();
    glColor3f(sphereColor, sphereColor, sphereColor);
    glTranslated(sphereTranslateX, sphereTranslateY, sphereTranslateZ);
    glutSolidSphere(0.15, 50, 50);
    glPopMatrix();
    
    for (int i = 0; i < 40 ; i++) { //RIGHT WALL ZY
        for (int j=-10; j<10; j++) {
            rightWall[i][j+10]=gameColors[startIndex][3];
            rightWallIndex[i][j+10] = startIndex;
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(10.0, j, i);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }

    for (int i = 0; i < 40 ; i++) { //LEFT WALL ZY
        for (int j=-10; j<10; j++) {
            leftWall[i][j+10]=gameColors[startIndex][3];
            leftWallIndex[i][j+10] = startIndex;
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(-10.0, j, i);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }

    for (int i = 0; i < 40 ; i++) { //TOP WALL ZX
        for (int j=-10; j<10; j++) {
            topWall[i][j+10]=gameColors[startIndex][3];
            topWallIndex[i][j+10] = startIndex;
            glPushMatrix();
            glScaled(1, 1, 2);
            glColor3f(gameColors[startIndex][0], gameColors[startIndex][1], gameColors[startIndex][2]);
            startIndex++;
            glTranslated(j, 10, i);
            glutSolidCube(1);
            glPopMatrix();
        }
        
    }

    for (int i = 0; i < 40 ; i++) { //BOTTOM WALL ZX
        for (int j=-10; j<10; j++) {
            bottomWall[i][j+10]=gameColors[startIndex][3];
            bottomWallIndex[i][j+10] = startIndex;
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
    if (start) {
        if (zLookAt > 20) {
            if(sphereTranslateX >= 4){
                score+=rightWall[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY];
                gameColors[rightWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+12]][0] = 1.0;
                gameColors[rightWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+12]][1] = 1.0;
                gameColors[rightWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+12]][2] = 1.0;
                gameColors[rightWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+12]][3] = 0.0;
                sphereColor=0;
                color=10;
            }else
                if(sphereTranslateX <= -4){
                    score+=leftWall[(int)sphereTranslateY][(int)sphereTranslateZ];
                    
                    gameColors[leftWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][0] = 1.0;
                    gameColors[leftWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][1] = 1.0;
                    gameColors[leftWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][2] = 1.0;
                    gameColors[leftWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][3] = 0.0;
                    
                    sphereColor=0;
                    color=10;
                }else
                    if(sphereTranslateY >= 4){
                        score+=topWall[(int)sphereTranslateZ][(int)sphereTranslateY];
                        
                        gameColors[topWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateX+13]][0] = 1.0;
                        gameColors[topWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateX+13]][1] = 1.0;
                        gameColors[topWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateX+13]][2] = 1.0;
                        gameColors[topWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateX+13]][3] = 0.0;
                        
                        sphereColor=0;
                        color=10;
                    }else
                        if(sphereTranslateY <= -4){
                            score+=bottomWall[(int)sphereTranslateY][(int)sphereTranslateZ];
                            
                            gameColors[bottomWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][0] = 1.0;
                            gameColors[bottomWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][1] = 1.0;
                            gameColors[bottomWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][2] = 1.0;
                            gameColors[bottomWallIndex[(int)(sphereTranslateZ/2.425)][(int)sphereTranslateY+8]][3] = 0.0;
                            
                            sphereColor=0;
                            color=10;
                        }else{
                            if(color <0){
                                sphereColor=1;
                                color--;
                            }
                            
                        }
            
            if (decrementX == 1) {
                sphereTranslateX -=0.05;
                if (sphereTranslateX <= -4) {
                    decrementX = 0;
                }
            } else if (decrementX == 0) {
                sphereTranslateX +=0.05;
                if (sphereTranslateX >= 4) {
                    decrementX = 1;
                }
            }
            
            if (decrementY == 1) {
                sphereTranslateY -=0.05;
                if (sphereTranslateY <= -4) {
                    decrementY = 0;
                }
            } else if (decrementY == 0) {
                sphereTranslateY +=0.05;
                if (sphereTranslateY >= 4) {
                    decrementY = 1;
                }
            }
            zLookAt -= 0.05;
            sphereTranslateZ -=0.05;
        }
    }
    sphereColor=1;
    double u;
    srand( unsigned(time(NULL) ));
    u=(double)rand()/(RAND_MAX+1)*(0.2-0.1)+0.1;
    
    
    if (rightPress>0) {
        if (sphereTranslateX+0.05 <= 4) {
            sphereTranslateX+=0.05;
            rightPress--;
        }
    }
    if (leftPress>0) {
        if (sphereTranslateX-0.05 >= -4) {
            sphereTranslateX-=0.05;
            leftPress--;
        }
    }
    if (upPress>0) {
        if (sphereTranslateY+0.05 <= 4) {
            sphereTranslateY+=0.05;
            upPress--;
        }
    }
    if (downPress>0) {
        if (sphereTranslateY-0.05 >= -4) {
            sphereTranslateY-=0.05;
            downPress--;
        }
    }
    startIndex = 0;
    glutPostRedisplay();
    
}
void keyPressed (unsigned char key, int x, int y) {
    if (key==' '){  // If the 'spacebar' key has been pressed
        start = !start;
    }
    
}
void keySpecial (int key, int x, int y) {
    if(key==GLUT_KEY_LEFT){
        leftPress=10;
    }
    else
        if (key==GLUT_KEY_RIGHT) {
            rightPress=10;
        }else
            if (key==GLUT_KEY_UP) {
                upPress=10;
            }else
                if (GLUT_KEY_DOWN) {
                    downPress=10;
                }
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
    glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses
    glutSpecialFunc(keySpecial);
    glutMainLoop();
    return 0;
}



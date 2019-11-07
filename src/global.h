#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm.h"


int keyboard[256];

enum Camera{ONE, TWO, THREE};
enum Camera currentCamera;

enum Screen{MENU, PLAYING};
enum Screen currentScreen;

enum Button{START, EXIT};
enum Button currentButton;

int currentRide;
int currentTopCamera;
int lightingswitch;


float ytowerfallcabins;
int falling;
int goingup;
int waitingup;
int waitingdown;
int towerfalltimer;


float red, green, blue;
int lighttimer;


int xMouse, yMouse;        //variáveis globais que serão usadas na função posicionaCamera
float xCursor, yCursor, zCursor;//guarda o centro do cursor
float phi, teta;       //ângulos das coordenadas esféricas
double xChange; double yChange; //variáveis que guardam o vetor 2D de movimento do mouse na tela


typedef struct{
    GLfloat x,y,z;
}vetor3d;

vetor3d camera;

char orthoperspective;

GLMmodel* tronland;
GLMmodel* ferriswheelBase;
GLMmodel* wheel;
GLMmodel* towerFall;
GLMmodel* towerFallCabins;
GLMmodel* carouselStructure;
GLMmodel* carouselMoto1;
GLMmodel* carouselMoto2;
GLMmodel* globeOfDeath;
GLMmodel* globeOfDeathMoto;

GLuint idMenu;
GLuint idStart;
GLuint idSelectedStart;
GLuint idExit;
GLuint idSelectedExit;

float degreeFW;
float degreeCarousel;
float degreeGlobeOfDeath;
float yCMoto1;
float yCMoto2;
int carouselTimer;

#endif